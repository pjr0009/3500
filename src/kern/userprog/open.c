#include <types.h>
#include <addrspace.h>
#include <kern/errno.h>
#include <kern/unistd.h>
#include <kern/stat.h>
#include <lib.h>
#include <filetable.h>
#include <../arch/mips/include/spl.h>
#include <curthread.h>
#include <thread.h>
#include <uio.h>
#include <vfs.h>
#include <vnode.h>
static void mk_useruio(struct iovec *iov, struct uio *u, userptr_t buf, 
       size_t len, off_t offset, enum uio_rw rw)
{

    iov->iov_ubase = buf;
    iov->iov_len = len;
    u->uio_offset = offset;
    u->uio_resid = len;
    u->uio_segflg = UIO_USERSPACE;
    u->uio_rw = rw;
    u->uio_space = curthread->t_vmspace;
}

int sys_getcwd(userptr_t buf, size_t buflen, int *retval) {
    struct uio user_uio;
    struct iovec user_iov;
    int result;

    /* set up a uio with the buffer, its size, and the current offset */
    mk_useruio(&user_iov, &user_uio, buf, buflen, 0, UIO_READ);

    result = vfs_getcwd(&user_uio);
    *retval = result;

    return result;
}


int sys_open(int *retval, char *filename, int flags, int mode) {

    if(!as_valid_read_addr(curthread->t_vmspace, (vaddr_t *)filename)){
        return EFAULT;
    }

    if (flags >= 63 || strlen(filename) < 1) {
        return EINVAL;
    }

    (void) mode;
    struct filedescriptor* fd = kmalloc(sizeof (struct filedescriptor));
    fd->fdvnode = kmalloc(sizeof (struct vnode));
    char *kfilename = kstrdup(filename);
    int copyflag = flags;
    flags = flags&O_ACCMODE;
    int offset = 0;
    int result = vfs_open(kfilename, copyflag, &fd->fdvnode);
    if (result) {
        return result;
    }

    if (copyflag & O_APPEND) {
        struct stat *statbuf = kmalloc(sizeof ( struct stat));
        VOP_STAT(fd->fdvnode, statbuf);
        offset = statbuf->st_size;
        kfree(statbuf);
    }

    if (copyflag & O_TRUNC) {
        VOP_TRUNCATE(fd->fdvnode, 0);
    }

    kfree(kfilename);
    fd->offset = offset;
    fd->mode = flags;
    fd->numOwners = 0; //will increment to 1 upon ft_add
    result = ft_add(curthread->ft, fd);
    *retval = result;
    return 0;
}
