/* se considera un vector ce contine numere reale. 
vom spune ca doua elemente ale sale formeaza o pereche in dezordine daca sunt indeplinite simultan conditiile:
- i < j
- a[i] > a[j], unde 1 <= i < n si 1<= j <= n;
sa se creeze un program care afiseaza perechile in dezordine din vector si nr lor
ex: n = 4 si vectorul 1, 13, 2, 4 se va afisa: 
13 2
13 4
2
*/

#include <stdio.h>

int main()
{
    int a[15];
    int i, j, sum = 0, n;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                printf("%d, %d\n", a[i], a[j]);
                sum++;
            }
        }
    }
    printf("\n%d perechi.\n", sum);

    return 0;
}
