#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    time_t tim = time(NULL);
    if (tim == (time_t) -1)
    {
        perror("time()");
        exit(EXIT_FAILURE);
    }

/*     struct tm *tm = localtime(&tim);
    if (tm == NULL)
    {
        perror("localtime()");
        exit(EXIT_FAILURE);
    } */

    char *str = ctime(&tim);
    printf("%s", str);
    exit(EXIT_SUCCESS);
}
