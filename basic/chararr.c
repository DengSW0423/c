#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char str[16] = "hello";
    
    strncat(str, "sdfsfsfsfsafsafsf", 16);

    puts(str);

    exit(0);
}
