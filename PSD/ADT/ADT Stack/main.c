#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "item.h"
#include "stack.h"

#define EXIT 4

int main(void)
{
    Stack s = newStack();
    Item item;
    int sel;
    do
    {
        system("cls");
        puts("Digita:");
        puts("  1. per inserire un elemento nello stack");
        puts("  2. per rimuovere un elemento dallo stack");
        puts("  3. per stampare lo stack");
        puts("  4. per uscire dal programma");
        printf("\n\nScegli un opzione: ");
        scanf("%d",&sel);
        switch(sel)
        {
            case 1:
              printf("Inserisci un elemento nello stack: ");
              input_item(&item);
              s = push(item,s);
              printf("\n\nHai inserito l'elemento %d",top(s));
              getch();
              break;
            case 2:
              item = top(s);
              s = pop(s);
              printf("Hai rimosso l'elemento %d",item);
              getch();
              break;
            case 3:
              outputStack(s);
              getch();
              break;
            case 4:
              break;
            default:
              puts("\nOpzione non valida");
              getch();
        }
    } 
    while (sel != EXIT);
    return 0;
}