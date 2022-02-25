#include <stdlib.h>
#include <stdio.h>

void max_num(int *arr, int row, int col)
{
    int max = *arr;
    for(int i = 0; i < row * col; i++)
    {
        max = *(arr + i) > max ? *(arr + i) : max;
    }

    printf("最大数为 %d\n", max);
}

int main()
{
    int arr[2][3] = {1, 2, 3, 4, 5, 6};
    max_num((int *)arr, 2, 3);
}