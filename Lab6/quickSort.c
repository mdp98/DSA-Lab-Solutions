#include "emp.h"

Employee* quickSort(Employee* arr, int low, int high, int min){
	int stack[high-low+1];
	int top = -1;
	stack[++top] = low;
	stack[++top] = high;

	while(top>=0){
		high = stack[top--];
		low = stack[top--];
		if(high - low <= min){
			insertionSort(arr, low, high);
			continue;
		}
		int p = partition(arr, low, high);
		if(p-1 > low){
			stack[++top] = low;
			stack[++top] = p-1;
		}
		if(p+1 < high){
			stack[++top] = p+1;
			stack[++top] = high;
		}
		
	}
	return arr;
}

int partition(Employee* arr, int low, int high){
	int i = low-1;
	
	for(int j=low; j<high; j++){
		if(arr[j].empID <= arr[high].empID){
			i++;
			Employee temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	Employee temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	return i+1;
}
