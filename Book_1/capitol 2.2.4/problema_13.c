/* se considera un tablou bidimensional patratic cu n linii
sa se det toate elementele ce reprezinta puncte "sa" (element minim pe linie si maxim pe coloana pe care este situat)
n = 3
    0  1  2

0   11 55 53
1   15 22 25
2   10 23 26
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, i, j, min, max, line, poz, r;
    int a[15][15];
    bool ok;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        min = a[i][0];
        ok = 1;
        for (j = 1; j < n; j++)
        {
            if (a[i][j] < min)
            {
                min = a[i][j];
                poz = j;
                line = i;
            }
        }
        max = min;
        for (r = 0; r < n; r++)
        {
            if(a[r][poz] > max)
            {
                ok = 0;
            }
        }
        if (ok)
        {
            printf("%d punct sa pentru linia %d si coloana %d\n", min, line, poz);
        }else 
        {
            printf("nu este niciun punct sa pe linia %d\n", i);
        }
    }
    return 0;
}
