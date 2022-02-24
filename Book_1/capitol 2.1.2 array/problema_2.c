#include <stdio.h>

int main()
{
    int i, n;
    int a[100];
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]:", i);
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n; i++)
    {
        if (a[i]/10 == 0)
        {
            a[i] = a[i+1] + a[i-1];
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
