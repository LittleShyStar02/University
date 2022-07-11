#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
	if(a > b) return a;
	return b;
}

int maxA(int a[],int len)
{
	if(len == 1) return a[0];
	return max(a[len-1],maxA(a,len-1));
}

int main(void)
{
	//maxA l'elemento max in un array
}
