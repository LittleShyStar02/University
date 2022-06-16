#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "list.h"

struct node
{
    Item item;
    struct node *next;
};

List cloneList(List l)
{
    List nl = newList();

    while(!emptyList(l))
    {
        nl = consList(getFirst(l),nl);
    }
    return reverseList(nl);
}

List consList(Item item,List l)
{
    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));
    nuovo->item=item;
    if(!emptyList(l)) nuovo->next = l;
    else nuovo->next = NULL;
    return nuovo;
}

int emptyList(List l)
{
    return (l==NULL);
}

Item getFirst(List l)
{
    if(emptyList(l)) return NULLITEM;
    return l->item;
}

Item getItem(List l,int pos)
{
    int i = 0;
    while(i< pos && !emptyList(l))
    {
        i++;
        l = tailList(l);
    }

    if(emptyList(l)) return NULLITEM;
    return getFirst(l);
}

List inputList(int n)
{
    List l = newList();
    Item item;

    for(int x = 0;x < n;x++)
    {
        printf("Elemento di posizione %d: ",x+1);
        input_item(&item);
        l = consList(item,l);
    }
    return reverseList(l);
}

List insertNode(List l,int pos,Item item)
{
    if(pos==0)
    {
        return consList(item,l);
    }

    int i = 0;
    List prec = l;
    while(i < pos-1 && prec != NULL)
    {
        prec = prec->next;
        i++;
    }

    if(prec == NULL) return l;
    List l1 = consList(item,prec->next);
    prec->next = l1;
    return l;
}

List insertList(List l,int pos,Item item)
{
    return insertNode(l,pos,item);
}

List newList(void)
{
    return NULL;
}

void outputList(List l)
{
    int i = 0;
    while(!emptyList(l))
    {
        printf("Elemento di posizione %d: ",i+1);
        output_item(getFirst(l));
        printf("\n");
        l = tailList(l);
        i++;
    }
}

int posItem(List l,Item item)
{
    int pos = 0;
    int found = 0;

    while(!emptyList(l) && !found)
    {
        if(items_equals(getFirst(l),item)) found = 1;
        else
        {
            pos++;
            l = tailList(l);
        }
    }

    if(!found) pos = -1;
    return pos;
}

List removeNode(List l,int pos)
{
    List l1;
    if(pos == 0 && !emptyList(l))
    {
        l1 = l;
        l = tailList(l);
        free(l1);
    }
    else
    {
        int i = 0;
        List prec = l;
        while(i < pos-1 && prec != NULL)
        {
            prec = prec->next;
            i++;
        }

        if(prec != NULL && prec->next != NULL)
        {
            l1 = prec->next;
            prec->next = l1->next;
            free(l1);
        }

        return l;
    }
}

List removeList(List l,int pos)
{
    return removeNode(l,pos);
}

List reverseList(List l)
{
    List l1 = newList();

    while(!emptyList(l))
    {
        l1 = consList(getFirst(l),l1);
        l = tailList(l);
    }
    return l1;
}

int sizeList(List l)
{
    int n = 0;
    while(!emptyList(l))
    {
        n++;
        l=tailList(l);
    }
    return n;
}

List tailList(List l)
{
    if(emptyList(l)) return newList();
    return l->next;
}