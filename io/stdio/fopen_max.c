#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    int count = 0;
    while (1)
    {
        FILE *f = fopen("test", "w");
        if (f == NULL)
        {
            perror("fopen()");
            break;
        }
        count++;
    }

    printf("%d\n", count);

    return 0;
}
