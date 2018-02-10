#include "que.h"

Queue newQ(){
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->len = 0;
	q->head = NULL;
	q->tail = NULL;
	return *q;
}

boolean isEmptyQ(Queue q){
	if(q.len == 0){
		return TRUE;
	}
	return FALSE;
}

Queue delQ(Queue q){
	if(q.len == 0){
		return q;
	}
	if(q.len == 1){
		q.len = 0;
		q.head = NULL;
		q.tail = NULL;
		return q;
	}
	Element* node = q.head;
	q.head = node->next;
	q.len = q.len - 1;
	return q;
}

Element* front(Queue q){
	return q.head;
}

Queue addQ(Queue q, Element* e){
	if(q.len==0){
		q.head = e;
		q.tail = e;
		e->next = NULL;
		q.len = 1;
		return q;
	}
	Element* node = q.tail;
	node->next = e;
	q.tail = node->next;
	e->next = NULL;
	q.len = q.len + 1;
	return q;
}

int lengthQ(Queue q){
	return q.len;
}
