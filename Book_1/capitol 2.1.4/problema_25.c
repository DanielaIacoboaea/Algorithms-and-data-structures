/* se considera 2 multimi retinute in 2 vectori
sa se realizeze un program care det reuniunea, intersectia si diferenta lor
ex: A = (2, 4, 1, 6, 7), B = (3, 4, 8, 9) se va afisa
a U b (2, 4, 1, 6, 7, 3, 8, 9); a X b = (4);  a - b (2, 1, 6, 7)
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a[15], b[15], c[15];
    int i, j, n, m, k, l, ok;
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (j = 0; j < m; j++)
    {
        printf("b[%d]: ", j);
        scanf("%d", &b[j]);
    }
    printf("reuniunea a si b\n");
    l = 0;
    
    for (i = 0; i < n; i++)
    {
        c[l] = a[i];
        l++;
    }
    k = n;
    for (j = 0; j < m; j++)
    {
        ok = 0;
        for (l = 0; l < k; l++)
        {
            if (b[j] == c[l])
            {
                ok = 1;
            }
        }
        if (ok == 0)
        {
            c[k] = b[j];
            k++;
        }
    }
    for (l = 0; l < k; l++)
    {
        printf("%d ", c[l]);
    }

    printf("\nintersectia intre a si b\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                printf("%d ", a[i]);
            }
        }
    }
    printf("\ndiferenta  intre a si b\n");

    for (i = 0; i < n; i++)
    {
        ok = 0;
        for (j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                ok = 1;
            }
        }
        if (ok == 0)
        {
            printf("%d ", a[i]);
        }
    }
    return 0;
}
