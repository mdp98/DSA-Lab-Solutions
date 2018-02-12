#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int key;
	struct element* next;
}Element;

typedef struct llist{
	int size;
	Element* head;
	Element* tail;
}Llist;

Llist* createList(int n);
Element* createElem(int k);
Llist* createCycle(Llist* Ls);
//void printList(Llist* Ls);
Llist* makeCircularList(Llist* Ls);
