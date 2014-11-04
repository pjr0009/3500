#include <types.h>
#include <kern/errno.h>
#include <lib.h>
#include <addrspace.h>
#include <vm.h>

/*
 * Note! If OPT_DUMBVM is set, as is the case until you start the VM
 * assignment, this file is not compiled or linked or in any way
 * used. The cheesy hack versions in dumbvm.c are used instead.
 */



int as_valid_read_addr(struct addrspace *as, vaddr_t *check_addr) {
    // if (check_addr < (vaddr_t*) USERTOP) {
    //     if (check_addr >= (vaddr_t*) as->as_vbase1 && check_addr < (vaddr_t*) (as->as_vbase1 + as->as_npages1 * PAGE_SIZE)) {
    //         return 1;
    //     }
    //     if (check_addr >= (vaddr_t*) as->as_vbase2 && check_addr < (vaddr_t*) (as->as_vbase2 + as->as_npages2 * PAGE_SIZE)) {
    //         return 1;
    //     }
    //     if (check_addr >= (vaddr_t*) (USERTOP - DUMBVM_STACKPAGES * PAGE_SIZE)) {
    //         return 1;
    //     }
    // }
    return 1;
}

int as_valid_write_addr(struct addrspace *as, vaddr_t *check_addr) {
    // if (check_addr < (vaddr_t*) USERTOP) {
    //     if (check_addr >= (vaddr_t*) as->as_vbase2 && check_addr < (vaddr_t*) (as->as_vbase2 + as->as_npages2 * PAGE_SIZE)) {
    //         return 1;
    //     }
    //     if (check_addr >= (vaddr_t*) (USERTOP - DUMBVM_STACKPAGES * PAGE_SIZE)) {
    //         return 1;
    //     }
    // }
    return 1;
}