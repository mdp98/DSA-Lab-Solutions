#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int key;
	struct element* next;
}Element;

typedef struct seqlist{
	Element* head;
	Element* tail;
}SeqList;

SeqList* newList();
SeqList* insertInOrder(SeqList* sl, Element* e);
SeqList* insertAtFront(SeqList* sl, Element* e);
SeqList* insertAtEnd(SeqList* sl, Element* e);
SeqList* del(SeqList* sl, Element* e);
SeqList* deleteAtFront(SeqList* sl);
Element* find(SeqList* sl, int k);

