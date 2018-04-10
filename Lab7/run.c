#include "hash.h"
#include "hashtable.h"

int main(){
	char** book = parse("aliceinwonderland.txt");
	int baseNum[6] = {97, 89, 83, 1000003, 1000033, 1000037};
	int tableSize[3] = {50, 100, 500};
	int* ans = profiling(book, baseNum, tableSize);
	printf("Minimum collisions : %d are given by base number : %d and table size : %d\n", ans[2], ans[0], ans[1]);

	HashT t = newHashT();
	int iCost = insertAll(t, book);
	printf("Insertion Cost in HashTable is : %d\n", iCost);
	/*int i = 0;
	for(int i=0; i<500; i++){
		printf("%d --- ", i);
		Node n = t->table[i].head;
		while(n->next != NULL){
			printf("%d -> ", n->key);
			n = n->next;
		}
		printf("%d\n", n->key);
	}*/
	char* str = book[9390];
	printf("Querying cost of finding '%s' in book is : %d\n", str, lookup(t, str, book));

	double m = 0.1;
	int qCost = 0;
	while(qCost < iCost && m <= 2.0){
		qCost = lookupAll(t, book, m);
		//printf("%d\t", qCost);
		m += 0.1;
	}
	printf("The percentage at which queryingCost overtook insertionCost is %0.1f%\n", (m-0.1)*100);
}
