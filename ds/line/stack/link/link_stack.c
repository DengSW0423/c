#include "link_stack.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

link_stack ls_create(size_t datasize)
{
    link_stack s = malloc(sizeof *s + sizeof(size_t));
    if (s != NULL)
    {
        s->next = NULL;
        DATASIZE(s) = datasize;
    }

    return s;
}

void ls_destroy(link_stack s)
{
    node *cur = s;
    node *next = s->next;

    while (cur != NULL)
    {
        free(cur);
        cur = next;
        if (cur == NULL)
            break;
        next = cur->next;
    }
}

int ls_push(link_stack s, void *d)
{
    node *new_node = malloc(sizeof *new_node + DATASIZE(s));
    if (new_node == NULL)
    {
        printf("create new node failed!\n");
        return -1;
    }

    new_node->next = s->next;
    s->next = new_node;
    memcpy(new_node->data, d, DATASIZE(s));

    return 0;
}

int ls_pop(link_stack s, void *d)
{
    if (ls_isempty(s))
    {
        printf("stack is empty! Can't pop\n");
        return -1;
    }

    memcpy(d, s->next->data, DATASIZE(s));
    
    node *n = s->next;
    s->next = s->next->next;

    free(n);
    return 0;
}

int ls_top(link_stack s, void *d)
{
    if (ls_isempty(s))
    {
        printf("stack is empty, can't get top!\n");
        return -1;
    }
    memcpy(d, s->next->data, DATASIZE(s));

    return 0;
}

void ls_print(link_stack s, void (*print)(void *d))
{
    node *n = s->next;
    while (n != NULL)
    {
        print(n->data);
        n = n->next;
    }
}

int ls_isempty(link_stack s)
{
    return s->next == NULL;
}
