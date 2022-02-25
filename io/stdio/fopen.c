#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    FILE *f = fopen("test", "w");
    if (f == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    printf("%p\n", f);
    printf("%p\n", "hello");
    int a;
    static int b;
    printf("%p\n", &a);
    printf("%p\n", &b);

    fclose(f);
    return 0;
}
