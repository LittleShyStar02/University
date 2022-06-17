#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "stack.h"

struct node
{
    Item item;
    struct node *next;
};

Stack newStack()
{
    return NULL;
}

int emptyStack(Stack s)
{
    return (s==NULL);
}

Stack pop(Stack s)
{
    if(emptyStack(s)) return NULL;
    Stack s1;
    s1 = s;
    s = s->next;
    free(s1);
    return s;
}

Stack push(Item item,Stack s)
{
    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));
    nuovo->item=item;
    if(!emptyStack(s)) nuovo->next = s;
    else nuovo->next = NULL;
    return nuovo;
}

Item top(Stack s)
{
    if(emptyStack(s)) return NULLITEM;
    return s->item;
}

void outputStack(Stack s)
{
    while(!emptyStack(s))
    {
        output_item(s->item);
        s = s->next;
    }
}