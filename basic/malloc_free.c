#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = malloc(sizeof(int));
    printf("%p\n", p);

    *p = 12;
    printf("%d\n", *p);
    free(p);

    p = NULL;

    printf("%p\n", p);
    printf("%d\n", *p);

    return 0;
}
