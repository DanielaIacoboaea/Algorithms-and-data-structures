#include <stdio.h>

int main()
{
    int i, j, n, m, k;
    int a[10][10];
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    k = 0;
    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            for (j = 1; j <= m; j++)
            {
                k++;
                a[i][j] = k;
            }
        }else
        {
            for (j = m; j >= 1; j--)
            {
                k++;
                a[i][j] = k;
            }
        }
        for (i = 1; i < n; i++)
        {
            for (j = 1; j < m; j++)
            {
                printf("%d", a[i][j]);
            }
            printf("\n");
        }        
    }
    return 0;
}
