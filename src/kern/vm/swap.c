#include <swap.h>
#include <types.h>
#include <kern/errno.h>
#include <kern/limits.h>
#include <kern/unistd.h>
#include <vfs.h>
#include <vnode.h>
#include <lib.h>
#include <kern/stat.h>

void swap_bootstrap(void){
  int rv;
  struct stat st;
  char path[sizeof(swapfilename)];
  off_t minsize;
  size_t pmemsize;

  // pmemsize = mainbus_ramsize();

  strcpy(path, swapfilename);
  rv = vfs_open(path, O_RDWR, &swapstore);

  if (rv) {
    panic("swap: Unable to continue.\n");
  }

  swap_total_pages = st.st_size / PAGE_SIZE;
  swap_free_pages = swap_total_pages;
  swap_reserved_pages = 0;

  swapmap = bitmap_create(st.st_size/PAGE_SIZE);
  DEBUG(DB_VM, "creating swap map with %lld entries\n",
      st.st_size/PAGE_SIZE);
  swaplock = lock_create("swaplock");
  bitmap_mark(swapmap, 0);
  swap_free_pages--;
}

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

off_t
swap_alloc(void)
{
  u_int32_t rv, index;
  
  lock_acquire(swaplock);

  rv = bitmap_alloc(swapmap, &index);

  swap_reserved_pages--;
  swap_free_pages--;

  lock_release(swaplock);

  return index*PAGE_SIZE;
}