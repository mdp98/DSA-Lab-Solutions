#include <stdio.h>
#include <stdlib.h>

typedef struct employee{
	char name[11];
	long long int empID;
}Employee;

Employee* quickSort(Employee* arr, int low, int high, int min);
int partition(Employee* arr, int low, int high);
Employee* insertionSort(Employee* arr, int low, int high);
