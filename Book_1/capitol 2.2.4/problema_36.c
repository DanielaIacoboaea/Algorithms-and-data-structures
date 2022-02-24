/* tablou bidimensional n
traseu de plecare de pe linia x si coloana y
directia data de un sir de caractere p: N, V, E, S
det suma elementelor situate pe drum
elementul de start apartine drumului 
ex: 
n = 4, m = 4, x = 3, y = 2, p = 6
si traseul N,N,E,S,V,V 
0 9 5 8 
3 2 1 5
3 8 3 0
0 2 6 2
se va afisa:
30 (8+ 2 + 9 + 5 + 1 + 2 + 3)
*/
# include <stdio.h>
# include <ctype.h>

int main()
{
    int i, j, n, sum = 0, m, k, x, y;
    int a[15][15];
    char p[15];
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    printf("x,y: ");
    scanf("%d,%d", &x, &y);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (k = 1; k <= m; k++)
    {
        printf("p[%d]: ", k);
        scanf(" %c", &p[k]);
    }
    i = x;
    j = y;
    sum = sum + a[i][j];
    printf("%d + ", a[i][j]);
    for (k = 1; k <= m; k++)
    {
        if (toupper(p[k]) == 'N')
        {
            i = i - 1;
            sum = sum + a[i][j];
            printf("%d + ", a[i][j]);

        }else if (toupper(p[k]) == 'S')
        {
            i = i + 1;
            sum = sum + a[i][j];
            printf("%d + ", a[i][j]);

        }else if (toupper(p[k]) == 'E')
        {
            j = j + 1;
            sum = sum + a[i][j];
            printf("%d + ", a[i][j]);

        }else if (toupper(p[k]) == 'V')
        {
            j = j - 1;
            sum = sum + a[i][j];
            printf("%d + ", a[i][j]);
        }
    }
    printf("\n suma: %d\n", sum);
    return 0;
}
