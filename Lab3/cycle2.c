#include "cycle.h"

boolean testCyclic(Llist* Ls){
	if(Ls->head == NULL){
		return FALSE;
	}
	Element* prev = Ls->head;
	Element* temp = Ls->head;
	Element* node = Ls->head;
	if(node->next == NULL){
		return FALSE;
	}
	node = node->next;
	while(node->next != NULL){
		temp = node;
		if(node->next == NULL){
			break;
		}
		node = node->next;
		temp->next = prev;
		prev = temp;
		if(node == Ls->head){
			return TRUE;
		}
	}
	return FALSE;
}
