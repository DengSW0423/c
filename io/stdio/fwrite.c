#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct stu
{
    int id;
    int score;
    char name[32];
};


int main()
{
    struct stu s = {1, 99, "dsw"};

    FILE *f = fopen("stu", "w");
    if (f == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    int ret = fwrite(&s, sizeof(s), 1, f);
    if (ret < 1)
    {
        fprintf(stderr, "error\n");
    }
    else
    {
        printf("successfully saved: %d\n", ret);
    }

    fclose(f);

    return 0;
}
