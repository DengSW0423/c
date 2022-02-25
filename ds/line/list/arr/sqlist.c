#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"

sqlist *sqlist_create()
{
    sqlist *p = malloc(sizeof(sqlist));
    if (p != NULL)
    {
        p->last = -1;
    }

    return p;
}

void sqlist_create1(sqlist **listp)
{
    *listp = malloc(sizeof(sqlist));
    if (*listp != NULL)
    {
        (*listp)->last = -1;
    }
}

int sqlist_insert(sqlist *list, int i, datatype *data)
{
    if (list == NULL || sqlist_isfull(list) || i < 0 || i > list->last + 1)
        return -1;

    for (int j = list->last + 1; j >= i + 1; j--)
    {
        list->data[j] = list->data[j - 1];
    }
    list->data[i] = *data;
    list->last++;

    return 0;
}

int sqlist_pushback(sqlist *list, datatype *data)
{
    return sqlist_insert(list, list->last + 1, data);
}

int sqlist_delete(sqlist *list, int j)
{
    if (list == NULL || j < 0 || j > list->last)
        return -1;

    for (int i = j + 1; i <= list->last; i++)
    {
        list->data[i - 1] = list->data[i];
    }
    list->last--;

    return 0;
}

int sqlist_find(const sqlist *list, datatype *data)
{
    if (list == NULL)
        return -1;

    int ret = -1;
    for (int i = 0; i < sqlist_getnum(list); i++)
    {
        if (list->data[i] == *data)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int sqlist_isempty(const sqlist *list)
{
    return (list->last >= 0) ? 1 : 0;
}

int sqlist_isfull(const sqlist *list)
{
    return (list->last == SIZE - 1) ? 1 : 0;
}

int sqlist_getnum(const sqlist *list)
{
    return list->last + 1;
}

void sqlist_destroy(sqlist *listp)
{
    free(listp);
}

int sqlist_union(sqlist *list1, const sqlist *list2)
{
    if (list1 == NULL || list2 == NULL || sqlist_getnum(list1) + sqlist_getnum(list2) > SIZE)
        return -1;

    for (int i = list1->last + 1, j = 0; i <= list1->last + list2->last + 1; i++, j++)
    {
        list1->data[i] = list2->data[j];
    }

    list1->last += sqlist_getnum(list2);

    return 0;
}

void sqlist_print(const sqlist *list)
{
    for (int i = 0; i < sqlist_getnum(list); i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}
