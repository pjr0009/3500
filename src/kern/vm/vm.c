#include <types.h>
#include <kern/errno.h>
#include <lib.h>
#include <thread.h>
#include <curthread.h>
#include <addrspace.h>
#include <vm.h>
#include <machine/spl.h>
#include <machine/tlb.h>

int vm_fault(int faulttype, vaddr_t faultaddress){
	DEBUG(DB_VM, "vm: fault: 0x%x\n", faultaddress);

    int spl;
	spl = splhigh();
    faultaddress &= PAGE_FRAME;
    addrspace * as = curthread -> t_vmspace;

	switch (faulttype) {
	
	    case VM_FAULT_READONLY:
			/* We always create pages read-write, so we can't get this */
			panic("dumbvm: got VM_FAULT_READONLY\n");
			// TLB READ MISS PROPIGATED FROM SYS161
		
		case VM_FAULT_READ:
	    	as_fault(faulttype, faultaddress, as);
	    	break;

	    case VM_FAULT_WRITE:
			panic("dumbvm: got VM_FAULT_WRITE\n");
			break;
	    
	    default:
	    	// UNKNOWN VMFAULT ERROR
			splx(spl);
			return EINVAL;

	}

	int i = faultaddress + faulttype;
	return i;
}