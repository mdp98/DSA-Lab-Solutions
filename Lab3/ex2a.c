#include "ex2a.h"

void* myalloc(int size, int num){
	void* ptr = (void*)malloc(size*num + 4);
	int* mem = ptr;
	*mem = size*num;
	memAlloc += size*num;
	return ptr;
}

void myfree(void* ptr){
	int* mem = ptr;
	int memory = *mem;
	memAlloc -= memory;
	free(ptr);
}
