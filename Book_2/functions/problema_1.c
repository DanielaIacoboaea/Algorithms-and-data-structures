/* n = 5 si tabloul (1, 6, 7, 55, 19) se va afisa 19 - cel mai mare nr prim 
*/

#include <stdio.h>

int is_prim(int a)
{
    int i, count = 0;
    for (i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            count++;
        }
    }
    if (count == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int p(unsigned int x[40], int n)
{
    int i;
    int y = 0;
    for (i = 0; i < n; i++)
    {
        if (is_prim(x[i]) && (x[i] > y))
        {
            y = x[i];
        }
    }
    return y;
}

int main()
{
    unsigned int a[40];
    int n, prim, i;
    long z;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[i]:\n");
        scanf("%d", &a[i]);
    }
    z = p(a, n);
    printf("y: %li\n", z);
    return 0;
}
