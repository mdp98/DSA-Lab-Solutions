#include "hash.h"

int hashf(char* str, int baseNum, int tableSize){
	int sum = 0;
	int i=0;
	while(str[i] != '\0'){
		sum += str[i];
		i++;
	}
	sum = sum % baseNum;
	sum = sum % tableSize;
	return sum;
}

int colCount(char** arr, int baseNum, int tableSize){
	int table[tableSize];
	int count = 0;
	int i = 0;
	while(arr[i] != '\0'){
		int h = hashf(arr[i], baseNum, tableSize);
		if(table[h] == 1){
			count++;
		}
		else{
			table[h] = 1;
		}
		i++;
	}
	return count;
}

char** parse(char* file){
	char** book = (char**)malloc(sizeof(char*)*1000);
	int size = 1000;
	int num = 0;
	
	FILE* f = fopen(file, "r");
	if(f == NULL){
		return NULL;
	}
	while(!feof(f)){
		int check = 0;
		char buff[100000];
		fscanf(f, "%s", buff);
		int i=0;
		while(i != strlen(buff)){
			if(isalpha(buff[i])){
				i++;
			}
			else{
				check = 1;
				break;
			}
		}
		if(check == 0){
			book[num] = (char*)malloc(sizeof(char)*strlen(buff));
			strcpy(book[num],buff);
			num++;
			if(num == size){
				size += size;
				book = (char**)realloc(book, sizeof(char*)*size);
			}
		}
	}
	printf("The number of valid strings is %d.\n", num-1);
	book[num] = '\0';
	return book;
}

int* profiling(char** book, int* baseNum, int* tableSize){
	int* ans = (int*)malloc(sizeof(int)*3);	
	int minBase;
	int minTable;
	int minCol = 1000000;
	for(int i=0; i<6; i++){
		for(int j=0; j<3; j++){
			int col = colCount(book, baseNum[i], tableSize[j]);
			printf("%d %d %d\n", col, baseNum[i], tableSize[j]);
			if(col < minCol){
				minCol = col;
				minBase = baseNum[i];
				minTable = tableSize[j];
			}				
		}
	}
	ans[0] = minBase;
	ans[1] = minTable;
	ans[2] = minCol;	
	return ans;
}

/**
int main(){
	char** book = parse("aliceinwonderland.txt");
	int baseNum[6] = {97, 89, 83, 1000003, 1000033, 1000037};
	int tableSize[3] = {50, 100, 500};
	int* ans = profiling(book, baseNum, tableSize);
	printf("Minimum collisions : %d are given by base number : %d and table size : %d\n", ans[2], ans[0], ans[1]);
}
**/
