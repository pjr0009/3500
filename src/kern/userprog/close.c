#include <types.h>
#include <filetable.h>
#include <curthread.h>
#include <thread.h>

int sys_close(int *retval, int index){
	ft_remove(curthread -> ft, index);
	*retval = 0;
	return 1;
}