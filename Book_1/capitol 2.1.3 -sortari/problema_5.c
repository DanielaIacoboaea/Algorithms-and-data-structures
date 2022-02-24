/* fie n un numar natural de cel mult 9 cifre. 
sa se genereze toate numerele care se pot scrie ca produs de 2 numere prime < n; 
*/

#include <stdio.h>

int check_prime(int x)
{
    int k, sum = 0;
    for (k = 2; k < x; k++)
    {
        if (x % k == 0)
        {
            sum++;
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, i, j, prod, count = 0;
    printf("n: ");
    scanf("%d", &n);
    int primes[n/2];
    
    for (i = 2; i < n; i++)
    {
        if (check_prime(i))
        {
            primes[count] = i;
            count += 1;
        }
    }
    for (i = 0; i < count; i++)
    {
        printf("%d ", primes[i]);
    }
    printf("\n");
    for (i = 1; i < count; i++)
    {
        for (j = 0; j < i; j++)
        {
            prod = primes[j] * primes[i];
            printf("%d * %d = %d\n", primes[j], primes[i], prod);
        }
    }
    return 0;
}
