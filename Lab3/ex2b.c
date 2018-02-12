#include "ex2a.h"

int main(){
	for(int i=0; i<10; i++){
		memAlloc = 0;
		int m = (rand()%15000) + 10000;
		//printf("m = %d\n", m);
		printf("Memory allocated : %d\n", memAlloc);
		int* a = myalloc(sizeof(int), m);
		printf("Memory allocated : %d\n", memAlloc);
		printf("Address of first location: %u\n", a+1);
		printf("Address of last location: %u\n", a+m);
		myfree(a);
		printf("Memory allocated : %d\n", memAlloc);
		printf("-------------------------------------\n");
	}
}
