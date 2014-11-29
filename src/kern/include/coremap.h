#ifndef _COREMAP_H_
#define _COREMAP_H_

#include <types.h>
#include <kern/errno.h>
#include <lib.h>
#include <thread.h>
#include <curthread.h>
#include <addrspace.h>
#include <vm.h>
#include <lpage.h>
#include <machine/spl.h>
#include <machine/tlb.h>



// state of the coremap entry, spefices if it should ever be swapped out or written to disk
typedef enum {
	DIRTY,
	CLEAN,
	FIXED
} cm_state;


struct coremap_entry { 
	struct lpage *cm_lp; /* logical page we hold */
	int cm_tlbix:7; /* tlb index number, or -1 */ 
	unsigned cm_kernel:1,/* true if kernel page */ 
	cm_notlast:1,/* true not last in sequence of kernel pages */ 
	cm_allocated:1;  /* true if page in use */ 
	volatile unsigned cm_pinned:1; /*true if page is busy*/ 
};

static u_int32_t num_coremap_entries;
static u_int32_t num_coremap_free;
static u_int32_t base_coremap_page;

// coremap array
static struct coremap_entry *coremap;

/* pages allocated to the kernel */ 
static u_int32_t num_coremap_kernel; 

/* pages allocated to user progs */ 
static u_int32_t num_coremap_user;

//functions
void coremap_bootstrap(void);


#endif