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
    kprintf("swap: Error %d opening swapfile %s\n", rv, swapfilename);
    kprintf("swap: Please create swapfile/swapdisk.\n");
    panic("swap: Unable to continue.\n");
  }

  // minsize = pmemsize*20;

  // VOP_STAT(swapstore, &st);
  // if (st.st_size < minsize) {
  //   kprintf("swap: swapfile %s is only %lu bytes.\n", swapfilename,
  //     (unsigned long) st.st_size);
  //   kprintf("swap: with %lu bytes of physical memory it should "
  //     "be at least\n", (unsigned long) pmemsize);
  //   kprintf("      %lu bytes (%lu blocks), perhaps larger.\n", 
  //     (unsigned long) minsize, 
  //     (unsigned long) minsize / 512);
  //   kprintf("swap: Because we conservatively reserve swap, a "
  //     "large amount may be\n");
  //   kprintf("      needed to run large workloads.\n");
  //   kprintf("swap: Please extend it.\n");
  //   panic("swap: Unable to continue.\n");
  // }

  kprintf("swap: swapping to %s (%lu bytes; %lu pages)\n", swapfilename,
    (unsigned long) st.st_size, 
    (unsigned long) st.st_size / PAGE_SIZE);

  swap_total_pages = st.st_size / PAGE_SIZE;
  swap_free_pages = swap_total_pages;
  swap_reserved_pages = 0;

  swapmap = bitmap_create(st.st_size/PAGE_SIZE);
  DEBUG(DB_VM, "creating swap map with %lld entries\n",
      st.st_size/PAGE_SIZE);
  if (swapmap == NULL) {
    panic("swap: No memory for swap bitmap\n");
  }

  swaplock = lock_create("swaplock");
  if (swaplock == NULL) {
    panic("swap: No memory for swap lock\n");
  }

  /* mark the first page of swap used so we can check for errors */
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

  // KASSERT(swap_free_pages <= swap_total_pages);
  // KASSERT(swap_reserved_pages <= swap_free_pages);

  // KASSERT(swap_reserved_pages>0);
  // KASSERT(swap_free_pages>0);

  rv = bitmap_alloc(swapmap, &index);
  /* If this blows up, our counters are wrong */
  // KASSERT(rv == 0);

  swap_reserved_pages--;
  swap_free_pages--;

  lock_release(swaplock);

  return index*PAGE_SIZE;
}