#include <stdio.h>

int n, a[50];

void min(int i, int *x)
{
    if (i == n-1)
    {
        *x = a[n-1];
    }else
    {
        min(i+1, x);
        if (a[i] < *x)
        {
            *x = a[i];
        }
    }
}

int main()
{
    int i;
    int *x = a;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    min (0, x);
    printf("%d\n", *x);
    return 0;
}
