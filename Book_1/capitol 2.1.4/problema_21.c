/* se considera un vector ce contine n (n< 100) numere naturale cu valori intre 0 si 60000
sa se ordoneze elementele pare fara insa a afecta pozitiile pe care sunt situate numerele impare
programul va afisa vectorul dupa ordonare 
evitati folosirea unui vector auxiliar
ex n = 7 si sirul (1, 40, 32, 44, 3, 8, 17) se va afisa: 1 8 32 40 3 44 17.
*/

#include <stdio.h>

int main()
{
    int a[100]; 
    int i, j, n, aux;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n - 1; i++)
    {
        if (a[i] % 2 == 0)
        {
            for (j = 0; j < i; j++)
            {
                if (a[j] % 2 == 0)
                {
                    if (a[j] > a[i])
                    {
                        aux = a[j];
                        a[j] = a[i];
                        a[i] = aux;
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
}
