/* scrieti un program care completeaza elementele unui tablou patratic de ordin n astfel
-elementele diagonalei principale sunt egale cu 0
- elementele situate sub diagonala principala sunt egale cu 1
- elementele situate deasupra diagonalei principale sunt egale cu 2
ex: n = 3
0 2 2   0 2 2 2 
1 0 2   1 0 2 2
1 1 0   1 1 0 2
        1 1 1 0
*/

#include <stdio.h>

int main()
{
    int a[10][10];
    int i, j, n;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                a[i][j] = 0;
            }
        }
    }
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            a[i][j] = 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            a[i][j] = 2;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
