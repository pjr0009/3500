#ifndef _VM_H_
#define _VM_H_
#include <types.h>
#include <machine/vm.h>

/*
 * VM system-related definitions.
 *
 * You'll probably want to add stuff here.
 */


/* Fault-type arguments to vm_fault() */
#define VM_FAULT_READ        0    /* A read was attempted */
#define VM_FAULT_WRITE       1    /* A write was attempted */
#define VM_FAULT_READONLY    2    /* A write to a readonly page was attempted*/

/* Invalid physical / virtual addresses for initialization routines */
 #define INVALID_VADDR       0
 #define INVALID_PADDR       0




/* Initialization function */
void vm_bootstrap(void);

/* Fault handling function called by trap code */
int vm_fault(int faulttype, vaddr_t faultaddress);

/* Allocate/free kernel heap pages (called by kmalloc/kfree) */
vaddr_t alloc_kpages(int npages);
vaddr_t page_alloc(int npages);

void free_kpages(vaddr_t addr);
void page_free(vaddr_t addr);

struct vm_object *vm_object_create (size_t npages);

struct vm_object{
	struct array *lpages;
	vaddr_t base_address;
	int readable:1;
	int writeable:1;
	int executable:1;	
};


#endif /* _VM_H_ */
