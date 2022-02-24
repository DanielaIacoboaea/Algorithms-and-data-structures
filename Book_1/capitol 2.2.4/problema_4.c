/* se considera doua tablouri bidimensionale de dimensiuni identice (n*m)
sa se afiseze transpusa matricei suma
transpusa unei matrici se obtine prin schimbarea liniilor cu coloanele
ex: n = 3, m = 2
2 3     5 6 
3 4     1 1
4 9     0 0 
se va afisa

7 4 4
9 5 9
*/

#include <stdio.h>

int main()
{
    int i, j, n, k, l, m;
    int a[10][10], b[10][10], s[10][10], t[10][10];
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

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            s[i][j] = a[i][j] + b[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            t[j][i] = s[i][j];
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    return 0;
}
