#include "item.h"

typedef struct c_queue *Queue;

Queue newQueue(void);
int emptyQueue(Queue q);
Item dequeue(Queue q);
int enqueue(Item item,Queue q);
void outputQueue(Queue q);