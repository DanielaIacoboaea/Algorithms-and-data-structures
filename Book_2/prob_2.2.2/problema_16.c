#include <stdio.h>

int a[50], b[50], n;

long Pow(int x, int y)
{
    if (y == 0)
    {
       return 1; 
    }else
    {
        return x* Pow(x, y-1);
    }
}
long E(int i)
{
    if (i < n)
    {
        return Pow(a[i], b[i]) + E(i+1);
    }else
    {
        return 0;
    }
}

int main()
{
    printf("n: ");
    scanf("%d", &n);
    int sum, i;
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("b[%d]: ", i);
        scanf("%d", &b[i]);
    }
    sum = E(0);
    printf("sum: %d\n", sum);
    return 0;
}
