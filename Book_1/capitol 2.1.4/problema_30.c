
#include <stdio.h>

int main()
{
    int a[15];
    int n, i, aux, x, y;

    printf("n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= n; i++)
    {
        x = a[i];
        y = (i + a[i]) % n;
        a[i] = a[y];
        a[y] = a[x];
    }
    for (i = 1; i<=n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
