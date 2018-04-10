#include "hash.h"

struct hashtable{
	struct chain* table;
	int elemCount;
	int loadFactor;
	int insertionCost;
};

struct node{
	int key;
	struct node* next;
};

struct chain{
	struct node* head;
	int size;
};

typedef struct hashtable* HashT;
typedef struct node* Node;
typedef struct chain* Chain;

HashT newHashT();
HashT insert(HashT t, char** book, int ind);
int insertAll(HashT t, char** book);
int lookupAll(HashT t, char** book, double m);
