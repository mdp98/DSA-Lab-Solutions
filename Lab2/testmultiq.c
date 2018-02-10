#include "multiq.h"
#include <sys/time.h>

MultiQ* loadData(FILE* f){
	MultiQ* mq = createMQ(10);
	if(f == NULL){
		return NULL;
	}
	while(!feof(f)){
		int id,priority;
		fscanf(f, "%d,%d", &id, &priority);
		//printf("%d %d\n",id,priority);
		Task* t = (Task*)malloc(sizeof(Task));
		t->tid = id;
		t->pr = priority;
		mq = addMQ(mq,t);
	}
	return mq;
}

MultiQ* testDel(MultiQ* mq, int num){
	for(int i=0; i<num; i++){
		mq = delNextMQ(mq);
	}
	printf("%d deletions done.\n", num);
	return mq;
}

int main(){
	MultiQ* mq = createMQ(10);
	FILE* f;
	f = fopen("input100.txt", "r");
	
	struct timeval t1,t2;
	double elapsedtime;
	gettimeofday(&t1, NULL);
	mq = loadData(f);
	gettimeofday(&t2, NULL);
	elapsedtime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedtime += (t2.tv_usec - t1.tv_usec)/1000.0;
	printf("Time taken to load data from file : %f\n", elapsedtime);	
	
	printMQ(mq);

	gettimeofday(&t1, NULL);
	mq = testDel(mq, 40);
	gettimeofday(&t2, NULL);
	elapsedtime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedtime += (t2.tv_usec - t1.tv_usec)/1000.0;
	printf("Time taken for deletions : %f\n", elapsedtime);	
		
	printMQ(mq);
	Task* t = nextMQ(mq);
	printf("%d %d\n",t->tid, t->pr);
	printf("Is the MultiQ empty? : %d\n", isEmptyMQ(mq));
	printf("Total items in MutliQ : %d\n", sizeMQ(mq));
	Priority* priority = (Priority*)malloc(sizeof(Priority));
	priority -> pr = 5;	
	printf("Number of items with priority 5 : %d\n", sizeMQbyPriority(mq,priority));
	
}

void printMQ(MultiQ* mq){
	for(int i=0; i<mq->size; i++){
		printf("Priority %d :", i+1);
		if(mq->q[i].len == 0){
			printf("\n");
			continue;	
		}
		Element* node = mq->q[i].head;
		while(node != mq->q[i].tail){
			printf("%d ",node->key);
			node = node->next;
		}
		printf("%d\n",node->key);
	}
}
