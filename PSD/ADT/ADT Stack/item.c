#include <stdio.h>

#include "item.h"

int items_equals(Item i1,Item i2)
{
    return (i1==i2);
}

void input_item(Item *item)
{
    scanf("%d",item);
}

void output_item(Item item)
{
    printf("%d",item);
}