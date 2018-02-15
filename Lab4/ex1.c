#include "ex1.h"

int main(){
	Record* arr = (Record*)malloc(sizeof(Record));
	FILE* f;
	f = fopen("10000", "r");
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
}
