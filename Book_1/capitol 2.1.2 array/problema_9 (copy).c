#include <stdio.h>

int main()
{
    int a[100];
    int max, i, n, p = 0, j, m, x;
    printf("n, x: ");
    scanf("%d,%d", &n, &x);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    i = 0;
    j = n - 1;
    while (i != j && p == 0)
    {
        m = (i + j)/2;
        if (a[m] == x)
        {
            p = m;
        }else 
        {
            if (a[m] > x)
            {
                j = m - 1;
            }else 
            {
                i = m + 1;
            }
        }
    }
    printf("p: %d\n", p);
    return 0;
}
