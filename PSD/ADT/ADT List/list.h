#include "item.h"

typedef struct node *List;

List cloneList(List l);
List consList(Item item,List l);
int emptyList(List l);
Item getFirst(List l);
Item getItem(List l,int pos);
List inputList(int n);
List insertList(List l,int pos,Item item);
List newList(void);
void outputList(List l);
int posItem(List l,Item item);
List removeList(List l,int pos);
List reverseList(List l);
int sizeList(List l);
List tailList(List l);