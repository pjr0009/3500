#ifndef _SYSCALL_H_
#define _SYSCALL_H_

/*
 * Prototypes for IN-KERNEL entry points for system call implementations.
 */
#include <types.h> 
#include <machine/trapframe.h>
#include <child_table.h>

int sys_reboot(int code);
int sys_getpid(pid_t *retval);
pid_t sys_fork(struct trapframe *tf);
int sys_execv();
int sys_waitpid();
int sys_open(int *retval, const char *path, int oflag, int mode);
int sys_read(int *retval, int index, void *buf, size_t nbytes);
int sys_write(int *retval, int index, void *buf, size_t nbytes); 
int sys_close(int *retval, int index);




#endif /* _SYSCALL_H_ */
