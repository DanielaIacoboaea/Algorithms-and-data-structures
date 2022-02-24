/* se considera un tablou bidimensional ce memoreaza pe fiecare din cele n linii cate o multime de m elemente
sa se realizeze un program care det perechea de multimi cu intersectie de cardinal maxim
se vor afisa nr de ordine ale liniilor de pereche
ex: n = 4; m = 4;
8 6 7 9 
2 1 4 5
9 2 7 8
4 2 3 7
se va afisa 1 3 
*/

#include <stdio.h>

int main()
{
    int i, j, n, m, card, x, y, max, c, t;
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
    for (i = 0; i+1 < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            card = 0;
            for (c = 0; c < m; c++)
            {
                for (t = 0; t < m; t++)
                {
                    if (a[i][c] == a[j][t])
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
    printf("card max: %d este intre liniile %d si %d\n", max, x, y);
    /*for (k = 0; k < n; k++)
    {
        for (i = 0; i < m; i++)
        {
            for (j = i + 1; j < m; j++)
            {
                if (a[k][i]>a[k][j])
                {
                    aux = a[k][i];
                    a[k][i] = a[k][j];
                    a[k][j] = aux;
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
    }*/

    return 0;
}
