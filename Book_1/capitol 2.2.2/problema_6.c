#include <stdio.h>

int main()
{
    int i, j, n, m, count = 0;
    int a[100][100];
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            a[i][j] = i;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            a[i][m-j+1] = 0;
            count++;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("count: %d\n", count);

    return 0;
}
