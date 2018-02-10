#include "que.h"

int main(){
	Queue q = newQ();
	printf("Is queue empty? : %d\n", isEmptyQ(q));
	Element* node1 = (Element*)malloc(sizeof(Element));
	node1->key = 4;
	q = addQ(q,node1);
	Element* node2 = (Element*)malloc(sizeof(Element));
	node2->key = 1;
	q = addQ(q,node2);
	Element* node3 = (Element*)malloc(sizeof(Element));
	node3->key = 2;
	q = addQ(q,node3);

	printf("Is queue empty? : %d\n", isEmptyQ(q));
	q = delQ(q);
	Element* res = front(q);
	printf("Front Element: %d\n", res->key);
	printf("Length of Queue: %d\n", lengthQ(q));
	return 0;
}
