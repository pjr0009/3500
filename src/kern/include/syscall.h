#ifndef _SYSCALL_H_
#define _SYSCALL_H_

/*
 * Prototypes for IN-KERNEL entry points for system call implementations.
 */
#include <types.h> 
#include <machine/trapframe.h>

int sys_reboot(int code);
int sys_getpid(pid_t *retval);
pid_t sys_fork(struct trapframe *tf);
int sys_execv();
int sys_open(int *retval, const char *path, int oflag, int mode);



#endif /* _SYSCALL_H_ */
