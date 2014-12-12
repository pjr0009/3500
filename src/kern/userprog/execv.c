#include <types.h>
#include <kern/unistd.h>
#include <kern/errno.h>
#include <lib.h>
#include <addrspace.h>
#include <thread.h>
#include <curthread.h>
#include <vm.h>
#include <vfs.h>

int
sys_execv()
{
	struct vnode *v;
	vaddr_t entrypoint, stackptr;
	int result;

	result = vfs_open(progname, O_RDONLY, &v);
	if (result) {
		return result;
	}

	assert(curthread->t_vmspace == NULL);

	curthread->t_vmspace = as_create();
	if (curthread->t_vmspace==NULL) {
		vfs_close(v);
		return ENOMEM;
	}

	as_activate(curthread->t_vmspace);

	result = load_elf(v, &entrypoint);
	if (result) {
		vfs_close(v);
		return result;
	}

	vfs_close(v);

	result = as_define_stack(curthread->t_vmspace, &stackptr);
	if (result) {
		return result;
	}

	md_usermode(0 /*argc*/, NULL /*userspace addr of argv*/,
		    stackptr, entrypoint);
	
	panic("md_usermode returned\n");
	return EINVAL;
}

