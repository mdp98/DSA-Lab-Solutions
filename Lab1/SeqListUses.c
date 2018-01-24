#include "SeqListUses.h"

SeqList* merge(SeqList* sl1, SeqList* sl2){
	Element* node = sl2->head;
	while(node != NULL){
		Element* temp = node;
		node = node->next;
		sl1 = insertInOrder(sl1, temp);
	}
	return sl1;
}

SeqList* insertionSort(SeqList* sl){
	if(sl->head == NULL){
		return sl;
	}
	Element* node = sl->head;
	while(node != NULL){
		Element* temp = node;
		node = node->next;
		sl = del(sl, temp);
		sl = insertInOrder(sl, temp);
	}
	return sl;
}
