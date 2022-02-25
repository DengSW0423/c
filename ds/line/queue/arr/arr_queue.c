#include "arr_queue.h"

#include <stdio.h>
#include <stdlib.h>

arr_queue *create()
{
    arr_queue *q = malloc(sizeof *q);
    if (q != NULL)
    {
        q->head = 0;
        q->tail = 0;
    }

    return q;
}

void destroy(arr_queue *q)
{
    free(q);
}

int enq(arr_queue *q, int d)
{
    if (is_full(q))
    {
        printf("queue is full, can't enqueue.\n");
        return -1;
    }

    q->tail++;
    q->data[q->tail % SIZE] = d;

    q->tail %= SIZE;
    return 0;
}

int deq(arr_queue *q, int *d)
{
    if  (is_empty(q))
    {
        printf("queue is empty, can't dequeue.\n");
        return -1;
    }

    q->head++;
    *d = q->data[q->head % SIZE];

    q->head %= SIZE;
    return 0;
}

int is_full(arr_queue *q)
{
    return (q->tail + 1) % SIZE == q->head;
}

int is_empty(arr_queue *q)
{
    return q->head == q->tail;
}

void print(arr_queue *q)
{
    if (q->tail > q->head)
        for (int i = q->head + 1; i <= q->tail; i++)
            printf("%d ", q->data[i % SIZE]);
    else
    {
        for (int i = q->head + 1; i < SIZE; i++)
        {
            printf("%d ", q->data[i]);
        }
        for (int i = 0; i <= q->tail; i++)
        {
            printf("%d ", q->data[i]);
        }
    }
    printf("\n");
}
