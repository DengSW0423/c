#ifndef ARR_QUEUE_H
#define ARR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE    5

typedef struct arr_queue
{
    int head;
    int tail;
    int data[SIZE];
} arr_queue;

arr_queue *create();

void destroy(arr_queue *q);

int enq(arr_queue *q, int d);

int deq(arr_queue *q, int *d);

int is_full(arr_queue *q);

int is_empty(arr_queue *q);

void print(arr_queue *q);

#endif