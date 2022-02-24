#include <stdio.h>

int main()
{
    int i, j, n, m;
    int a[15][15];
    m = 0;
    printf("n: ");
    scanf("%d", &n);
    for (i = 1; i<= n; i++)
    {
        for (j = 1; j <= (n-i+1); j++)
        {
            m++;
            a[i][j] = m;
        }
    }
    for (i = n; i >= 2; i--)
    {
        for (j = n; j >= (n - i + 2); j--)
        {
            m++;
            a[i][j] = m;
        }
    }
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
