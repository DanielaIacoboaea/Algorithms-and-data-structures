#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n, m;
    int a[15][15];
    printf("n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            a[i][j] = abs(i-j);
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <=n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
