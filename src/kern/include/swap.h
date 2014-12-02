#include <synch.h>
#include <lib.h>
static const char swapfilename[] = "lhd0raw:"; /*Swap file*/
static struct vnode *swapstore; /* swap allocation map */ 
static struct bitmap *swapmap; /* synchronizes swapmap and counters */ 
static struct lock *swaplock;
static unsigned long swap_total_pages; 
static unsigned long swap_free_pages; 
static unsigned long swap_reserved_pages;
struct lock *global_paging_lock;