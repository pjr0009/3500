#include <vm.h> 
#include <kern/errno.h>
#include <lib.h>
#include <array.h>

struct vm_object *vm_object_create (size_t npages)
{

	struct vm_object *vmo = NULL;
	unsigned i; int result;

	DEBUG(DB_VM, "vm_object (page table) created: pages = %d\n", npages);

	vmo = (struct vm_object *)kmalloc(sizeof(struct vm_object));
	if (vmo == NULL) {
		return (NULL);
	}

	vmo -> lpages = array_create();
	if (vmo -> lpages == NULL) {
		kfree(vmo);
		return (NULL);
	}

	// filled in as_define_region
	// vmo -> base = 0xdeadbeef;
	// vmo -> redzone = 0xdeafbeef;

	// add zerofilled pages
	result = array_setsize(vmo -> lpages, npages);
	if (result) {
		array_destroy(vmo -> lpages);
		kfree(vmo);
		return (NULL);
	}
	vmo -> base_address = INVALID_VADDR;

	for (i = 0; i < npages; i++) {
		array_add(vmo -> lpages, NULL);
	}

	return (vmo);

}