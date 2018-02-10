#include <stdio.h>
#include <stdlib.h>

typedef enum{
	FALSE=0,
	TRUE=1
}boolean;

typedef struct element{
	int key;
	struct element* next;
}Element;

typedef struct queue{
	int len;
	Element* head;
	Element* tail;
}Queue;

Queue newQ();
boolean isEmptyQ(Queue q);
Queue delQ(Queue q);
Element* front(Queue q);
Queue addQ(Queue q, Element* e);
int lengthQ(Queue q);
