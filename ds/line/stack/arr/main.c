#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"

int main()
{
    sqstack *s = st_create();
    if (s == NULL)
        exit(1);

    datatype arr[3] = {1,2,3};

    for (int i = 0; i < 3; i++)
    {
        st_push(s, &arr[i]);
    }

    st_print(s);

    int t;
    st_top(s, &t);
    printf("%d\n", t);

    st_print(s);

    st_destroy(s);
    return 0;
}
