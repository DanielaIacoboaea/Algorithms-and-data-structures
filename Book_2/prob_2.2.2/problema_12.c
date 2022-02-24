#include <stdio.h>

int a[50], n;

void s(int i, int t)
{
    int x, j;
    if (i < n -1 )
    {
        for (j = i + 1; j < n;j++)
        {
            if (a[i] * t > a[j] * t)
            {
                x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }else
    {
        s(i+1, t);
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
    s(0, 1);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
