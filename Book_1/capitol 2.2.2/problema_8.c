#include <stdio.h>

int main()
{
    int i, j, n, p;
    int a[50][50];
    p = 1;
    printf("n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (j = 1; j <= (n+1)/2; j++)
    {
        for (i = j; i <= n - j + 1; i++)
        {
            p = p * a[i][j];
        }
    }
    printf("p: %d\n", p);
    return 0;
}
