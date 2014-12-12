#include <types.h>
#include <kern/errno.h>
#include <kern/unistd.h>
#include <lib.h>
#include <filetable.h>
#include <../arch/mips/include/spl.h>
#include <addrspace.h>
#include <filetable.h>
#include <thread.h>
#include <uio.h>
#include <vfs.h>
#include <vnode.h>
#include <vm.h>
#include <synch.h>
#include <curthread.h>
struct lock *writelock;

int sys_write(int *retval, int index, void *buf, size_t nbytes) {
    if (writelock == NULL) {
        writelock = lock_create("WriteLock");
        if (writelock == NULL) {
            return ENOMEM;
        }
    }
    struct filedescriptor* fd = ft_get(curthread->ft, index);
    if (fd == NULL) {
        return EBADF;
    }
    switch (O_ACCMODE & fd->mode) {
        case O_WRONLY:
        case O_RDWR:
            break;
        default:
            return EBADF;
    }
    struct uio u;
    mk_kuio(&u, (void *) buf, nbytes, fd->offset, UIO_WRITE);
    int spl = splhigh();
    int sizewrite = VOP_WRITE(fd->fdvnode, &u);
    splx(spl);

    if (sizewrite) {
        return sizewrite;
    }
    sizewrite = nbytes - u.uio_resid;
    *retval = sizewrite;
    fd->offset += sizewrite;
    return 0;
}
