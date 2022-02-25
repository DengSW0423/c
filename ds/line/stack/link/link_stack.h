#ifndef LINK_STACK_H
#define LINK_STACK_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

// 获取数据的大小
#define DATASIZE(head) ( *(size_t *)(head)->data )

typedef struct node
{
    struct node *next;
    char data[0];
} node, *link_stack;

link_stack ls_create(size_t datasize);

void ls_destroy(link_stack s);

int ls_push(link_stack s, void *d);

int ls_pop(link_stack s, void *d);

int ls_top(link_stack s, void *d);

void ls_print(link_stack s, void (*print)(void *d));

int ls_isempty(link_stack s);

#endif
