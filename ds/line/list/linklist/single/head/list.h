#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef int datatype;

typedef struct node_st
{
    datatype data;
    struct node_st *next;
} node;

node *list_create();

void list_destroy(node *list);

int list_insert_at(node *list, int i, datatype *data);

int list_pushback(node *list, datatype *data);

int list_pushfront(node *list, datatype *data);

int list_delete_at(node *list, int i, datatype *data);

int list_delete(node *list, datatype *data); //return deleted number of data.

bool list_isempty(node *list);

void list_print(node *list);

#endif