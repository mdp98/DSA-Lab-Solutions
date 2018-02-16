#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	char name[11];
	double cgpa;
}Element;

void merge(Element* Ls1, int sz1, Element* Ls2, int sz2, Element* Ls);
Element* recMS(Element* Ls, int low, int high);
Element* iterMS(Element* Ls, int n);
