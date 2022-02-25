#include "list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


LIST *list_create(int data_size)
{
    LIST *list = malloc(sizeof(LIST));

    if (list != NULL)
    {
        list->head.data = NULL;
        list->head.prev = &list->head;
        list->head.next = &list->head;
        list->size = data_size;
    }

    return list;
}

void list_destroy(LIST *list)
{
    if (list == NULL)
        return;

    node *cur = list->head.next;
    while (cur != &list->head)
    {
        node *t = cur;
        cur = cur->next;
        free(t->data);
        free(t);
    }
    
    free(list);
}

int list_insert(LIST *list, void *data, int mode)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
        return -1;
        
    new_node->data = malloc(list->size);
    if (new_node->data == NULL)
    {
        free(new_node);
        return -2;
    }

    memcpy(new_node->data, data, list->size);

    if (mode == HEAD)
    {
        new_node->next = list->head.next;
        new_node->next->prev = new_node;
        new_node->prev = &list->head;
        new_node->prev->next = new_node;

        return 0;
    }

    if (mode == TAIL)
    {        
        new_node->prev = list->head.prev;
        new_node->prev->next = new_node;
        new_node->next = &list->head;
        new_node->next->prev = new_node;

        return 0;
    }

    fprintf(stderr, "error mode\n");
    exit(1);
}

void list_print(LIST *list, op *print)
{
    node *cur = list->head.next;
    while (cur != &list->head)
    {
        print(cur->data);
        cur = cur->next;
    }
}

static node *find_node(LIST *list, const void *key, cmp *compare)
{
    node *cur = list->head.next;
    while (cur != &list->head)
    {
        if (compare(key, cur->data) == 0)
            break;

        cur = cur->next;
    }

    return cur;
}

void *list_find(LIST *list, const void *key, cmp *compare)
{
    return find_node(list, key, compare)->data;
}

void list_delete(LIST *list, const void *key, cmp *compare)
{
    node *n = find_node(list, key, compare);
    if (n == &list->head)
        return;
    
    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n->data);
    free(n);
}

LIST *list_fetch(LIST *list, const void *key, cmp *compare)
{
    node *n = find_node(list, key, compare);
    if (n == &list->head)
        return NULL;

    LIST *new_list = list_create(list->size); 

    node *cur = n;
    while (cur != &list->head)
    {
        list_insert(new_list, cur->data, TAIL);
        cur = cur->next;
    }

    return new_list;
}