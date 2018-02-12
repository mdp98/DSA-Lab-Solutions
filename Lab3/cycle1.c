#include "cycle.h"

boolean testCyclic(Llist* Ls){
	if(Ls->head == NULL){
		return FALSE;
	}
	Element* hare = Ls->head;
	Element* tort = Ls->head;
	while(hare->next != NULL){
		if(hare->next->next == NULL){
			break;
		}
		hare = hare->next->next;
		tort = tort->next;
		
		if(hare == tort || hare->next == tort){
			return TRUE;
		}
	}
	return FALSE;
}
