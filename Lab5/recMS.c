#include "ex1.h"

Element* recMS(Element* Ls, int low, int high){
	if(low < high){
		int mid = (low + high)/2;
		Element* Ls1 = recMS(Ls, low, mid);
		Element* Ls2 = recMS(Ls, mid+1, high);
		Element* Ls3 = (Element*)malloc(sizeof(Element)*(high - low + 1));
		merge(Ls1, mid-low+1, Ls2, high-mid, Ls3);
		for(int i=low, j=0; i<=high, j<=(high-low); i++, j++){
			Ls[i] = Ls3[j];
		}
	}
	return Ls + low;
}
