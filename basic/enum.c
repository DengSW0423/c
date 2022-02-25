#include <stdio.h>

enum state
{
    sleeping,
    running,
    stopped
};

int main()
{
    enum state s = running;

    printf("%d\n", s);

    return 0;
}