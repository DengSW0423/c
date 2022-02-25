#include <stdio.h>
#include <stdlib.h>

union union_test
{
    struct s
    {
        u_int16_t i;
        u_int16_t j;
    }x;

    u_int32_t y;
    
} un;



int main()
{

    un.y = 0x11223344;
    printf("%x\n", un.x.i + un.x.j);

    return 0;
}
