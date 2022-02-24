/* realizati un program care permuta circular liniile unui tablou bidimensional cu 
n linii si m coloane cu o pozitie mai sus
ex: n = 3, m = 4;
2 4 13 2 
3 1 60 13
16 7 30 2 

se va afisa
3  1 60 13 
16 7 30 2
2  4 13 2
*/

#include <stdio.h>

int main()
{
    int i, j, n, m;
    int a[15][15];
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
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            a[n+i][j] = a[i][j];
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                a[i][j] = a[i+1][j];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
