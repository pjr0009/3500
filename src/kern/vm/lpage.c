#include <lpage.h>
#include <machine/coremap.h>


lpage* lpage_create(){
	lpage *ret = kmalloc(sizeof(lpage));
	if(ret){
		ret -> lp_paddr  = INVALID_VADDR;
		ret -> lp_swapaddr = INVALID_PADDR;
        ret -> lp_lock = sem_create("lp_lock", 1);
    } 
	return ret;
}



lpage* lpage_zerofill(lpage ** lpret){
	lpage *lp;
	paddr_t pa;
	off_t swa;

	lp = lpage_create();
	if (lp == NULL) {
		return ENOMEM;
	}


	swa = swap_alloc();
    
	if (swa == INVALID_SWAPADDR) {
		// lpage_destroy(lp);
		return ENOSPC;
	}
    // allocate some user page(s)
    pa = coremap_allocuser(lp);

    lp->lp_paddr = pa | LPF_DIRTY;
    lp->lp_swapaddr = swa;



    DEBUG(DB_VM ,"PADDR %d", pa);
	if (pa == INVALID_PADDR) {
		/* lpage_destroy will clean up the swap */
		// lpage_destroy(lp);
		return ENOSPC;
	}

	// lpage_lock(lp);


	// KASSERT(coremap_pageispinned(pa));

	*lpret = lp;
	// *paret = pa;
	return 0;
}


int lpage_fault(lpage *lp, struct addrspace *as, int faulttype, vaddr_t va)
{

    /* Handle  TLB miss. */
    if ((faulttype == VM_FAULT_READ) || (faulttype == VM_FAULT_WRITE)) {
        lpage_lock_acquire(lp);
        paddr_t pa = (lp->lp_paddr & PAGE_FRAME);
        
        /* If data is not in physical memory, swap in. */
        // if (pa == INVALID_PADDR) {
            // ct_majfaults++;
            off_t swa = lp->lp_swapaddr;
            // KASSERT(swa != INVALID_SWAPADDR);
            
            // lpage_lock_release(lp);
            DEBUG(DB_VM,"\n\n\n\n4");

            
            /* Check if physical memory was allocated successfully. */
            if (pa == INVALID_PADDR) {
                return ENOMEM;
            }
            
            /* Swap in the page. */
            DEBUG(DB_VM, "Swapping in a page.\n");
            // KASSERT(coremap_pageispinned(pa));
            // P(global_paging_lock);
            swap_pagein(pa, swa);
            DEBUG(DB_VM,"4");
            
            lpage_lock_acquire(lp);
            // V(global_paging_lock);
            
            /* Assert page was not swapped in by another thread. */
            // KASSERT((lp->lp_paddr & PAGE_FRAME) == INVALID_PADDR);
            lp->lp_paddr = pa & PAGE_FRAME;
        // }
        /* Get dirty bit from existing physical address. */
        // else {
        //     // ct_minfaults++;
        //     DEBUG(DB_VM, "Re-adding entry\n");
        // }
        
        lpage_lock_release(lp);
        // KASSERT(coremap_pageispinned(pa));
        
        /* Enter translation to MMU. */
        // mmu_map(as, va, pa, LP_ISDIRTY(lp));
    }
    /* Handle readonly fault. Update the dirty bit to 1. */
    else {
        DEBUG(DB_VM, "!!!Fault type readonly.\n");
        
        /* Set dirty bit to 1. */
        // lpage_lock_and_pin(lp);
        LP_SET(lp, LPF_DIRTY);
        paddr_t pa = lp->lp_paddr;
        lpage_lock_release(lp);
        
        /* Update translation in MMU. Set dirty bit to 1. */
        // mmu_unmap(as, va);
        // mmu_map(as, va, pa, LPF_DIRTY);
    }
    
    return 0;
}


void lpage_lock_acquire(lpage *lp){
    // P(lp -> lp_lock);
}

void lpage_lock_release(lpage *lp){
    // V(lp -> lp_lock);

    
}
