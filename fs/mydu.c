#include <dirent.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static u_int64_t mydu(const char *path)
{
    struct stat sb;
    if (lstat(path, &sb) < 0)
    {
        perror("lstat()");
        exit(EXIT_FAILURE);
    }

    if (!S_ISDIR(sb.st_mode))
        return sb.st_blocks / 2;

    u_int64_t ret = 0;
    DIR *dir = opendir(path);
    if (dir == NULL)
    {
        perror("opendir()");
        exit(EXIT_FAILURE);
    }
    struct dirent *de;
    errno = 0;
    while ((de = readdir(dir)) != NULL)
    {
        if (lstat(de->d_name, &sb) < 0)
        {
            perror("lstat()");
            exit(EXIT_FAILURE);
        }
        if (S_ISDIR(sb.st_mode))
        {
            if (strcmp(de->d_name, "..") == 0 || strcmp(de->d_name, ".") == 0)
                continue;
            ret += mydu(de->d_name);
        }
        else
            ret += sb.st_blocks / 2;
    }

    if (errno != 0)
    {
        closedir(dir);
        perror("readdir()");
        exit(EXIT_FAILURE);
    }

    closedir(dir);
    return ret + sb.st_blocks / 2;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage...\n");
        exit(EXIT_FAILURE);
    }

    printf("%lu\n", mydu(argv[1]));
    return 0;
}
