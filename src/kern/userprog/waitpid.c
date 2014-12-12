
#include <machine/spl.h>
#include <kern/unistd.h>
#include <pid.h>
#include <child_table.h>
#include <thread.h>
#include <curthread.h>
#include <vm.h>
#include <kern/errno.h>
#include <lib.h>

#include <addrspace.h>


int sys_waitpid(pid_t PID, int *status, int options) {
    int spl = splhigh();
    if (options != 0) {
        splx(spl);
        return EINVAL;
    }
    struct child_table *child = NULL;
    struct child_table *p;
    for (p = curthread->children; p != NULL; p = p->next) {
        if (p->pid == PID) {
            child = p;
            break;
        }
    }
    if (child == NULL) {
        splx(spl);
        //error
        if (pid_claimed(PID)) {
            return -1; /
        } else {
            return -1;
        }
    }
    
    while (child->finished == 0) {
        thread_sleep((void *) PID);
    }
    
    *status = child->exit_code;
    
    if (curthread->children->pid == PID) {
        struct child_table *temp = curthread->children;
        curthread->children = curthread->children->next;
        kfree(temp);
    } else {
        for (p = curthread->children;; p = p->next) {
            assert(p->next != NULL);
            if (p->next->pid == PID) {
                struct child_table *temp = p->next;
                p->next = p->next->next;
                kfree(temp);
                break;
            }
        }
    }
    
    pid_parent_done(PID);
    splx(spl);
    
    return PID;
}

