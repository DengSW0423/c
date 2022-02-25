#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage ...\n");
        exit(EXIT_FAILURE);
    }

    if (argv[2] <= 0)
    {
        fprintf(stderr, "line number should greater than 0.\n");
        exit(EXIT_FAILURE);
    }

    int to_read = open(argv[1], O_RDONLY);
    if (to_read < 0)
    {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }
    int to_write = open(argv[1], O_WRONLY);
    if (to_write < 0)
    {
        perror("open()");
        close(to_read);
        exit(EXIT_FAILURE);
    }

    char buf;
    size_t count = 0;
    ssize_t nread = read(to_read, &buf, 1);
    while (nread > 0)
    {
        if (buf == '\n')
            ++count;
        
        if (count == atoi(argv[2]) - 1)
            break;

        nread = read(to_read, &buf, 1);
    }

    if (count == atoi(argv[2]) - 1)
    {
        off_t start = lseek(to_read, 0, SEEK_CUR);
        lseek(to_write, start, SEEK_CUR);

        nread = read(to_read, &buf, 1);
        while (nread > 0 && buf != '\n')
        {
            nread = read(to_read, &buf, 1);
        }

        off_t len = 0; 
        if (buf == '\n')
        {
            off_t end = lseek(to_read, 0, SEEK_CUR);
            len = end - start;
            lseek(to_write, start, SEEK_SET);
            
            char *buf = malloc(len);
            if (buf == NULL)
            {
                close(to_read);
                close(to_write);
                exit(EXIT_FAILURE);    
            }

            ssize_t nwritten = 0;
            ssize_t need_to_write = 0;
            nread = read(to_read, buf, len);
            while (nread > 0)
            {
                nwritten = write(to_write, buf + nwritten, need_to_write);
                need_to_write = nread - nwritten;
                while (need_to_write > 0)
                {
                    nwritten = write(to_write, buf + nwritten, need_to_write);
                    need_to_write -= nwritten;
                }

                nread = read(to_read, buf, len);
            }

            if (nread < 0)
            {
                close(to_read);
                close(to_write);
                free(buf);
                exit(EXIT_FAILURE);
            }

            free(buf);
            ftruncate(to_write, lseek(to_read, 0, SEEK_END) - len);
        }
        else if (nread == 0)
        {
            len = lseek(to_read, 0, SEEK_CUR) - start;
            ftruncate(to_write, lseek(to_read, 0, SEEK_END) - len);
        }
        else
        {
            close(to_read);
            close(to_write);
        }
    }
    else if (nread == 0)
    {
        printf("no line %d\n", atoi(argv[2]));
    }
    else
    {
        fprintf(stderr, "errro\n");
    }

    close(to_read);
    close(to_write);
    return 0;
}
