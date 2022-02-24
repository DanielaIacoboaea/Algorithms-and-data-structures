#include <stdio.h>

int main()
{
    int a[10][10];
    int i, n, m, x, j;
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    for(i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < n; i++)
    {
        x = 0;
        for (j = 0; j < m; j++)
        {
            x = x + a[i][j] % 10;
        }
        printf("x: %d ", x);
    }

    return 0;
}
