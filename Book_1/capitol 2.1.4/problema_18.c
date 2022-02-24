/* sa se scrie un program care afiseaza permutarile circulare ale unui vector cu n elemente intregi
o permutare circulara se obtine prin rotirea elementelor vectorului cu i pozitii (i < n)
ex pt n = 4 si vectorul (2,5,3,1) se va afisa
5 3 1 2
3 1 2 5
1 2 5 3
*/

#include <stdio.h>

int main()
{
    int a[50];
    int n, i, count = 1;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    while (count < n)
    {
        for (i = 0; i < n; i++)
        {
            a[n+i] = a[i];
            a[i] = a[i+1];
        }
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        count++;
    }
    return 0;
}
