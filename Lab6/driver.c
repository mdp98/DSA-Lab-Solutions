#include "emp.h"

int main(){
	FILE* f;
	f = fopen("data.txt", "r");
	Employee* arr = (Employee*)malloc(sizeof(Employee));	
	int i=0;	
	while(!feof(f)){
		arr = realloc(arr, sizeof(Employee)*(i+1));
		fscanf(f, "%[a-z] %llu\n", &arr[i].name, &arr[i].empID);
		//printf("%s %llu\n", arr[i].name, arr[i].empID);
		i++;
	}
	fclose(f);
	printf("----------------------------------------------");
	arr = quickSort(arr, 0, i-1, 3);
	for(int j=0; j<i; j++){
		printf("%s %llu\n", arr[j].name, arr[j].empID);
	}
}
