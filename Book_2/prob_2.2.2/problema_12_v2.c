#include <stdio.h>

int a[50], n;

void S(int i, int j, int t)
{
    int x;
    if (i < n-1)
    {
        if (j < n)
        {
            if (a[i] *t > a[j] * t)
            {
                x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
            S(i, j+1, t);
        }
    }
}

int main()
{
    int i;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    S(0, 0, -1);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
