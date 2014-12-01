#include <types.h>
#include <kern/errno.h>
#include <lib.h>
#include <thread.h>
#include <curthread.h>
#include <addrspace.h>
#include <vm.h>
#include <machine/coremap.h>
#include <machine/spl.h>
#include <machine/tlb.h>



void vm_bootstrap(void) {
	coremap_bootstrap();
}



int vm_fault(int faulttype, vaddr_t faultaddress){
	DEBUG(DB_VM, "vm: fault: 0x%x\n", faultaddress);

    int spl;
	spl = splhigh();
    faultaddress &= PAGE_FRAME;
    struct addrspace * as = curthread -> t_vmspace;

	switch (faulttype) {
	
	    case VM_FAULT_READONLY:
			/* We always create pages read-write, so we can't get this */
			panic("vm: got VM_FAULT_READONLY\n");
			// TLB READ MISS PROPIGATED FROM SYS161
		
		case VM_FAULT_READ:
	    	as_fault(faulttype, faultaddress, as);
	    	break;

	    case VM_FAULT_WRITE:
			panic("vm: got VM_FAULT_WRITE\n");
			break;
	    
	    default:
	    	// UNKNOWN VMFAULT ERROR
			splx(spl);
			return EINVAL;

	}

	int i = faultaddress + faulttype;
	return i;
}


vaddr_t alloc_kpages(int npages){
	paddr_t pa;
	if(npages > 1){
		pa = coremap_alloc_multipages(npages);
	}
	else {
		pa = coremap_alloc_page(NULL, 1);
	}
	if(pa == INVALID_PADDR){
		return 0;
	}
	return PADDR_TO_KVADDR(pa);
};

void free_kpages(vaddr_t npages){
	if(npages > 1){
		coremap_free_multipages(npages);
	}
	else {
		coremap_free_page();
	}
	// if(pa == INVALID_VADDR){
	// 	panic("invalid virtual address")
	// }
};
