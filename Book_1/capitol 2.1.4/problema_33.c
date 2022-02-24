/* fie un tablou unidimensional cu n elemente valori naturale
sa se ordoneze descrescator aceste valori dupa nr de cifre distincte pe care le contin
ex: n = 7 si a = (334, 124, 21, 34, 222, 1, 39) se va afisa:
124 334 21 34 39 222 1
*/ 

#include <stdio.h>
#include <stdbool.h>

int distinctDigits(int x)
{
    int count = 1, i, rem;
    int arr[10];
    bool ok;
    rem = x % 10;
    x = x/10;
    arr[0] = rem;
    while (x != 0)
    {
        rem = x % 10;
        for (i = 0; i < count; i++)
        {
            if(rem != arr[i])
            {
                ok = 1;
            }else 
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            count++;
            arr[count-1] = rem;
        }
        x = x/10;
    }
    return count;
}

typedef struct numbers
{
    int x;
    int digits;
} numbers;

int main()
{
    numbers a[15];
    int i, n, j, aux;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i].x);
        a[i].digits = distinctDigits(a[i].x);
    }
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j].digits > a[j-1].digits)
            {
                aux = a[j].digits;
                a[j].digits = a[j-1].digits;
                a[j-1].digits = aux;

                aux = a[j].x;
                a[j].x = a[j-1].x;
                a[j-1].x = aux;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i].x);
    }

    return 0;
}
