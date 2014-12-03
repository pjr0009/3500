#include <synch.h>
#include <types.h>
#include <machine/vm.h>
#include <kern/errno.h>
#include <lib.h>
#include <vm.h>
#include <vnode.h>
#include <uio.h>

static const char swapfilename[] = "lhd0raw:"; /*Swap file*/
static struct vnode *swapstore; /* swap allocation map */ 
static struct bitmap *swapmap; /* synchronizes swapmap and counters */ 
static struct lock *swaplock;
static unsigned long swap_total_pages; 
static unsigned long swap_free_pages; 
static unsigned long swap_reserved_pages;
// struct lock *global_paging_lock;

void swap_pagein(paddr_t pa, off_t swapaddr);
void swap_pageout(paddr_t pa, off_t swapaddr);
void swap_io(paddr_t pa, off_t swapaddr, enum uio_rw rw);