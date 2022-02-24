/* n intervale inchise [a, b], a si b numere intregi
sa se det reuniunea acestora 
ex: n = 5               se va afisa
2 4                     1 4 
1 3                     5 9
5 8                     10 12 
10 12
5 9 
*/

#include <stdio.h>

typedef struct interval{
    int a;
    int b;
} interval;

int main()
{
    int n, i, ra, rb, j;
    interval valori[256];
    interval aux;
    printf("n: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("[a,b]:\n");
        scanf("%d,%d", &valori[i].a, &valori[i].b);
    }
    for (i = 0; i < n; i++)
    {
        for (j = n-1; j > i; j--)
        {
            if (valori[j].a < valori[j-1].a)
            {
                aux = valori[j];
                valori[j] = valori[j-1];
                valori[j-1] = aux;
            }
        }
    }
    ra = valori[0].a;
    rb = valori[0].b;
    for (i = 1; i < n; i++)
    {
        if (valori[i].a > rb)
        {
            printf("[%d, %d]\n", ra, rb);
            ra = valori[i].a;
            rb = valori[i].b;
        }else if (valori[i].b > rb)
        {
            rb = valori[i].b;
            printf("[%d,%d]\n", ra, rb);
        }
    }

    return 0;
}
