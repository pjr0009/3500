#include <coremap.h>

void coremap_bootstrap(void) {
	paddr_t first, last;
	u_int32_t coremap_size;
	int num_of_pages;

	ram_getsize(&first, &last);


	num_of_pages = (last - first) / PAGE_SIZE;


	coremap_size = num_of_pages * sizeof(struct coremap_entry);
	coremap_size = ROUNDUP(coremap_size, PAGE_SIZE);

	/*
	 * Steal pages for the coremap.
	 */
	coremap = (struct coremap_entry *) PADDR_TO_KVADDR(first);

	// Get base coremap page
	base_coremap_page = first / PAGE_SIZE;

	// Get last coremap page
	num_coremap_entries = (last - first) / PAGE_SIZE;
	num_coremap_kernel = 0;
	num_coremap_user = 0;
	num_coremap_free = num_coremap_entries;

	for (i=0; i < num_coremap_entries; i++) {
		coremap[i].cm_kernel = 1; 
		coremap[i].cm_notlast = 1;
		coremap[i].cm_allocated = 1;
		coremap[i].cm_pinned = 0; 
		coremap[i].cm_tlbix = 1; 
		coremap[i].cm_lp = 1;
	}

}	
