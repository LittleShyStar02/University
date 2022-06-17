#include "item.h"

typedef struct node *Stack;

Stack newStack(void);
int emptyStack(Stack s);
Stack pop(Stack s);
Stack push(Item item,Stack s);
Item top(Stack s);
void outputStack(Stack s);