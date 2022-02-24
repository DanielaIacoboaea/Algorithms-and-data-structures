#include <stdio.h>

int main()
{
    int n, m, i, j, max, linie, prod, prod_max, x;
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
    linie = 0;
    prod_max = 0;
    for (i = 0; i < n; i++)
    {
        x = 0;
        prod = 1 * a[i][0];
        for (j = 1; j < m; j++)
        {
            prod = prod * a[i][j];
            if (a[i][j] == a[i][0])
            {
                x++;
            }
        }
        if (x > max)
        {
            max = x;
            linie = i;
            prod_max = prod;
        }
    }
    printf("linie: %d, max: %d, prod_max: %d\n", linie, max, prod_max);
    return 0;
}
