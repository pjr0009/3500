/*
 * Filetables for the thread. See filetable.h for details.
 */
#include <types.h>
#include <kern/errno.h>
#include <kern/unistd.h>
#include <kern/limits.h>
#include <machine/spl.h>
#include <lib.h>
#include <array.h>
#include <queue.h>
#include <vfs.h>
#include <vnode.h>
#include <filetable.h>
/*
 * ft_create()
 * Creates a file table that is attached to the thread library.
 * 
 */
struct filetable *ft_create() {
    struct filetable *ft = kmalloc(sizeof (struct filetable));
    if (ft == NULL) {
        return NULL;
    }
    ft->size = 0;
    ft->filedescriptor = array_create();
    if (ft->filedescriptor == NULL) {
        ft_destroy(ft);
        return NULL;
    }
    array_preallocate(ft->filedescriptor, 20);
    array_add(ft->filedescriptor, NULL);
    array_add(ft->filedescriptor, NULL);
    array_add(ft->filedescriptor, NULL);
    //Return the file table
    return ft;
}


int ft_attachstds(struct filetable *ft) {
    char *console = NULL;
    int mode;
    int result = 0;
    //STDIN
    struct vnode *vn_stdin;
    mode = O_RDONLY;
    struct filedescriptor *fd_stdin = NULL;
    fd_stdin = (struct filedescriptor *) kmalloc(sizeof ( struct filedescriptor));
    if (fd_stdin == NULL) {
        ft_destroy(ft);
        return 0;
    }
    console = kstrdup("con:");
    result = vfs_open(console, mode, &vn_stdin);
    if (result) {
        vfs_close(vn_stdin);
        ft_destroy(ft);
        return 0;
    }
    kfree(console);
    fd_stdin->mode = mode;
    fd_stdin->offset = 0;
    fd_stdin->fdvnode = vn_stdin;
    fd_stdin->numOwners = 1;
    ft_set(ft, fd_stdin, STDIN_FILENO);
    //STDOUT
    struct vnode *vn_stdout;
    mode = O_WRONLY;
    struct filedescriptor *fd_stdout = NULL;
    fd_stdout = (struct filedescriptor *) kmalloc(sizeof (struct filedescriptor));
    if (fd_stdout == NULL) {
        ft_destroy(ft);
        return 0;
    }
    console = kstrdup("con:");
    result = vfs_open(console, mode, &vn_stdout);
    if (result) {
        vfs_close(vn_stdout);
        ft_destroy(ft);
        return 0;
    }
    kfree(console);
    fd_stdout->mode = mode;
    fd_stdout->offset = 0;
    fd_stdout->fdvnode = vn_stdout;
    fd_stdout->numOwners = 1;
    ft_set(ft, fd_stdout, STDOUT_FILENO);
    //STDERR
    struct vnode *vn_stderr;
    mode = O_WRONLY;
    struct filedescriptor *fd_stderr = NULL;
    fd_stderr = (struct filedescriptor *) kmalloc(sizeof (struct filedescriptor));
    if (fd_stderr == NULL) {
        ft_destroy(ft);
        return 0;
    }
    console = kstrdup("con:");
    result = vfs_open(console, mode, &vn_stderr);
    if (result) {
        vfs_close(vn_stderr);
        ft_destroy(ft);
        return 0;
    }
    kfree(console);
    fd_stderr->mode = mode;
    fd_stderr->offset = 0;
    fd_stderr->fdvnode = vn_stderr;
    fd_stderr->numOwners = 1;
    ft_set(ft, fd_stderr, STDERR_FILENO);
    return 1;
}

int ft_array_size(struct filetable *ft) {
    assert(ft != NULL);
    return (array_getnum(ft->filedescriptor));
}

int ft_size(struct filetable *ft) {
    assert(ft != NULL);
    int total = array_getnum(ft->filedescriptor);
    int i = 0;
    for (i = 0; i < ft_array_size(ft); i++) {
        if (ft_get(ft, i) == NULL) {
            total--;
        }
    }
    return total;
}

struct filedescriptor *ft_get(struct filetable *ft, int fti) {
    if (fti < 0) {
        return NULL;
    }
    //Since the stds are not attached to the thread, if the fd <=2 is requested,
    //then we will attach the stds to the thread.
    if (fti < 3) {
        if (array_getguy(ft->filedescriptor, fti) == NULL) {
            ft_attachstds(ft);
        }
    }
    //Doesn't exist.
    if (fti >= ft_array_size(ft)) { //changed > to >= since there shouldn't be an element ARRAY_SIZE --Matt
        return NULL;
    }
    struct filedescriptor *ret = array_getguy(ft->filedescriptor, fti);
    return ret;
}

int ft_set(struct filetable* ft, struct filedescriptor* fd, int fti) {
    if (fti >= ft_array_size(ft)) {
        return 1;
    }
    array_setguy(ft->filedescriptor, fti, fd);
    if (ft_get(ft, fti) == fd) {
        return 1;
    }
    return 0;
}

int ft_add(struct filetable* ft, struct filedescriptor* fd) {
    int index = 0;
    for (index = 0; index < ft_array_size(ft) && index < OPEN_MAX; index++) {
        if (ft_get(ft, index) == NULL) {
            array_setguy(ft->filedescriptor, index, fd);
            return index;
        }
    }
    if (index == OPEN_MAX) {
        return -1;
    }
    if (array_add(ft->filedescriptor, fd) != 0) { //if error (ENOMEM)
        return -1;
    }
    fd->numOwners++;
    assert(index != 0);
    return index;
}

int ft_remove(struct filetable* ft, int fti) {
    struct filedescriptor * fd = ft_get(ft, fti);
    if (fd != NULL) {
        int spl = splhigh();
        fd->numOwners--;
        if (fd->numOwners == 0) {
            vfs_close(fd->fdvnode);
            kfree(fd);
        }
        splx(spl);
        array_setguy(ft->filedescriptor, fti, NULL);
        return 1;
    } else {
        return -1;
    }
}

int ft_destroy(struct filetable* ft) {
    int i;
    for (i = ft_array_size(ft) - 1; i >= 0; i--) {
        ft_remove(ft, i);
    }
    kfree(ft);
    return 1;
}


