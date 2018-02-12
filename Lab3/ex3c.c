#include "ex2a.h"
#include "ex3.h"
#include "cycle.h"
#include <sys/time.h>

int main(){
	Llist* Ls = createList(10);
	Ls = createCycle(Ls);
	//printList(Ls);
	
	struct timeval t1,t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);
	boolean test = testCyclic(Ls);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Elapsed time in testing : %f ms\n", elapsedTime);	
	
	if(test == 0){
		printf("Linear Linked List\n");
	}
	else{
		printf("Cyclic Linked List\n");	
	}
	
	Ls = makeCircularList(Ls);
	//printList(Ls);
}
