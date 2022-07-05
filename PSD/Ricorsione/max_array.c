#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
	if(a > b) return a;
	return b;
}

int maxA(int a[],int len,int m)
{
	if(len == 0) return a[0];
	return max(m,maxA(a,len-1,a[len-1]));
}

int main(void)
{
	//maxA l'elemento max in un array
}
