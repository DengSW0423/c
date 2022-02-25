#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *stream;
    char *line = malloc(3UL);
    size_t len = 3UL;
    ssize_t nread;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    stream = fopen(argv[1], "r");
    if (stream == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // while ((nread = getline(&line, &len, stream)) != -1)
    while ((nread = getdelim(&line, &len, '\n', stream)) != -1)
    {
        printf("%lu\n", len);
        printf("Retrieved line of length %zu:\n", nread);
        fwrite(line, nread, 1, stdout);
    }

    free(line);
    fclose(stream);
    exit(EXIT_SUCCESS);
}
