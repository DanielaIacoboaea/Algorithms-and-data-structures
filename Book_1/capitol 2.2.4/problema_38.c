/* se considera o tabla de sah cu n linii si m coloane pe care sunt plasate pioni 
pionii unt codificati la citire cu valoarea 1
regina adversa trebuie plasata intr-un punct al tablei astfel incat pe cele doua diagonale pe care le ataca, sa se afle cati mai multi pioni
det linia, coloana si nr de pioni de pe diagonalele atacate 
ex: 
n = 5, m = 4
     1 2 3 4

1    1 1 0 0
2    0 1 0 1
3    1 0 1 0
4    1 0 0 0 
5    1 0 1 0

se va afisa
4 2 5 (linia 4, coloana 2, 5 pioni)
*/

#include <stdio.h>

int sum(int x[][4], int size_i, int el_i, int el_j)
{
    int i, j, sum = 0;
    
    i = el_i;
    j = el_j;
    while (i >= 1 && j >= 1)
    {
        sum = sum + x[i][j];
        i = i - 1;
        j = j - 1;
    }
    i = el_i;
    j = el_j;
    while (i <= size_i && j <= 4)
    {
        sum = sum + x[i][j];
        i = i + 1;
        j = j + 1;

    }
    i = el_i;
    j = el_j;
    while (i <= size_i && j >= 1)
    {
        sum = sum + x[i][j];
        i = i+1;
        j = j - 1;
    }
    i = el_i;
    j = el_j;
    while (i >= 1 && j <= 4)
    {
        sum = sum + x[i][j];
        i = i - 1;
        j = j + 1;
    }
    return sum;
}

int main()
{
    int i, j, n, m, max, poz_x, poz_y;
    int a[15][4], s[15][15];
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            s[i][j] = 0;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (a[i][j] == 0)
            {
                s[i][j] = sum(a, n, i, j);
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
    max = s[0][0];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (s[i][j] > max)
            {
                max = s[i][j];
                poz_x = i;
                poz_y = j;
            }
        }
    }
    printf("\nRegina va ataca de pe linia %d, coloana %d luand maxim %d pioni\n", poz_x, poz_y, max);
    return 0;
}
