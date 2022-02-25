#include <stdlib.h>
#include <stdio.h>

int main()
{
    int m1[2][3] = {1,2,3,4,5,6};
    int m2[3][2] = {1,2,3,4,5,6};

    int m3[2][2] = {0};
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }

    exit(0);
}
