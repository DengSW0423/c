#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "invalid args\n");
        exit(1);
    }

    FILE *src = fopen(argv[1], "r");
    if (src == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    unsigned long count = 0;
    while (fgetc(src) != EOF)
    {
        count++;
    }

    printf("size: %lu\n", count);

    fclose(src);

    return 0;
}
