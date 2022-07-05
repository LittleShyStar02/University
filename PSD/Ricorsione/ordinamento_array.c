#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
	int app = *a;
	*a = *b;
	*b = app;
}

void ordina(int vet[],int len,int count)
{
	if(len < 1 || count >= len) return;
	if((count+1) == len) ordina(vet,len-1,0);
	if(vet[count] > vet[len-1]) swap(&vet[count],&vet[len-1]);
	ordina(vet,len,count+1);
}

int main(void)
{
	int len = 10,x=0;
	int vet[len];
	vet[0] = 7;
	vet[1] = 5;
	vet[2] = 1;
	vet[3] = 8;
	vet[4] = 3;
	vet[5] = 0;
	vet[6] = 4;
	vet[7] = 9;
	vet[8] = 2;
	vet[9] = 6;
	ordina(vet,len,0);
	for(x = 0;x < len;x++) printf("%d ",vet[x]);
}
