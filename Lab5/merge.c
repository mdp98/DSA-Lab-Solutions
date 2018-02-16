#include "ex1.h"

void merge(Element* Ls1, int sz1, Element* Ls2, int sz2, Element* Ls){
	int i=0;
	int j=0;
	int k=0;

	while(j < sz1 && k < sz2){
		if(Ls1[j].cgpa <= Ls2[k].cgpa){
			Ls[i] = Ls1[j];
			i++;
			j++;
		}
		else{
			Ls[i] = Ls2[k];
			i++;
			k++;
		}
	}
	if(j == sz1){
		for(int m=k; m<sz2; m++){
			Ls[i] = Ls2[m];
			i++;
		}
	}
	if(k == sz2){
		for (int m=j; m<sz1; m++){
			Ls[i] = Ls1[m];
			i++;
		}
	}
}
