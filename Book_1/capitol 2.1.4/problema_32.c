/* se considera un vector cu n elemente naturale
sa se afiseze pe linii, elementele din a grupate dupa cifra dominanta (prima in scrierea zecimala)
pe aceeasi linie vor fi scrise elemente cu aceeasi cifra dominanta
ex: n = 7 si a = {334, 124, 21, 34, 122, 1, 39} se va afisa:

124 122 1 
21 
334 34 39
*/

#include <stdio.h>
#include <stdbool.h>

int firstDigit(int x)
{
    int rem;
    while (x != 0)
    {
        rem = x % 10;
        x = x/10;
    }
    return rem;
}

typedef struct number
{
    int x;
    int digit;
} number;

int main()
{
    number a[15];
    int n, i, j;
    bool ok;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i].x);
        a[i].digit = firstDigit(a[i].x);
    }
    
    for (i = 1; i < 10; i++)
    {
        ok = 0;
        for (j = 0; j < n; j++)
        {
            if(a[j].digit == i)
            {
                printf("%d ", a[j].x);
                ok = 1;
            }
        }
        if (ok)
        {
            printf("\n");
        }
    }
    return 0;
}
