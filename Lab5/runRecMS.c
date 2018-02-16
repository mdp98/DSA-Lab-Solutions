#include "ex1.h"

int main(){
	Element* Ls = (Element*)malloc(sizeof(Element));
	FILE* f;
	f = fopen("1024.txt","r");
	if(f==NULL){
		return NULL;
	}
	int i = 0;
	while(!feof(f)){
		Ls = realloc(Ls,sizeof(Element)*(i+1));
		fscanf(f, "%[a-z],%lf\n", &Ls[i].name, &Ls[i].cgpa);
		//printf("%s %f\n", Ls[i].name, Ls[i].cgpa);
		i++;
	}
	fclose(f);
	
	struct timeval t1,t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);
	Ls = recMS(Ls, 0, i-1);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec)/1000.0;
	printf("Elapsed Time in sorting : %f ms\n", elapsedTime);
}
