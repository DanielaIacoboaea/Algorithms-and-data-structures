/* det suma maxima care se poate forma cu m numere distincte dintr-un vector ce contine n valori intregi.
daca vectorul contine mai putin de m valori distincte se va afisa mesajul Impoibil
ex: n = 6 si m = 2 si vectorul (3, 13, 3, 13, 8, 13) se va afisa 21
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a[50], b[50];
    int i, j, sum = 0, sum_max = 0, n, m, l_b, count = 0, aux;
    bool ok;
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    l_b = 0;
    b[0] = a[0];
    for (i = 1; i < n; i++)
    {
        ok = 0;
        for (j = 0; j <= l_b; j++)
        {
            if(a[i] == b[j])
            {
                ok = 1;
            }
        }
        if (ok == 0)
        {
            l_b++;
            b[l_b] = a[i];
        }
    }
    
    if (l_b < m)
    {
        printf("Imposibil!\n");
    }
    for (i = 0; i <= l_b; i++)
    {
        for (j = l_b; j > i; j--)
        {
            if (b[j] < b[j-1])
            {
                aux = b[j];
                b[j] = b[j-1];
                b[j-1] = aux;
            }
        }
    }
    for (i = 0; i <= l_b; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    if (l_b < m)
    {
        printf("Imposibil!\n");
    } else 
    {
        for (i = l_b; i > l_b - m; i--)
        {
            sum = sum + b[i];
        }
    }
    printf("sum: %d\n", sum);

    return 0;
}
