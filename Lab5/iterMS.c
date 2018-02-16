#include "ex1.h"

Element* iterMS(Element* Ls, int n){
	int currSize;
	int low;

	for(currSize = 1; currSize <= n-1; currSize = currSize*2){
		for (low = 0; low < n-1; low = low + 2*currSize){
			Element* Ls1 = Ls + low;
			int mid = low + currSize - 1;
			Element* Ls2 = Ls + mid + 1;
			int high = (low + 2*currSize - 1)<(n-1) ? low + 2*currSize - 1 : n-1;
			Element* Ls3 = (Element*)malloc(sizeof(Element)*(high-low+1));
			merge(Ls1,mid-low+1,Ls2,high-mid,Ls3);

			for(int i=low, j=0; i<=high, j<=high-low; i++, j++){
				Ls[i] = Ls3[j];
			}
		}
	}
	return Ls;
}
