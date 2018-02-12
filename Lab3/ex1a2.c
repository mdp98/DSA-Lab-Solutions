#include <stdio.h>
#include <stdlib.h>

int bits = 2000;

void p(int n){
	int pilani = 1;
	printf("Pilani has address : %u\n", &pilani);
	g(1);
}

void g(int n){
	int goa = 2;
	printf("Goa has address : %u\n", &goa);
	h(1);
}

void h(int n){
	int hyd = 3;
	printf("Hyd has address : %u\n", &hyd);
	d(1);
}

void d(int n){
	int dub = 4;
	printf("Dub has address : %u\n", &dub);
}

int main(){
	p(1);
	printf("Bits has address : %u\n", &bits);
}
