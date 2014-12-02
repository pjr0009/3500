#include <lpage.h>


lpage* lpage_create(){
	lpage *ret = (lpage*)kmalloc(sizeof(lpage));
	if(ret){
		ret -> lp_paddr  = INVALID_VADDR;
		ret -> lp_swapaddr = INVALID_PADDR;
	} 
	return ret;
}

int lpage_lock(){
	// lock_acquire(lpage_lock)
}


lpage* lpage_zerofill(){
	lpage *lp;
	paddr_t pa;
	// off_t swa;

	lp = lpage_create();
	if (lp == NULL) {
		return ENOMEM;
	}

	// swa = swap_alloc();
	// if (swa == INVALID_SWAPADDR) {
	// 	lpage_destroy(lp);
	// 	return ENOSPC;
	// }
	// lp->lp_swapaddr = swa;

	// allocate some user page(s)
	pa = coremap_allocuser(lp);
	if (pa == INVALID_PADDR) {
		/* lpage_destroy will clean up the swap */
		// lpage_destroy(lp);
		return ENOSPC;
	}

	// lpage_lock(lp);

	lp -> lp_swapaddr = pa | LPF_DIRTY;

	// KASSERT(coremap_pageispinned(pa));

	// *lpret = lp;
	// *paret = pa;
	return 0;
}

int lpage_fault(lpage *lp, struct addrspace *as, int faulttype, vaddr_t va){
    paddr_t oldpa;
    off_t swa;
    int writable = 0;
    
    // lock the lpage before changing lpage attributes
    // lpage_lock_and_pin(lp);
    
    // get physical page address page number
    oldpa = lp->lp_swapaddr & PAGE_FRAME;
    
    // check if page in memory - if not, unlock the page and allocate
    if (oldpa == INVALID_PADDR) {  // page is not in RAM
        DEBUG(DB_VM, "Page is not in memory.\n");
        // get swap address
        swa = lp->lp_swapaddr;
        
        if (swa == INVALID_VADDR) {  // invalid swap address
            panic("Page fault: Page not found on disk.\n");
        }
        
        // unlock page before entering coremap code
        // lpage_unlock(lp);
        
        // allocate space in memory
        oldpa = coremap_allocuser(lp);
        if (new_frame_number == INVALID_PADDR) {
            DEBUG(DB_VM, "Failed to allocate page in coremap: Out of memory.\n");
            return ENOMEM;
        }
        
        // make sure the page is pinned
        // KASSERT(coremap_pageispinned(lpa));
        
        // acquire global paging lock before performing swap
        // lock_acquire(global_paging_lock);
        // load page into physical memory
        // swap_pagein(lpa, swa);
        // re-lock the lpage
        // lpage_lock(lp);
        // release global paging lock
        // lock_release(global_paging_lock);
        
        // set the new page address
        lp->lp_swapaddr = new_frame_number;
    }
    
    switch(faulttype) {
        case (VM_FAULT_READ):
            DEBUG(DB_VM, "vm_fault(): read\n");
            // read fault so set writable to 0
            writable = 0;
            break;
        case (VM_FAULT_WRITE):
            DEBUG(DB_VM, "vm_fault(): write\n");
            // write fault so set it to writable
            writable = 1;
            LP_SET(lp, LPF_DIRTY);
            break;
        case(VM_FAULT_READONLY):
            DEBUG(DB_VM, "vm_fault(): readonly\n");
            // page is new, set it to writable
            writable = 1;
            LP_SET(lp, LPF_DIRTY);
            break;
        default:
            panic("Invalid fault type.\n");
            break;
    }
    
    // unlock lpage before entering coremap code
    // lpage_unlock(lp);

    // put page in TLB
    // mmu_map(as, va, lpa, writable);
    
    return 0;
}


