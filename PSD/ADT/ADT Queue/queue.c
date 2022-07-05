#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "queue.h"

struct node
{
    Item value;
    struct node *next;
};

struct c_queue
{
    struct node *head,*tail;
    int size;
};

Queue newQueue(void)
{
    struct c_queue *q;
    q = malloc(sizeof(struct c_queue));
    if(q == NULL) return NULL;
    q->size = 0;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

int emptyQueue(Queue q)
{
    if(q == NULL) return -1;
    return q->size == 0;
}

int enqueue(Item item,Queue q)
{
    if(q == NULL) return -1;

    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));
    if(nuovo == NULL) return 0;
    nuovo->value = item;
    nuovo->next = NULL;

    if(q->head == NULL) q->head = nuovo;
    else q->tail->next = nuovo;

    q->tail = nuovo;
    (q->size)++;
    return 1;
}

Item dequeue(Queue q)
{
    if(q == NULL || q->size == 0) return NULLITEM;
    
    Item result;
    struct node *tmp;
    tmp = q->head;
    result = tmp->value;
    q->head = q->head->next;
    free(tmp);
    (q->size)--;
    return result;
}

void outputQueue(Queue q)
{
    if(emptyQueue(q)) return;

    struct node *Node = q->head;
    while(Node != NULL)
    {
        output_item(Node->value);
        Node = Node->next;
    }
}