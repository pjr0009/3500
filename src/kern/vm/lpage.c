#include <lpage.h>


lpage* create_lpage(){
	lpage *ret = (lpage*)kmalloc(sizeof(lpage));
	if(ret){
		ret -> page_number  = INVALID_VADDR;
		ret -> frame_number = INVALID_PADDR;
		ret -> dirty = 0;
		ret -> resident = 0;
	} 
	return ret;
}

