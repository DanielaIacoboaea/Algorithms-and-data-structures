#include <stdio.h>

int main()
{
    int i, j, n, s;
    int a[100][100];
    printf("n: ");
    scanf("%d", &n);
    s = 0;
    for (i = 1; i <=n; i++)
    {
        for (j = 1; j<= n; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 1; i <= ((n+1)/2); i++)
    {
        for (j = i; j <= (n-i+1); j++)
        {
            s = s + a[i][j];
        }
    }
    printf("s: %d\n", s);
    return 0;
}
