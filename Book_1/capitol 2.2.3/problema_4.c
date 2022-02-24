/* n linii si m coloane
perechea de multimi cu reuniunea de cardinal maxima
afisare: nr de ordine ale liniilor din pereche

ex: n = 4, m = 4

8 6 7 9
2 1 4 5
9 2 7 8
4 2 3 7 
se va afisa: 1 si 2
*/

#include <stdio.h>

int main()
{
    int i, j, n, m, c, t, max, card, x, y;
    int a[15][15];
    printf("n, m: ");
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
    for (i = 0; i+1 < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            card = 0;
            for (c = 0; c < m; c++)
            {
                for (t = 0; t < m; t++)
                {
                    if (a[i][c] != a[j][t])
                    {
                        card++;
                    }
                }
            }
            if (card > max)
            {
                max = card;
                x = i;
                y = j;

            }
        }
    }
    printf("numarul maxim de elemente prin reuiune este %d de pe liniile %d si %d\n", max/2, x, y);
    return 0;
}
