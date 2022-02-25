#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFSIZE 8192

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("usage:..\n");
        exit(EXIT_FAILURE);
    }

    int src = open(argv[1], O_RDONLY);
    if (src < 0)
    {
        perror("open()");
        exit(EXIT_FAILURE);
    }

    int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest < 0)
    {
        close(src);
        perror("open()");
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZE];
    ssize_t nread = read(src, buf, BUFSIZE);
    ssize_t nwritten = 0;
    ssize_t need_to_write = 0;

    while (nread > 0)
    {
        need_to_write = nread;
        nwritten = write(dest, buf, nread);
        if (nwritten < 0)
            exit(EXIT_FAILURE);

        while (nwritten < need_to_write)
        {
            size_t offset = 0;
            offset += nwritten;
            need_to_write -= nwritten;
            nwritten = write(dest, buf + offset, need_to_write);
            if (nwritten < 0)
                exit(EXIT_FAILURE);
        }

        nread = read(src, buf, BUFSIZE);
    }

    if (nread == 0)
    {
        printf("ok!\n");
    }
    else
    {
        fprintf(stderr, "error\n");
    }

    close(src);
    close(dest);
    return 0;
}
