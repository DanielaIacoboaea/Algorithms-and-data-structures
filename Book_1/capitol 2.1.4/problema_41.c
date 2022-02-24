/* se considera doi vectori de lungime n respectiv m ce contine elemente naturale ordonate crescator
se cere interclasarea valorilor pare din cei doi vectori 
in urma interclasarii elementele vor fi plasate intr-un nou vector
ex: n = 8; m = 5; a =(13, 26, 44, 54, 112, 115, 311, 600) si b =(3, 28, 48, 55, 56) se va afisa
26, 28, 44, 48, 54, 112, 600
*/

#include <stdio.h>

int main()
{
    int a[15], b[15], c[15];
    int i, j, aux, n, m, k, l;
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (j = 0; j < m; j++)
    {
        printf("b[%d]: ", j);
        scanf("%d", &b[j]);
    }
    l = 1;
    k = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            c[k] = a[i];
            k++;
            l++;
        }
    }
    for (j = 0; j < m; j++)
    {
        if (b[j] % 2 == 0)
        {
            c[k] = b[j];
            k++;
            l++;
        }
    }
    for (k = 0; k < l - 1; k++)
    {
        for (i = l - 2; i > k; i--)
        {
            if (c[i] < c[i-1])
            {
                aux = c[i];
                c[i] = c[i-1];
                c[i-1] = aux;
            }
        }
    }
    for (k = 0; k < l - 1; k++)
    {
        printf("%d ", c[k]);
    }

    return 0;
}
