#include "arr_queue.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    arr_queue *q = create();
    if (q == NULL)
    {
        printf("error\n");
        exit(1);
    }

    int arr[4] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++)
    {
        enq(q, arr[i]);
    }

    int i;
    deq(q, &i);
    enq(q, arr[0]);
    enq(q, arr[0]);
    
    print(q);

    destroy(q);
    return 0;
}
