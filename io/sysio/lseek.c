#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage:..\n");
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0666);
    if (fd < 0)
    {
        perror("open()");
        exit(EXIT_FAILURE);
    }

    off_t offset = lseek(fd, 0, SEEK_SET);
    printf("%ld\n", offset);

    char *buf = "dsw";
    ssize_t nwritten = write(fd, buf, 3);
    printf("%ld\n", nwritten);

    FILE *f = fdopen(fd, "a");
    if (f == NULL)
    {
        close(fd);
        perror("fdopen()");
        exit(1);
    }

    printf("%ld\n", ftell(f));

    fclose(f);
    return 0;
}
