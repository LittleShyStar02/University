#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int addizione(int n1,int n2)
{
	if(n2==0) return n1;
	return 1 + addizione(n1,n2-1);
}

int sottrazione(int n1,int n2)
{
	if(n2==0) return n1;
	return -1 + sottrazione(n1,n2-1);
}

int moltiplicazione(int n1,int n2)
{
	if (n2 == 0) return 0;
    return n1 + moltiplicazione(n1,n2-1);
}

int divisione(int n1,int n2)
{
	if(n1 == 0) return 0;
	if(n2 > n1) return 0;
	return 1 + divisione(n1-n2,n2);
}

int modulo(int n1,int n2)
{
	if(n1 == 0) return 0;
	if(n2 > n1) return n1;
	return modulo(n1-n2,n2);
}

int main(void)
{
	int one=0,two=0;
	int sel;
	do
	{
		system("cls");
		puts("Digita: ");
		puts("  1. per modificare il valore del primo numero");
		puts("  2. per modificare il valore del secondo numero");
		puts("  3. per eseguire un'addizione tra i due numeri");
		puts("  4. per eseguire una sottrazione tra i due numeri");
		puts("  5. per eseguire una moltiplicazione tra i due numeri");
		puts("  6. per eseguire una divisione tra i due numeri");
		puts("  7. per eseguire il modulo tra i due numeri");
		puts("  8. per uscire dal programma");
		printf("\n\n Primo numero: %d",one);
		printf("\n\n Secondo numeri: %d",two);
		printf("\n\n Scegli un ozpione: ");
		scanf("%d",&sel);
		switch(sel)
		{
			case 1:
				printf("\nInserisci il primo numero: ");
				scanf("%d",&one);
				break;
			case 2:
				printf("\nInserisci il secondo numero: ");
				scanf("%d",&two);
				break;
			case 3:
				printf("\n%d + %d = %d",one,two,addizione(one,two));
				break;
			case 4:
				if(one > two)
				{
					printf("\n%d - %d = %d",one,two,sottrazione(one,two));
				}
				else
				{
					printf("\nImpossibile eseguire la sottrazione. %d < %d",one,two);
				}
				break;
			case 5:
				printf("\n%d * %d = %d",one,two,moltiplicazione(one,two));
				break;
			case 6:
				printf("\n%d / %d = %d",one,two,divisione(one,two));
				break;
			case 7:
				printf("\n%d mod %d = %d",one,two,modulo(one,two));
				break;
			case 8:
				break;
			default:
				puts("\nOpzione non valida");
		}
		if(sel > 0 && sel < 8)
		{
			puts("\n\nPremi un tasto per continuare...");
			getch();
		}
	}while(sel != 8);
	return 0;
}
