#include <types.h>
#include <kern/errno.h>
#include <kern/unistd.h>
#include <lib.h>
#include <filetable.h>
#include <../arch/mips/include/spl.h>
#include <addrspace.h>
#include <curthread.h>
#include <thread.h>
#include <uio.h>
#include <vfs.h>
#include <vnode.h>
#include <vm.h>

int sys_read(int *retval, int index, void *buf, size_t nbytes) {

    //Get the file descriptor from the opened list of file descriptors that the current thread has, based on the index given.
    struct filedescriptor* fd = ft_get(curthread->ft, index);
    if (fd == NULL) {
        return EBADF;
    }

    switch (O_ACCMODE & fd->mode) {
        case O_RDONLY:
        case O_RDWR:
            break;
        default:
            return EBADF;
    }
    struct uio u;
    mk_kuio(&u, (void *) buf, nbytes, fd->offset, UIO_READ);
    int spl;
    spl = splhigh();
    int sizeread = VOP_READ(fd->fdvnode, &u);
    splx(spl);
    if (sizeread) {
        return sizeread;
    }
    sizeread = u.uio_resid;
    *retval = sizeread;
    fd->offset += sizeread;
    return 0;
}

