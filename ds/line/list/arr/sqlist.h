#ifndef SQLIST_H
#define SQLIST_H

#define SIZE 64
typedef int datatype;

typedef struct sqlist
{
    datatype data[SIZE];
    int last;
} sqlist;

sqlist *sqlist_create();

void sqlist_create1(sqlist **);

int sqlist_insert(sqlist *, int i, datatype *);

int sqlist_pushback(sqlist *, datatype *);

int sqlist_delete(sqlist *, int i);

int sqlist_find(const sqlist *, datatype *);

int sqlist_isempty(const sqlist *);

int sqlist_isfull(const sqlist *);

int sqlist_getnum(const sqlist *);

void sqlist_destroy(sqlist *);

int sqlist_union(sqlist *, const sqlist *);

void sqlist_print(const sqlist *);

#endif
