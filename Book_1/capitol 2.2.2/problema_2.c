#include <stdio.h>

int main()
{
    int n, m, max, x, i, j, c;
    int a[10][10];
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    max = 0;
    for (j = 0; j < m; j++)
    {
        x = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i][j] % 3 == 0)
            {
                x++;
            }
        }
        if (x > max)
        {
            max = x;
            c = j;
        }
    }
    printf ("max: %d is on column %d\n", max, c);
    return 0;
}
