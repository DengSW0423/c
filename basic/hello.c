#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int arr[2][3] = {1,2,3,4,5,6};
    int arr1[3][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr1[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }

    exit(0);
}
