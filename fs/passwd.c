#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage...\n");
        exit(EXIT_FAILURE);
    }

    errno = 0;
    struct passwd *p = getpwnam(argv[1]);
    if (p == NULL)
    {
        if (errno != 0)
        {
            perror("getpwnam");
        }
        else
        {
            printf("not found %s\n", argv[1]);
        }
        exit(EXIT_FAILURE);
    }

    printf("Name: %s uid: %ld\n", p->pw_name, (long)p->pw_uid);
    exit(EXIT_SUCCESS);
}
