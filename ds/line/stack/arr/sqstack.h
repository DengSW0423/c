#ifndef SQSTACK_H
#define SQSTACK_H

#define SIZE 5

typedef int datatype;

typedef struct sqstack
{
    datatype data[SIZE];
    int top;
} sqstack;

sqstack *st_create();

void st_destroy(sqstack *stack);

int st_push(sqstack *stack, datatype *d);

int st_pop(sqstack *stack, datatype *d);

int st_top(sqstack *stack, datatype *d);

int st_isempty(sqstack *stack);

void st_print(sqstack *stack);

#endif