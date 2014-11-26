#ifndef _LPAGE_H_
#define _LPAGE_H_

#include <types.h>
#include <machine/vm.h>
#include <kern/errno.h>
#include <lib.h>
#include <thread.h>
#include <addrspace.h>

typedef struct {
	vaddr_t page_number;
	paddr_t frame_number;
	short   dirty;
	short   resident;
} lpage;


lpage* create_lpage();

#endif