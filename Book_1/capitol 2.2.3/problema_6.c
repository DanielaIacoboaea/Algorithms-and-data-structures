/* fie un tablou bidimensional de n linii si m coloane
sa se realizeze un program care insereaza in fata oricarei linii ale carei elemente sunt ordonate 
crescator sau descrescator, o noua linie cu elemente egale cu valoarea maxima de pe linia ordonata
ex:
n = 2, m = 4
si 
1 4 5 8
9 8 5 2 
se va afisa
8 8 8 8
1 4 5 8
9 9 9 9
9 8 5 2
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i, j, max, n, m, def, k, l, t, v;
    int a[10][10];
    bool ok;
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
        ok = 1;
        def = (a[i][0] < a[i][1]);
        //max = 0;
        for (j = 1; j+1 < m; j++)
        {
            if ((a[i][j] < a[i][j+1]) != def)
            {
                ok = 0;
            } 
            /*else if (a[i][j+1] > max)
            {
                max = a[i][j+1];
            }*/ 
        }
        if (ok)
        {
            for (k = n - 1; k >= i; k--)
            {
                for (l = 0; l < m; l++)
                {
                    a[k+1][l] = a[k][l];
                }
            }
            if (def)
            {
                v = a[i][m-1];

            }else 
            {
                v = a[i][0];
            }
            /* for (k = i; k <= i; k++)
            {
                for (t = 0; t < m; t++)
                {
                    a[k][t] = max;
                }
            }*/
            for (l = 0; l < m; l++)
            {
                a[i][l] = v;
            }
            n++;
            i = i + 1;
        }else
        {
            i++;
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
