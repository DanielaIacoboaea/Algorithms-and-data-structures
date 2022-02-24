/* se citesc n < 11 numere de maxim 9 cifre; sa se verifice daca sunt aproape prime (produs de 2 numere prime)
sa se afiseze DA/NU;
*/

#include <stdio.h>
#include <stdbool.h>

int prime_div(int num)
{
    int k, c = 0;
    for (k = 2; k < num; k++)
    {
        if (num % k == 0)
        {
            c++;
        }
    }
    return c;
}

int main()
{
    int n, x, i, j, check_prime, m;
    int numbers[12];
    bool yes = 0;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("x: ");
        scanf("%d", &numbers[i]);
    }

    for (j = 0; j < n; j++)
    {
        check_prime = prime_div(numbers[j]);
        if (check_prime != 0)
        {
            for (m = 2; m < numbers[j]; m++)
            {
                if ((numbers[j] % m == 0) && (prime_div(m) == 0) && (prime_div(numbers[j]/m) == 0))
                {
                    printf("DA! %d se poate scrie ca produs de numere prime: %d, %d\n", numbers[j], m, numbers[j]/m);
                    yes = 1;
                    break;
                }else
                {
                    yes = 0;
                }
            }
        }else
        {
            printf("numarul %d este prim.\n", numbers[j]);
        }
        if (yes == 0)
        {
            printf("NU! %d nu se poate scrie ca produs de numere prime\n", numbers[j]);
        }
    }
    return 0;
}
