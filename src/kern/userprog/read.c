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
    //Make sure that the file is opened for writing.
    switch (O_ACCMODE & fd->mode) {
        case O_RDONLY:
        case O_RDWR:
            break;
        default:
            return EBADF;
    }
    //Make the uio
    struct uio u;
    mk_kuio(&u, (void *) buf, nbytes, fd->offset, UIO_READ);
    //Disable interrupt
    //int spl;
    //spl = splhigh();
    //Read
    int sizeread = VOP_READ(fd->fdvnode, &u);
    //splx(spl);
    if (sizeread) {
        return sizeread;
    }
    //Find the number of bytes read
    sizeread = nbytes - u.uio_resid;
    *retval = sizeread;
    //Update the offset
    fd->offset += sizeread;
    return 0;
}

