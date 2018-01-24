#include "SeqList.h"

int main(){
	SeqList* sl = newList();
	Element* node1 = (Element*)malloc(sizeof(Element));
	node1->key = 1;
	sl = insertInOrder(sl,node1);
	Element* node2 = (Element*)malloc(sizeof(Element));
	node2->key = 3;
	sl = insertInOrder(sl,node2);
	Element* node3 = (Element*)malloc(sizeof(Element));
	node3->key = 4;
	sl = insertAtFront(sl,node3);
	Element* node4 = (Element*)malloc(sizeof(Element));
	node4->key = 2;
	sl = insertAtEnd(sl,node4);
	printlist(sl);
	sl = del(sl, node2);
	printlist(sl);
	sl = deleteAtFront(sl);
	printlist(sl);
	Element* findel = (Element*)malloc(sizeof(Element));
	findel = find(sl,1);
	printf("The list has element %d.", findel->key);
}

void printlist(SeqList* sl){
	Element* node = sl->head;
	while(node!=NULL){
		printf("%d ", node->key);
		node = node->next;
	}
	printf("\n");
}
