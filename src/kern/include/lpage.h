#ifndef _LPAGE_H_
#define _LPAGE_H_

#include <types.h>
#include <machine/vm.h>
#include <kern/errno.h>
#include <lib.h>
#include <thread.h>
#include <addrspace.h>
#include <synch.h>
#include <swap.h>

typedef struct {
	volatile paddr_t lp_paddr;
	off_t lp_swapaddr;
	struct semaphore* lp_lock;
} lpage;


lpage* lpage_create();
lpage* lpage_zerofill(lpage **lp);
int lpage_fault(lpage *lp, struct addrspace *as, int faulttype, vaddr_t va);
void lpage_lock_aquire(lpage *lp);
void lpage_lock_release(lpage *lp);


/* lpage flags */
#define LPF_DIRTY		0x1
#define LPF_MASK		0x1	// mask for the above

#define LP_ISDIRTY(lp)		((lp)->lp_paddr & LPF_DIRTY)

#define LP_SET(am, bit)		((lp)->lp_paddr |= (bit))
#define LP_CLEAR(am, bit)	((lp)->lp_paddr &= ~(paddr_t)(bit))

#endif