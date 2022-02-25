#include <dirent.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define PATHNAME "/home/admin"

int main()
{
    DIR *dir = opendir(PATHNAME);
    if (dir == NULL)
    {
        perror("opendir()");
        exit(EXIT_FAILURE);
    }

    struct dirent *de;
    errno = 0;
    while ((de = readdir(dir)) != NULL)
    {
        printf("%s  ", de->d_name);

#ifdef _DIRENT_HAVE_D_RECLEN
        printf("%u\n", de->d_reclen);
#endif
    }

    if (errno != 0)
    {
        closedir(dir);
        fprintf(stderr, "readdir: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    closedir(dir);
    exit(EXIT_SUCCESS);
}
