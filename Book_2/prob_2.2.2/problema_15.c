#include <stdio.h>

int a[50], n;

int C(int x)
{
    if (x < 10)
    {
        return x;
    }else
    {
        return (x/10);
    }
}

void S(int i, int b[50], int d[50], int *k, int *l)
{
    if (i < n)
    {
        if (C(a[i]) % 2 == 0)
        {
            b[*k] = a[i];
            k++;
        }else
        {
            d[*l] = a[i];
            l++;
        }
        S(i+1, b, d, k, l);
    }
}

int main()
{
    int size_b = 0;
    int size_d = 0;
    int i;
    int b[50], d[50];
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    S(0, b, d, &size_b, &size_d);
    printf("vector numere pare\n");
    for (i = 0; i < size_b; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\nvector numere impare\n");
    for (i = 0; i < size_d; i++)
    {
        printf("%d ", d[i]);
    }
    
    return 0;
}
