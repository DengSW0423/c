#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SIZE    32

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "error args\n");
        exit(1);
    }

    FILE *src = fopen(argv[1], "r");
    if (src == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    FILE *dest = fopen(argv[2], "w");
    if (dest == NULL)
    {
        fclose(src);
        perror("fopen()");
        exit(1);
    }

    char buf[SIZE];
    char *ret = fgets(buf, SIZE, src);
    while (ret != NULL)
    {
        fputs(buf, dest);
        ret = fgets(buf, SIZE, src);
    }

    if (feof(src))
    {
        printf("ok\n");
    }
    else
    {
        printf("error\n");
    }

    fclose(dest);
    fclose(src);

    return 0;
}
