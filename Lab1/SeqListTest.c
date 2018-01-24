#include "SeqListUses.h"

int main(){
	SeqList* sl1 = newList();
	Element* node1 = (Element*)malloc(sizeof(Element));
	node1->key = 1;
	sl1 = insertInOrder(sl1,node1);
	Element* node2 = (Element*)malloc(sizeof(Element));
	node2->key = 3;
	sl1 = insertInOrder(sl1,node2);
	SeqList* sl2 = newList();
	Element* node3 = (Element*)malloc(sizeof(Element));
	node3->key = 4;
	sl2 = insertInOrder(sl2,node3);
	Element* node4 = (Element*)malloc(sizeof(Element));
	node4->key = 2;
	sl2 = insertInOrder(sl2,node4);
	SeqList* sl = (SeqList*)malloc(sizeof(SeqList));
	sl = merge(sl1, sl2);
	printlist(sl);

	SeqList* sl3 = newList();
	Element* node5 = (Element*)malloc(sizeof(Element));
	node5->key = 1;
	sl3 = insertInOrder(sl3,node5);
	Element* node6 = (Element*)malloc(sizeof(Element));
	node6->key = 3;
	sl3 = insertInOrder(sl3,node6);
	Element* node7 = (Element*)malloc(sizeof(Element));
	node7->key = 4;
	sl3 = insertAtFront(sl3,node7);
	Element* node8 = (Element*)malloc(sizeof(Element));
	node8->key = 2;
	sl3 = insertAtEnd(sl3,node8);
	printf("Before sorting : ");
	printlist(sl3);
	sl3 = insertionSort(sl3);
	printf("After sorting : ");
	printlist(sl3);
}

void printlist(SeqList* sl){
	Element* node = sl->head;
	while(node!=NULL){
		printf("%d ", node->key);
		node = node->next;
	}
	printf("\n");
}
