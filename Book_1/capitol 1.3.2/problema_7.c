/* exponent; n < 101; o cifra k {2,3,5,7}
sa se afiseze exponentul lui k in descompunerea in factori primi ai prod 1 * 2 * 3 *... *n;
ex: 
n = 6; 
k = 3 se va afisa 2;
*/

#include <stdio.h>

int main()
{
    int n, k, nr, expo, i;
    printf("n, k ");
    scanf("%d,%d", &n, &k);
    for (i = 1; i <= n; i++)
    {
        printf("i: %d\n", i);
        nr = i;
        while (nr % k == 0)
        {
            expo = expo + 1;
            printf("expo: %d\n", expo);
            nr = nr/k;
            printf("nr: %d\n", nr);
        }
    }
    printf("expo: %d\n", expo);
    return 0;
}
