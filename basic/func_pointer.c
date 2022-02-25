#include <stdio.h>
#include <stdlib.h>

int *add(int a, int b)
{

    return NULL;
}

int main()
{

    int *(*arr[3])(int, int) = {NULL};

    arr[0] = add;

    return 0;
}
