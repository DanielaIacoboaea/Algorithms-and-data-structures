/* valori panta - cifrele privite de la stanga la dreapta sau invers sunt in ordine crescatoare 
se citeste N numere naturale <= 30 cu maxim 8 cifre; 
sa se afiseze cate elemente din sir sunt numere panta 
sa se afiseze cel mai mare si cel mai mic nr panta; daca nu exista, a se afiseze nu exista;
*/

#include <stdio.h>
#include <stdbool.h>

bool nr_panta(int x)
{
    int r, comp = 9;
    bool ok = 1;
    while (x != 0)
    {
        r = x % 10;
        if (comp > r)
        {
            ok = 1;
        }else 
        {
            ok = 0;
            break;
        }
        comp = r;
        x = x / 10;
    }
    return ok;
}

bool nr_rampa(int y)
{
    int rest, c = 0;
    bool ok = 1;
    while (y != 0)
    {
        rest = y % 10;
        if (c < rest)
        {
            ok = 1;
        }else 
        {
            ok = 0;
            break;
        }
        c = rest;
        y = y / 10;
    }
    return ok;
}
int main()
{
    int n, i, j, count = 0, min = 99999999, max = 0;
    int numbers[30];
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("x: ");
        scanf("%d", &numbers[i]);
    //min = numbers[0];
    //max = numbers[0];
        if (nr_panta(numbers[i]))
        {
            printf("nr este in panta: %d\n", numbers[i]);
            count++;
            if (numbers[i] < min)
            {
                min = numbers[i];
            }
            if (numbers[i] > max)
            {
                max = numbers[i];
            }
        }
        if (nr_rampa(numbers[i]))
        {
            printf("nr este in rampa: %d\n", numbers[i]);
            count++;
            if (numbers[i] < min)
            {
                min = numbers[i];
            }
            if (numbers[i] > max)
            {
                max = numbers[i];
            }
        }
    }
    if (count == 0)
    {
        printf("nu exista numere in panta.\n");
    }else 
    {
        printf("numarul de valori-panta este: %d\n", count);
    }
    if (min != 99999999)
    {
        printf("cea mai mica valoare-panta este: %d\n", min);
    }
    if (max != 0)
    {
        printf("cea mai mare valoare-panta este: %d\n", max);
    }
    return 0;
}
