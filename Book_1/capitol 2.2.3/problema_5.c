/* n linii si m coloane
sa se stearga toate liniile care incep cu un element de pe prima linie
ex: n = 4, m = 4;
8 6 7 9 
7 1 4 5 
9 2 7 8
4 2 3 7 
se va afisa
8 6 7 9 
4 2 3 7 
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i, j, n, m, r, t, l, k;
    int a[15][15];
    bool ok;
    printf("n,m ");
    scanf("%d,%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i+1 < n; i++)
    {
        for (r = i+1; r < n; r++)
        {
            ok = 0;
            for (j = 0; j < m; j++)
            {
                if (a[r][0] == a[i][j])
                {
                    ok = 1;
                }
            }
            if (ok)
            {
                for (l = r; l < n; l++)
                {
                    for (k = 0; k < m; k++)
                    {
                        a[l][k] = a[l+1][k];
                    }
                }
                r--;
                n--; 
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
