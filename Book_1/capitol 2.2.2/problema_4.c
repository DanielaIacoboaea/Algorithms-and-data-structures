#include <stdio.h>

int main()
{
    int i, j, n, p;
    int a[10][10];
    printf("n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            a[i][j] = 2 * ((i-1) *n + j);
        }
    }
    /*for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= n; i++)
        {
            a[i][j] = i;
        }
    } */
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
