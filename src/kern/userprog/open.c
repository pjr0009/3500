#include <types.h>
#include <kern/errno.h>
#include <kern/unistd.h>
#include <kern/stat.h>
#include <lib.h>
#include <addrspace.h>
#include <filetable.h>
#include <../arch/mips/include/spl.h>
#include <curthread.h>
#include <thread.h>
#include <uio.h>
#include <vfs.h>
#include <vnode.h>

int sys_open(int *retval, const char *path, int oflag, int mode){
    struct filedescriptor *new_fd = NULL;
    new_fd = (struct filedescriptor *) kmalloc(sizeof ( struct filedescriptor));
    new_fd -> fdvnode = kmalloc(sizeof (struct vnode));
	char *kpath = kstrdup(path);

	int result = vfs_open(kpath, oflag, &new_fd->fdvnode);
    if (result) {
        return result;
    }

	new_fd->offset = 0;
    new_fd->mode = mode;
    result = ft_add(curthread->ft, new_fd);
    kprintf("file desciptor: %d", result);
    *retval = result;
    return 0;
}
