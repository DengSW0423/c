#ifndef LIST_H
#define LIST_H

#define HEAD    0
#define TAIL    1

typedef void op(const void *);

typedef int cmp(const void *, const void *);

typedef struct node_st
{
    struct node_st *prev;
    struct node_st *next;
    void *data;
} node;

typedef struct
{
    int size;
    node head;
} LIST;


LIST *list_create(int data_size);

void list_destroy(LIST *list);

int list_insert(LIST *list, void *data, int mode);

void list_print(LIST *list, op *print);

/**
 * return NULL, if not found; else return the first data meets the key.
 */
void *list_find(LIST *list, const void *key, cmp *compare);

void list_delete(LIST *list, const void *key, cmp *compare);

LIST *list_fetch(LIST *list, const void *key, cmp *compare);

#endif
