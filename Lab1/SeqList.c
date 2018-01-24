#include "SeqList.h"

SeqList* newList(){
	SeqList* sl = (SeqList*)malloc(sizeof(SeqList));
	sl->head = NULL;
	sl->tail = NULL;
	return sl;
}

SeqList* insertInOrder(SeqList* sl, Element* e){
	if(sl->head == NULL){
		sl->head = e;
		sl->tail = e;
		e->next = NULL;
		return sl;
	}
	if(sl->head->key > e->key){
		e->next = sl->head;
		sl->head = e;
		return sl;
	}
	Element* node = sl->head;
	Element* prev = sl->head;
	while((node->key < e->key) && (node->next!=NULL)){
		prev = node;
		node = node->next;
	}
	if(node->next == NULL){
		if(node->key < e->key){
			node->next = e;
			e->next = NULL;
			sl->tail = e;
			return sl;		
		}
	}
	prev->next = e;
	e->next = node;
	return sl;
}

SeqList* insertAtFront(SeqList* sl, Element* e){
	if(sl->head == NULL){
		sl->head = e;
		sl->tail = e;
		e->next = NULL;
		return sl;
	}
	e->next = sl->head;
	sl->head = e;
	return sl;
}

SeqList* insertAtEnd(SeqList* sl, Element* e){
	if(sl->head == NULL){
		sl->head = e;
		sl->tail = e;
		e->next = NULL;
		return sl;
	}
	sl->tail->next = e;
	e->next = NULL;
	sl->tail = e;
	return sl;
}

SeqList* del(SeqList* sl, Element* e){
	if(sl->head == NULL){
		return sl;
	}
	if(sl->head->key == e->key){
		sl->head = sl->head->next;
		if(sl->head == NULL){
			sl->tail = NULL;
		}
		return sl;
	}
	Element* node = sl->head;
	Element* prev = node;
	while(node->next!=NULL){
		if(node->key != e->key){
			prev = node;
			node = node->next;
			continue;
		}
		prev->next = node->next;
		return sl;
	}
	if(node->key == e->key){
		prev->next = NULL;
		sl->tail = prev;
	}
	return sl;
}

SeqList* deleteAtFront(SeqList* sl){
	if(sl->head == NULL){
		return sl;
	}
	sl->head = sl->head->next;
	if(sl->head == NULL){
		sl->tail = NULL;
	}
	return sl;
}

Element* find(SeqList* sl, int k){
	Element* node = sl->head;
	while(node != NULL){
		if(node->key != k){
			node = node->next;
			continue;
		}
		break;
	}
	return node;
}
