#include "emp.h"

Employee* insertionSort(Employee* arr, int low, int high){
	int k = high;
	for(int i=low; i<high + 1; i++){
		Employee temp = arr[k];
		int j = low;
		while(arr[j].empID < arr[k].empID){
			j++;
		}
		if(j == k){
			k--;
			continue;
		}
		for(int x = k; x>j; x--){
			arr[x] = arr[x-1];
		}
		arr[j] = temp;
	}
	return arr;
}
