#include <stdio.h>
#include <stdlib.h>

int bits = 2000;

void p(int n){
	int pilani = 1;
	printf("Pilani has address : %u\n", &pilani);
}

void g(int n){
	int goa = 2;
	printf("Goa has address : %u\n", &goa);
}

void h(int n){
	int hyd = 3;
	printf("Hyd has address : %u\n", &hyd);
}

void d(int n){
	int dub = 4;
	printf("Dub has address : %u\n", &dub);
}

int main(){
	p(1);
	g(1);
	h(1);
	d(1);
	printf("Bits has address : %u\n", &bits);
}
