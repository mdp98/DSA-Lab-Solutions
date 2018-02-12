#include "ex2a.h"
#include "ex3.h"
#include "cycle.h"

Llist* createList(int n){
	Llist* Ls = myalloc(sizeof(Llist),1);
	Ls->size = n;
	Ls->head = createElem(rand());
	Element* prev = Ls->head;
	for(int i=1; i<n; i++){
		Element* new = createElem(rand());
		prev->next = new;
		prev = prev->next;
	}
	Ls->tail = prev;
	FILE* f;
	f = fopen("output.txt", "w");
	fprintf(f, "Memory allocated : %d\n", memAlloc);
	fclose(f);
	return Ls;
}

Llist* createCycle(Llist* Ls){
	if (Ls->head == NULL){
		return Ls;
	}
	int toss = rand()%2;	
	printf("toss = %d\n",toss);
	if(toss == 0){
		return Ls;
	}
	int r = rand() % Ls->size;
	printf("r = %d\n", r);
	Element* e = Ls->head;
	for (int i=0; i<r; i++){
		e = e->next;
	}
	Ls->tail->next = e;
	return Ls;
}

Element* createElem(int k){
	Element* e = myalloc(sizeof(Element),1);
	e->key = k;
	e->next = NULL;
	return e;
}

/*void printList(Llist* Ls){
	printf("List: ");
	Element* e = Ls->head;
	while(e != Ls->tail){
		printf("%d ", e->key);
		e = e->next;
	}
	printf("%d\n", e->key);

	printf("%d %d\n", e->next->key, e->next->next->key);
}*/

Llist* makeCircularList(Llist* Ls){
	if(Ls->head == NULL){
		return Ls;
	}
	boolean test = testCyclic(Ls);
	if(test == 0){
		Ls->tail->next = Ls->head;
		return Ls;
	}
	Element* e  = Ls->tail->next;
	Element* node = Ls->head;
	while(node != e){
		Element* temp = node->next;
		myfree(node);
		node = temp;
		Ls->size -= 1;
	}
	Ls->head = e;
	return Ls;
}
