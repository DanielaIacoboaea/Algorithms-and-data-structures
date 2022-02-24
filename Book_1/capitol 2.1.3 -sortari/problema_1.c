/* algoritmul de selectie 
in sortarea prin selectie, elementele vectorului sunt impartite in 2 liste
- una ordonata
- una neordonata
aloritmul de selectie are n - 1 pasi:
- identificarea min
- schimbarea min cu primul element din array
*/

#include <stdio.h>

int main()
{
    int a[50];
    int i, n, p, j, aux, temp;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    int min = a[0];
    for (i = 0; i < n; i++)
    {
        printf("primul for i: %d\n", i);
        p = i;
        printf("primul for p: %d\n", p);
        for (j = i + 1; j < n; j++)
        {
            printf("al doilea for j: %d\n", j);
            printf("al doilea for a[%d] %d si a[%d] %d care intra in comparatie\n", p, a[p], j, a[j]);
            if (a[p] > a[j])
            {
                //p = j;
                printf("p din if %d\n", p);
                printf("j din if %d\n", j);
                aux = a[j];
                printf("aux: %d\n", aux);
                a[j] = a[p];
                printf("a[%d]: %d\n", i, a[i]);
                a[p] = aux;
                printf("a[%d]: %d\n", p, a[p]);
                p = j;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
