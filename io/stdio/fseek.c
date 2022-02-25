#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    FILE *f = fopen("test.txt", "r+");
    char *str = "abcdefghjklmn";

    fputs(str, f);
    printf("%ld\n", ftell(f));

    rewind(f);
    printf("%ld\n", ftell(f));

    int ch;
    while ((ch = fgetc(f)) != EOF)
    {
        printf("%c", ch);
    }
    printf("\n");

    fseek(f, -2, SEEK_CUR);

        while ((ch = fgetc(f)) != EOF)
    {
        printf("%c", ch);
    }
    printf("\n");
    
    fclose(f);
    return 0;
}
