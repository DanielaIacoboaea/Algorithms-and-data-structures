/* sa se afiseze primele n numere naturale are au cifra de control egala cu cu cifra x
citita de la tastatura. cifra de control a unui numar se obtine prin insumarea cifrelor din scriere zecimala a numarului
apoi se insumeaza cifrele acestei sume s.a.m.d pana cand suma obtinuta este exprimata printr-o. 
de ex: nr 28997 are cifra de control 9 (2 + 8 + 9 + 9 + 7 = 35, 3 + 5 = 8).
ex: pt n = 2 si x = 3 se va afisa 3, 12
*/ 

#include <stdio.h>

int break_digit_sum(int num)
{
    int r, s = 0;
    while (num != 0)
    {
        r = num % 10;
        s = s + r;
        num = num / 10;
    }
    return s;
}

int one_digit(int sums)
{
    for (int j = 0; j <= 9; j++)
    {
        if (sums == j)
        {
            return 1;
        } 
    }
    return 0;
}

int main()
{ 
    int n, x, sum, i;
    printf("n: ");
    scanf("%d", &n);
    printf("x: ");
    scanf("%d", &x);
    i = 1;
    int count = 0;
    while (count < n)
    {
        sum = break_digit_sum(i);
        while (one_digit(sum) == 0)
        {
            sum = break_digit_sum(sum);
            if (one_digit(sum))
            {
                break;
            }
        }
        if (one_digit(sum) && (sum == x))
        {
            printf("%d ", i);
            count++;
        }
        i++;
    }
    return 0;
}
