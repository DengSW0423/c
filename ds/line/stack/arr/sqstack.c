#include "sqstack.h"

#include <stdlib.h>
#include <stdio.h>

sqstack *st_create()
{
    sqstack *s = malloc(sizeof *s);
    if (s != NULL)
    {
        s->top = -1;
    }

    return s;
}

void st_destroy(sqstack *stack)
{
    free(stack);
}

int st_push(sqstack *stack, datatype *d)
{
    if (stack->top == SIZE - 1)
        return -1;

    stack->data[++stack->top] = *d;

    return 0;
}

int st_pop(sqstack *stack, datatype *d)
{
    if (st_isempty(stack))
    {
        printf("stack is empty, can't pop\n");
        return -1;
    }
    *d = stack->data[stack->top--];

    return 0;
}

int st_top(sqstack *stack, datatype *d)
{
    if (st_isempty(stack))
        return -1;

    *d = stack->data[stack->top];
    
    return 0;
}

int st_isempty(sqstack *stack)
{
    return stack->top == -1;
}

void st_print(sqstack *stack)
{
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

