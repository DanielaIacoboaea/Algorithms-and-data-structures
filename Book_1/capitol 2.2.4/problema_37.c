/* tablou bidimensional n
traseu de plecare de pe linia x si coloana y
directia data de un sir de caractere p: N, V, E, S
determinati elementele prin care s-a trecut de cele mai multe ori 
pt fiecare element din solutie se va afisa linia si coloana pe care este situat
ex: 
n = 4, m = 4, x = 3, y = 2, p = 8
si traseul N, N, E, S, V, S, S, V

se va afisa:
2 2 
3 2 
*/

#include <stdio.h>
#include <ctype.h>

typedef struct row_column
{
    int x;
    int y;

}row_column;

int main()
{
    int i, j, n, m, k, x, y, c, size_c = 2, r;
    char p[15];
    row_column coord[15];
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    printf("x,y: ");
    scanf("%d,%d", &x, &y);

    for (k = 1; k <= m; k++)
    {
        printf("p[%d]: ", k);
        scanf(" %c", &p[k]);
    }
    
    c = 1;
    coord[1].x = x;
    coord[1].y = y;
    for (k = 1; k <= m; k++)
    {
        if (toupper(p[k]) == 'N')
        {
            c++;
            x = x - 1;
            coord[c].x = x;
            coord[c].y = y;
            size_c++;

        }else if (toupper(p[k]) == 'S')
        {
            c++;
            x = x + 1;
            coord[c].x = x;
            coord[c].y = y;
            size_c++;

        }else if (toupper(p[k]) == 'E')
        {
            c++;
            y = y + 1;
            coord[c].x = x;
            coord[c].y = y;
            size_c++;

        }else if (toupper(p[k]) == 'V')
        {
            c++;
            y = y - 1;
            coord[c].x = x;
            coord[c].y = y;
            size_c++;
        }
    }
    for (c = 1; c+1 < size_c; c++)
    {
        for (r = c + 1; r < size_c; r++)
        {
            if ((coord[c].x == coord[r].x) && (coord[c].y == coord[r].y))
            {
                printf("%d %d\n", coord[c].x, coord[c].y);
            }
        }
    }
    printf("\n");
    for (c = 1; c < size_c; c++)
    {
        printf("%d %d\n", coord[c].x, coord[c].y);
    }
    
    return 0;
}
