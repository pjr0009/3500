
#include <kern/unistd.h>
#include <types.h>
#include <thread.h>
#include <curthread.h>
#include <lib.h>
#include <kern/errno.h>
#include <machine/pcb.h>
#include <machine/spl.h>
#include <machine/trapframe.h>
#include <addrspace.h>
#include <child_table.h>

pid_t sys_fork(struct trapframe *tf) {
    int spl = splhigh();
    char *new_t_name = kmalloc(sizeof(char) * (strlen(curthread->t_name)+9));
    if (new_t_name == NULL) {
        //error
        splx(spl);
        return ENOMEM;
    }
    new_t_name = strcpy(new_t_name, curthread->t_name);
    struct child_table *new_child = kmalloc(sizeof(struct child_table));
    if (new_child == NULL) {
        //error
        splx(spl);
        return ENOMEM;
    }
    struct thread *child_thread = NULL;

    void (*func_pt)(void *, unsigned long) = &md_forkentry;
    
    int result = thread_fork(strcat(new_t_name, "- child"), tf, 0, func_pt, &child_thread);
   
    if (result != 0) {
        kfree(new_child);
        //ERROR
        splx(spl);
        return result;
    }  
    
    child_thread->parent = curthread;
    //add new process to list of children
    new_child->pid = child_thread->pid;
    new_child->finished = 0;
    new_child->exit_code = -2; //not really needed
    new_child->next = curthread->children;
    curthread->children = new_child;
    
    int err = as_copy(curthread->t_vmspace, &child_thread->t_vmspace); //copy the data to the child process's new address space
    
    //error handler
    if (err != 0) {
        // DEBUG(DB_THREADS, "Not enough memory to copy address space in fork. Closing child...\n");
        child_thread->t_vmspace = NULL;
        child_thread->parent = NULL; //to prevent thread_destroy from freeing a non-existant pid
        md_initpcb(&child_thread->t_pcb, child_thread->t_stack, 0, 0, &thread_exit); //set new thread to delete itself
        splx(spl);
        return err;
    }


    
    
    int retval = child_thread->pid;
    splx(spl);
    return retval; //the parent thread returns this.
}
