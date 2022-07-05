#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "item.h"
#include "queue.h"

#define EXIT 4

int main(void)
{
  Queue q = newQueue();
  Item item;
  int sel;
  do
  {
    system("cls");
    puts("Digita:");
    puts("  1. per inserire un elemento nella coda");
    puts("  2. per rimuovere un elemento dalla coda");
    puts("  3. per stampare la coda");
    puts("  4. per uscire dal programma");
    printf("\n\nScegli un opzione: ");
    scanf("%d",&sel);
    switch(sel)
    {
      case 1:
        printf("Inserisci un elemento nella coda: ");
        input_item(&item);
        enqueue(item,q);
        printf("\n\nHai inserito l'elemento %d",item);
        getch();
        break;
      case 2:
        item = dequeue(q);
        printf("Hai rimosso l'elemento %d",item);
        getch();
        break;
      case 3:
        outputQueue(q);
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