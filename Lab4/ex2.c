#include "ex2.h"

Record* insertInOrder(Record* arr, Record r, int size){
	if(arr == NULL){
		arr[0] = r;
		return arr;
	}
	int i=0; 
	while(arr[i].cardNo <= r.cardNo && i<size){
		i++;
	}
	for(int j=size-1; j>=i; j--){
		arr[j+1] = arr[j];
	}
	arr[i] = r;
	return arr;
}

Record* insertionSort(Record* arr, int size){
	if(size==1){
		return arr;
	}
	arr = insertionSort(arr,size-1);
	Record r = arr[size-1];
	arr = insertInOrder(arr, r, size-1);
	return arr;
}

int main(){
	Record* arr = (Record*)malloc(sizeof(Record));
	FILE* f;
	f = fopen("10", "r");
	if (f == NULL){
		return NULL;
	}
	int i = 0;
	
	struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);
	while (!feof(f)){
		arr = realloc(arr, sizeof(Record)*(i+1));
		fscanf(f, "\"%llu,%[^,],%[^,],%[^,],%[^\"]\"\n", &arr[i].cardNo, &arr[i].bankCode, &arr[i].expDate, &arr[i].firstName, &arr[i].lastName);
		//printf("%d %llu %s %s %s %s\n", i, arr[i].cardNo, arr[i].bankCode, arr[i].expDate, arr[i].firstName, arr[i].lastName);
		i = i+1;
	}
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	fclose(f);	
	
	f = fopen("time.txt", "w");
	fprintf(f, "Elapsed time is : %f ms", elapsedTime);
	fclose(f);

	gettimeofday(&t1, NULL);
	arr = insertionSort(arr, 10);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Elapsed time is : %f ms\n", elapsedTime);
	for (int i=0; i<10; i++){
		printf("%llu %s %s %s %s\n", arr[i].cardNo, arr[i].bankCode, arr[i].expDate, arr[i].firstName, arr[i].lastName);
	}
}
