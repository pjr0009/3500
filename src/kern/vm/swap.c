#include <swap.h>


void swap_pagein(paddr_t pa, off_t swapaddr){
  DEBUG(DB_VM, "SWAPPING PAGE IN");
  swap_io(pa, swapaddr, UIO_READ);
};

void swap_io(paddr_t pa, off_t swapaddr, enum uio_rw rw){
  
  struct uio u; vaddr_t va;
  int result;
  // Get va from pa;
  va = PADDR_TO_KVADDR(pa);
  mk_kuio(&u, (char *)va, PAGE_SIZE, swapaddr, rw); 
  
  if(rw == UIO_READ) { 
  	result = VOP_READ(swapstore, &u);
  } 
  else {
    result = VOP_WRITE(swapstore, &u);
  }
  DEBUG(DB_VM, "SWAP IO");

  if (result==EIO){
  	panic("swap: EIO on swapfile (offset %ld)\n",(long)swapaddr); 
  }
  if(result==EINVAL){
    panic("swap: EINVAL on swapfile(offset%ld)\n",(long)swapaddr);
  } 
  if (result) {
  	panic("swap: Error %d from swapfile (offset %ld)\n", result, (long)swapaddr);
  }
}