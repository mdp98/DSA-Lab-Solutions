#include "hashtable.h"

HashT newHashT(){
	HashT t = (HashT)malloc(sizeof(struct hashtable));
	t->elemCount = 0;
	t->loadFactor = 0;
	t->insertionCost = 0;
	t->table = (Chain)malloc(sizeof(struct chain)*500);
	for(int i=0; i<500; i++){
		//t->table+i = (Chain)malloc(sizeof(struct chain));
		t->table[i].head = NULL;
		t->table[i].size = 0;
	}
	return t;
}

HashT insert(HashT t, char** book, int ind){
	char* str = book[ind];
	int tind = hashf(str, 1000003, 500);
	if(t->table[tind].size == 0){
		t->table[tind].head = (Node)malloc(sizeof(struct node));
		t->table[tind].head->key = ind;
		t->table[tind].head->next = NULL;
		t->table[tind].size++;
		t->elemCount++;
		t->loadFactor = t->elemCount / 500;
		return t;
	}
	Node n = t->table[tind].head;
	while(n->next!=NULL){
		n = n->next;
	}
	Node new = (Node)malloc(sizeof(struct node));
	new->key = ind;
	new->next = NULL;
	n->next = new;
	t->table[tind].size++;
	t->elemCount++;
	t->loadFactor = t->elemCount / 500;
	t->insertionCost++;
	return t;
}

int insertAll(HashT t, char** book){
	int i = 0;
	while(book[i] != '\0'){
		t = insert(t, book, i);
		i++;
	}
	return t->insertionCost;
}

int lookup(HashT t, char* str, char** book){
	int queryingCost = 0;
	int ind = hashf(str, 1000003, 500);
	if(t->table[ind].size == 0){
		return 0;
	}
	Node n = t->table[ind].head;
	while(n != NULL){
		int ans = strcmp(str, book[n->key]);
		queryingCost++;
		if(ans == 0){
			return queryingCost;
		}
		n = n->next;
	}
	return 0;
}

int lookupAll(HashT t, char** book, double m){
	int qCost = 0;
	int i = 0;
	while(book[i] != '\0'){
		i++;
	}
	int end = i*m;
	for(int i=0; i<end; i++){
		int cost = lookup(t, book[i], book);
		qCost += cost;
	}
	return qCost;
}
	
