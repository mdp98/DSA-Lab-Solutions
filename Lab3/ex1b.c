#include <stdio.h>
#include <stdlib.h>

int bits = 2000;

void p(int n){
	int pilani = n;
	printf("%d : Pilani has address : %u\n",pilani, &pilani);
	if(pilani < bits){
		p(n+1);
	}
}

int main(){
	p(1);
}
