/* realizati un program care ordoneaza descrescator elementele de pe prima linie 
a unui tablou bidimensional numai prin operatia de interschimbare a coloanelor
ex: n = 3, m = 4
2  4 13 2 
3  1 60 13
16 7 30 2
se va afisa

13 4 2 2
60 1 3 13
30 7 16 2 
*/

#include <stdio.h>

int main()
{
    int i, j, n, m, aux, r;
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
    for (j = 0; j < m; j++)
    {
        for (r = m - 1; r > j; r--)
        {
            if (a[0][r] > a[0][r-1])
            {
                for (i = 0; i < n; i++)
                {
                    aux = a[i][r];
                    a[i][r] = a[i][r-1];
                    a[i][r-1] = aux;
                }
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
