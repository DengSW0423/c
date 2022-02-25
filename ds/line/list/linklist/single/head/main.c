#include <stdlib.h>
#include <stdio.h>

#include "list.h"

int main()
{
    node *list = list_create();
    if (list == NULL)
    {
        fprintf(stderr, "create list error!\n");
        exit(1);
    }

    datatype arr[3] = {1,2,3};
    for (int i = 0; i < 3; i++)
    {
        list_pushback(list,&arr[i]);
    }
    
    for (int i = 0; i < 3; i++)
    {
        list_pushfront(list,&arr[i]);
    }
    list_print(list);
    
    datatype d;
    list_delete_at(list, list->data, &d);

    list_print(list);
    printf("%d\n", d);

    list_destroy(list);

    return 0;
}
