#include <stdio.h>

int n;

int C(int x, int t)
{
    if (x == 0)
    {
        return 0;
    }else
    {
        if (x % 2 == t)
        {
            return C(x/10, t) + x % 10;
        }else
        {
            return C(x/10, t);
        }
    }
}

void M(int i, int a[50])
{
    if (i < n)
    {
        a[i] = C(a[i], i%2);
        M(i+1, a);
    }
}

int main()
{
    int i;
    int a[50];
    printf("n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    M(1, a);
    for (i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
