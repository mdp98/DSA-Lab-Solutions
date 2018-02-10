#include "multiq.h"

MultiQ* createMQ(int num){
	MultiQ* mq = (MultiQ*)malloc(sizeof(MultiQ));
	mq->q = (Queue*)malloc(sizeof(Queue)*num);
	for (int i=0; i<num; i++){
		mq->q[i] = newQ();
	}
	mq->size = num;
	return mq;
}

MultiQ* addMQ(MultiQ* mq, Task* t){
	if(t->pr > mq->size){
		return mq;
	}
	Element* node = (Element*)malloc(sizeof(Element));
	node->key = t->tid;
	mq->q[t->pr - 1] = addQ(mq->q[t->pr - 1], node);
	return mq;
}

Task* nextMQ(MultiQ* mq){
	int i=0; 
	while (mq->q[i].len == 0 && i < mq->size){
		i++;
	}
	if(i == mq->size){
		return NULL;
	}
	Element* node = mq->q[i].head;
	Task* t = (Task*)malloc(sizeof(Task));
	t->tid = node->key;
	t->pr = i + 1;
	return t;
}

MultiQ* delNextMQ(MultiQ* mq){
	int i = 0;
	while(mq->q[i].len == 0 && i < mq->size){
		i++;
	}
	if(i == mq->size){
		return mq;
	}
	mq->q[i] = delQ(mq->q[i]);
	return mq;
}

boolean isEmptyMQ(MultiQ* mq){
	int i = 0;
	while (mq->q[i].len == 0 && i<mq->size){
		i++;
	}
	if(i == mq->size){
		return TRUE;
	}
	return FALSE;
}

int sizeMQ(MultiQ* mq){
	int s = 0;
	for (int i=0; i<mq->size; i++){
		s = s + mq->q[i].len;
	}
	return s;
}

int sizeMQbyPriority(MultiQ* mq, Priority* p){
	int prty = p->pr;
	if(prty > mq->size){
		return 0;
	}
	int s = mq->q[prty - 1].len;
	return s;
}

Queue getQueueFromMQ(MultiQ* mq, Priority* p){
	int prty = p->pr;
	if(prty > mq->size){
		return mq->q[0];
	}
	return mq->q[prty - 1];
}
