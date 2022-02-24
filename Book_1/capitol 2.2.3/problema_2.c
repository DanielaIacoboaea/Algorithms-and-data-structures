/* se considera un tablou bidimensional cu n linii si m coloane 
sa se det nr de perechi de linii monotone
doua linii se numesc monotone daca oricare pereche de elemente ale lor situate pe aceeasi coloana 
respecta monotonia elementelor de pe prima coloana
ex: 
n = 3, m = 4
8 6 7 6 
2 1 4 7
4 2 3 5 
se va afisa 1 
liniile 1 si 3 formeaza o pereche de linii monotone
*/

#include <stdio.h>
#include <stdbool.h>


int main()
{
    int i, j, n, m, count = 0, r, mt, l1, l2;
    int a[15][15];
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
    for (r = 0; r+1 < n; r++)
    {
        for (i = r+1; i < n; i++)
        {
            mt = a[r][0] < a[i][0];
            ok = 1;
            for (j = 1; j < m; j++)
            {
                if ((a[r][j] < a[i][j]) != mt)
                {
                    ok = 0;
                }
            }
            if (ok)
            {
                count++;
                l1 = r;
                l2 = i;
            }
        }
    }
    printf("%d linii. Liniile %d si %d formeaza perechi monotone\n", count, l1, l2);
    return 0;
}
