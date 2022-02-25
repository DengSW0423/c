#include "list.h"

#include <stdlib.h>
#include <stdio.h>

node *list_create()
{
    node *list = malloc(sizeof(node));
    if (list != NULL)
    {
        list->next = NULL;
        list->data = 0; //count elements in the list.
    }
    
    return list;
}

void list_destroy(node *list)
{
    if (list == NULL)
        return;
    
    node *cur = list;
    node *next = cur->next;
    
    while (1)
    {
        free(cur);
        cur = next;
        if (cur == NULL)
            break;

        next = cur->next;
    }
}

int list_insert_at(node *list, int i, datatype *data)
{
    if (list == NULL || i <= 0 || i > list->data + 1)
        return -1;
    
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return -2;
    }

    new_node->data = *data;
    new_node->next = NULL;
    node *tmp = list;

    for (int j = 0; j < i - 1; j++)
    {
        tmp = tmp->next;
    }
    new_node->next = tmp->next;
    tmp->next = new_node;

    list->data++;
    return 0;
}

int list_pushback(node *list, datatype *data)
{
    if (list == NULL)
        return -1;

    return list_insert_at(list, list->data + 1, data);
}

int list_pushfront(node *list, datatype *data)
{
    if (list == NULL)
        return -1;

    return list_insert_at(list, 1, data);
}

int list_delete_at(node *list, int i, datatype *data)
{
    if (list == NULL || i <= 0 || i > list->data)
        return -1;
    
    node *pre = list;
    for (int j = 0; j < i - 1; j++)
    {
        pre = pre->next;
    }
    *data = (pre->next->data);
    node *tmp = pre->next;
    pre->next = pre->next->next;
    free(tmp);

    list->data--;

    return 0;
}

int list_delete(node *list, datatype *data) //return deleted number of data.
{
    if (list == NULL)
        return -1;

    int ret = 0;
    node *cur = list;
    while (cur->next != NULL)
    {
        if (cur->next->data == *data)
        {
            node *t = cur->next;
            cur->next = cur->next->next;
            free(t);
            ret++;
        }
        else
        {
            cur = cur->next;
        }
    }
    
    list->data -= ret;
    return ret;
}

bool list_isempty(node *list)
{
    return !list->data;
}

void list_print(node *list)
{
    node *cur = list->next;

    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
