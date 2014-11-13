
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
        // DEBUG(DB_PID, "Invalid option passed to waitpid\n");
        splx(spl);
        //error
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
    if (child == NULL) { //error: pid not in use or is not the pid of a child process
        // DEBUG(DB_PID, "Thread `%s` trying to wait on invalid PID %d\n", curthread->t_name, (int) PID);
        splx(spl);
        //error
        if (pid_claimed(PID)) {
            return -1; //do not have permission to wait on that pid
        } else {
            return -1; //not a valid pid
        }
    }
    
    // DEBUG(DB_PID, "Thread `%s`: wait_pid(%d)\n", curthread->t_name, (int) PID);
    while (child->finished == 0) {
        thread_sleep((void *) PID);
    }
    
    *status = child->exit_code;
    
    //now, remove the child from children list since it has exited and it's PID is no longer needed
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

