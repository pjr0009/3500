#include <types.h> 
#include <syscall.h> 
#include <thread.h> 
#include <curthread.h>

int sys_getpid(pid_t *retval){
	*retval = curthread -> pid;
	return 0;
}