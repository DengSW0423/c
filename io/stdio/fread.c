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
    struct stu s;
    FILE *f = fopen("stu", "r");
    if (f == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    int ret = fread(&s, sizeof(s), 1, f);
    fclose(f);

    if (ret < 1)
    {
        fprintf(stderr, "error\n");
        exit(1);
    }

    printf("sucessfully loaded: %d\n", ret);
    printf("id = %d, name = %s, score = %d\n", s.id, s.name, s.score);

    return 0;
}
