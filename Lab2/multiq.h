#include "que.h"

typedef struct task{
	int tid;
	int pr;
}Task;

typedef struct priority{
	int pr;
}Priority;

typedef struct multiq{
	int size;
	Queue* q;
}MultiQ;

MultiQ* createMQ(int num);
MultiQ* addMQ(MultiQ* mq, Task* t);
Task* nextMQ(MultiQ* mq);
MultiQ* delNextMQ(MultiQ* mq);
boolean isEmptyMQ(MultiQ* mq);
int sizeMQ(MultiQ* mq);
int sizeMQbyPriority(MultiQ* mq, Priority* p);
Queue getQueueFromMQ(MultiQ* mq, Priority* p);
