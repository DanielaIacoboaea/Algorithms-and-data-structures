/* se dau doua numere naturale nenule cu cel mult 10 cifre
se cere sa se afiseze cifrele comune
ex: pt numerele 12323234 si 657284 se va afisa 2 4.
*/

#include <stdio.h>

int verifica_cifra(int d, int x)
{
    int r;
    while (x != 0 )
    {
        r = x % 10;
        if (d == r)
        {
            return 1;
        }
        x = x/10;
    }
    return 0;
}

int main()
{
    //int a, b, r, rest, count_a = 0, count_b = 0;
    int a, b, i; 
    printf("numar a: ");
    scanf("%d", &a);
    printf("numar b: ");
    scanf("%d", &b);
    for (i = 0; i <= 9; i++)
    {
        if (verifica_cifra(i, a) && verifica_cifra(i, b))
        {
            printf("%d ", i);
        }
    }
    return 0;
}
/*
    int arr_a[10];
    int arr_b[10];
    int i = 0, j = 0;
    while (a != 0 || b != 0)
    {
        r = a % 10;
        arr_a[i] = r;
        i++;
        count_a++;
        rest = b % 10;
        arr_b[j] = rest;
        j++;
        count_b++;
        a = a/10;
        b = b/10;
    }
    
    for (i = 0; i < count_a; i++)
    {
        for (j = 0; j < count_b; j++)
        {
            if (arr_a[i] == arr_b[j])
            {
                printf("%d ", arr_a[i]);
            }
        }
    }
    return 0;
}
*/
