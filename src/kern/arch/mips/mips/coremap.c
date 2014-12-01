#include <machine/coremap.h>

void coremap_bootstrap(void) {
	paddr_t first, last;
	u_int32_t coremap_size;
	int num_of_pages, i;

	DEBUG(DB_VM, "\n\nCOREMAP BOOTSTRAP \n");


	ram_getsize(&first, &last);

	num_of_pages = (last - first) / PAGE_SIZE;

	global_paging_lock = sem_create("global_paging_lock", 1);
	


	coremap_size = num_of_pages * sizeof(struct coremap_entry);
	coremap_size = ROUNDUP(coremap_size, PAGE_SIZE);

	// Coremap is an array which is indexed by its physical address.
	// stealing memory for coremap itself. 
	coremap = (struct coremap_entry *) PADDR_TO_KVADDR(first);

	// Get base coremap page
	base_coremap_page = first / PAGE_SIZE;

	// Get last coremap page
	num_coremap_entries = (last - first) / PAGE_SIZE;
	// not sure what these should be (yet).
	num_coremap_kernel = 0;
	num_coremap_user = 0;
	num_coremap_free = num_coremap_entries;

	// initialize each entry
	for (i=0; i < num_coremap_entries; i++) {
		coremap[i].cm_kernel = 0; 
		coremap[i].cm_notlast = 1;
		coremap[i].cm_allocated = 0;
		coremap[i].cm_pinned = 0; 
		coremap[i].cm_tlbix = 1; 
		coremap[i].cm_lp = NULL;
	}
	DEBUG(DB_VM, "Number of pages: %d \n", num_of_pages);
	DEBUG(DB_VM, "coremap_size : %d \n", coremap_size);
	DEBUG(DB_VM, "Number of coremap entries: %d \n", num_coremap_entries);
	DEBUG(DB_VM, "COREMAP BOOTSTRAP SUCCESS! \n \n", num_coremap_entries);


	vm_bootstrapped = 1;
}	

paddr_t coremap_alloc_multipages(int npages){
	return (paddr_t)npages;
};

void coremap_free_multipages(int npages){
	(void)npages;
};


//using this for when malloc is called before coremap has been bootstrapped.
static paddr_t getppages(unsigned long npages)
{
	int spl;
	paddr_t addr;

	spl = splhigh();

	addr = ram_stealmem(npages);
	
	splx(spl);
	return addr;
}

paddr_t coremap_alloc_page(struct lpage *lp, int dopin){
	
	if(vm_bootstrapped != 1){
		return getppages(1);
	} 
	//otherwise we have coremap initialized and have global paging lock initialized.
	int i;
	int candidate = -1;
	
	// critical section
	P(global_paging_lock);
	DEBUG(DB_VM, "\nAllocating page");

	if(num_coremap_free > 0){
		
		// find a coremap entry candidate
		for(i=0; i < num_coremap_entries; i++){
			if(coremap[i].cm_pinned || coremap[i].cm_allocated || coremap[i].cm_kernel){
				continue;
			}
			else{
				candidate = i;
				break;
			}
		}

		// check candidate and allocate it accordingly, returning the physical address for the tlb?
		if(candidate == -1 /* and not in interrupt */){
			DEBUG(DB_VM, "\nNeed to evict and swap out victim\n");
			return INVALID_PADDR; /*for now*/
			/* page swap; evict someone */
		} else if (candidate < 0){
			DEBUG(DB_VM, "\nNo valid coremap entry found!!\n");
			V(global_paging_lock);
			return INVALID_PADDR;
		} else {
			DEBUG(DB_VM, "\nCoremap entry %d being allocated\n" , candidate);
			/* found a free coremap entry */
			coremap[candidate].cm_allocated = 1;
			coremap[candidate].cm_lp = lp;
			coremap[candidate].cm_pinned = dopin;

			V(global_paging_lock);
			
			// check if it's a kernel entry
			if(lp == NULL){
				coremap[candidate].cm_kernel = 1;
				num_coremap_kernel += 1;
			} else {
				num_coremap_user += 1;
			}
			return COREMAP_TO_PADDR(candidate);
		}
	}
	DEBUG(DB_VM, "\nNO COREMAP ENTRIES FREE\n");
	return INVALID_PADDR;
};

void coremap_free_page(){

};