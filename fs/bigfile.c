#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "usage...\n");
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT |O_TRUNC, 0666);
    if (fd < 0)
    {   
        perror("open()");
        exit(EXIT_FAILURE);
    }

    lseek(fd, 5UL * 1024*1024*1024 - 1, SEEK_SET);
    write(fd, "a", 1);

    close(fd);

    return 0;
}