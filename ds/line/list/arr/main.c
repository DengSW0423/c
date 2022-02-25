#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"

int main()
{
    sqlist *list = sqlist_create();
    sqlist *list1 = sqlist_create();
    if (list == NULL)
    {
        exit(1);
    }

    if (list1 == NULL)
    {
        exit(1);
    }

    int a = 1, b = 2, c = 3;

    sqlist_pushback(list, &a);
    sqlist_pushback(list, &b);
    sqlist_pushback(list, &c);

    sqlist_pushback(list1, &a);

    sqlist_union(list, list1);
    sqlist_print(list);

    sqlist_destroy(list);
    sqlist_destroy(list1);

    return 0;
}
