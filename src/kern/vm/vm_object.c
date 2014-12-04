#include <vm.h> 
#include <kern/errno.h>
#include <lib.h>
#include <array.h>

struct vm_object *vm_object_create (size_t npages)
{

	struct vm_object *vmo;
	unsigned i;
	int result;

	// result = swap_reserve(npages);
	// if (result != 0) {
	// 	return NULL;
	// }

	vmo = kmalloc(sizeof(struct vm_object));
	if (vmo == NULL) {
		// swap_unreserve(npages);
		return NULL;
	}

	vmo->lpages = array_create();
	if (vmo->lpages == NULL) {
		kfree(vmo);
		// swap_unreserve(npages);
		return NULL;
	}

	vmo->base_address = 0xdeafbeef;		/* make sure these */

	/* add the requested number of zerofilled pages */
	result = array_setsize(vmo->lpages, npages);
	if (result) {
		array_destroy(vmo->lpages);
		kfree(vmo);
		// swap_unreserve(npages);
		return NULL;
	}

	for (i=0; i<npages; i++) {
		array_setguy(vmo->lpages, i, NULL);
	}

	return vmo;

}