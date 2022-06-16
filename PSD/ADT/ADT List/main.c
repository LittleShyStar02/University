#include <stdio.h>
#include <conio.h>

#include "list.h"
#include "item.h"

int main(void)
{
    List l = newList();
    int n;
    printf("\nQuanti elementi vuoi inserire nella lista? ");
    scanf("%d",&n);
    l = inputList(n);
    outputList(l);
    getch();
    return 0;
}