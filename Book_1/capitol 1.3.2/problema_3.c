/* sir 7, 17, 37, 47, 67, 97, 107, 127, 137, 157, 167...;
deduceti regula dupa care sunt generati termenii sirului si afisati pe ecran al n-lea termen din sir (n < 2001)
ex: n = 10 se afiseaza 157;
cred ca regula este ca sunt numere prime care se termina in 7;
*/

#include <stdio.h>

int check_prime(int x)
{
    int i, sum = 0;
    for (i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            sum++;
        }
    }
    if (sum == 0)
    {
        return 1;
    }else 
    {
        return 0;
    }
}

int main()
{
    int n, j = 0, num;
    printf("n: ");
    scanf("%d", &n);
    for (num = 0; j <= n; num++)
    {
        if (check_prime(num) && num % 10 == 7)
        {
            //printf("%d ", num);
            j++;
            if (j == n)
            {
                printf("%d \n", num);
            }
        }
    }
    return 0;
}
