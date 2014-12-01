#include <types.h>
#include <kern/errno.h>
#include <lib.h>
#include <addrspace.h>
#include <vm.h>
#include <lpage.h>
/*
 * Note! If OPT_DUMBVM is set, as is the case until you start the VM
 * assignment, this file is not compiled or linked or in any way
 * used. The cheesy hack versions in dumbvm.c are used instead.
 */

struct addrspace *
as_create(void)
{
	struct addrspace *as = kmalloc(sizeof(struct addrspace));
	if (as==NULL) {
		return NULL;
	}
	// create array of page tables
	as -> as_objects = (struct vm_object*)array_create();
	DEBUG(DB_VM, "\nArray allocated for address space objects\n");

	// verify as_objects array was created successfully
	if (as->as_objects == NULL) {
		kfree(as);
		return NULL;
	}

	return as;
}


int as_fault(int faulttype, vaddr_t faultaddress, struct addrspace*  as){
	
};


int
as_copy(struct addrspace *old, struct addrspace **ret)
{
	struct addrspace *newas;

	newas = as_create();
	if (newas==NULL) {
		return ENOMEM;
	}

	/*
	 * Write this.
	 */

	(void)old;
	
	*ret = newas;
	return 0;
}

void
as_destroy(struct addrspace *as)
{
	/*
	 * Clean up as needed.
	 */
	
	kfree(as);
}

void
as_activate(struct addrspace *as)
{
	/*
	 * Write this.
	 */

	(void)as;  // suppress warning until code gets written
}

/*
 * Set up a segment at virtual address VADDR of size MEMSIZE. The
 * segment in memory extends from VADDR up to (but not including)
 * VADDR+MEMSIZE.
 *
 * The READABLE, WRITEABLE, and EXECUTABLE flags are set if read,
 * write, or execute permission should be set on the segment. At the
 * moment, these are ignored. When you write the VM system, you may
 * want to implement them.
 */
int as_define_region(struct addrspace *as, vaddr_t vaddr, size_t sz,
		 int readable, int writeable, int executable)
{
	DEBUG(DB_VM, "\nCREATING ADDRESS SPACE REGION FOR TEXT/CODE SEGMENT\n");
	struct vm_object *vmobj;
	int i, result;
	/* align base address */
	vaddr &= PAGE_FRAME;

	/* size may not be */
	sz = ROUNDUP(sz, PAGE_SIZE);

	/*
	 * Check for overlaps.
	 */
	// for (i = 0; i < array_getnum(as->as_objects); i++) {
	// 	vaddr_t bot, top;
		
	// 	vmo = vm_object_array_get(as->as_objects, i);
	// 	KASSERT(vmo != NULL);
	// 	bot = vmo->vmo_base;
	// 	top = bot + PAGE_SIZE * lpage_array_num(vmo->vmo_lpages);

	// 	/* Check guard band, if any */
	// 	KASSERT(bot >= vmo->vmo_lower_redzone);
	// 	bot = bot - vmo->vmo_lower_redzone;

	// 	if (check_vaddr+sz > bot && check_vaddr < top) {
	// 		/* overlap */
	// 		return EINVAL;
	// 	}
	// }


	/* Create a new vmo. All pages are marked zerofilled. */
	vmobj = vm_object_create(sz/PAGE_SIZE);
	if (vmobj == NULL) {
		return ENOMEM;
	}
	// vmo->vmo_base = vaddr;
	// vmo->vmo_lower_redzone = lower_redzone;

	/* Add it to the parent address space. */
	array_add(as->as_objects, vmobj);
	// if (result) {
	// 	vm_object_destroy(as, vmo);
	// 	return result;
	// }

	/* Done */
	return 0;
	
}

int
as_prepare_load(struct addrspace *as)
{
	/*
	 * Write this.
	 */

	(void)as;
	return 0;
}

int
as_complete_load(struct addrspace *as)
{
	/*
	 * Write this.
	 */

	(void)as;
	return 0;
}

int
as_define_stack(struct addrspace *as, vaddr_t *stackptr)
{
	/*
	 * Write this.
	 */

	(void)as;

	/* Initial user-level stack pointer */
	*stackptr = USERSTACK;
	
	return 0;
}

