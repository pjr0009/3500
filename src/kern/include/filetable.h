#ifndef _FILETABLE_H_
#define _FILETABLE_H_
#define OPEN_MAX 100
/*
 basic table implementation, used for storing a list of file descriptors
 */

// Structure of the filedescriptor
struct filedescriptor;

struct filedescriptor {
	//The file descriptor number
	int index;
	int mode;
	//The mode of the file descriptor in question
	// int mode;
	//Number of owners of the file descriptor
	int numOwners;
	//The offset of the cursor in the file from the base address
	int offset;
	//pointer to vnode
	struct vnode* fdvnode;
};

// Structure of the filetable
struct filetable;

struct filetable {
	//The table of file descriptors
	struct array *filedescriptor;
	//The size of the filetable
	int size;
};

struct filetable *ft_create();
int ft_attachstds(struct filetable *ft);
int ft_array_size(struct filetable *ft);
int ft_size(struct filetable *ft);
struct filedescriptor *ft_get(struct filetable *ft, int fti);
int ft_set(struct filetable* ft, struct filedescriptor* fdn, int fti);
int ft_add(struct filetable* ft, struct filedescriptor* fdn);
int ft_remove(struct filetable* ft, int fti);
int ft_destroy(struct filetable* ft);
void ft_test_list(struct filetable* ft);
void ft_test(struct filetable* ft);
#endif