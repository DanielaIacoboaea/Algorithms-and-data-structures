/* tablou unidimensional ce contine un numar par de elemente (2*n)
creati cu aceste valori un sir de n fractii a caror suma este maxima
fiecare fractie se va afisa pe cate o linie printr-o pereche de numere reprezentand in ordine "numarator -numitor"
ex n = 3 si a = (3, 12, 21, 34, 2, 39)
34 3
21 12
39 2
*/

#include <stdio.h>

int main()
{
    int n, size, min, max,aux, i, j;
    int a[15];
    printf("n: ");
    scanf("%d", &n);
    size = 2 * n;
    for (i = 0; i < size; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < size; i++)
    {
        for (j = size-1; j > i; j--)
        {
            if (a[j] > a[j-1])
            {
                aux = a[j];
                a[j] = a[j-1];
                a[j-1] = aux;
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("%d, %d\n", a[i], a[(size-1)-i]);
    }

    return 0;
}
