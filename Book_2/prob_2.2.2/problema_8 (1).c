#include <stdio.h>

int m, n;

int nr(int x, int c)
{
    if (x == 0)
    {
        return 0;
    }else
    {
        if (x % 10 == c)
        {
            return nr(x/10, c) + 1;
        }else
        {
            return nr (x/10, c);
        }
    }
}

int D(int x, int i)
{
    if (i > 9)
    {
        return 0;
    }else
    {
        if (nr(x, i) >= 1)
        {
            return D(x, i+1) + 1;
        }else
        {
            return D(x, i+1);
        }
    }
}

void P(int i, int *max)
{
    int x, y;
    if (i <= n)
    {
        printf("x: \n");
        scanf("%d", &x);
        y = D(x, 0);
        if (y > *max)
        {
            *max = y;
        }
        P(i+1, max);
        if (*max == y)
        {
            printf("%d \n", x);
        }
    }
}
int main()
{
    m = 0;
    printf("n: ");
    scanf("%d", &n);
    P(1, &m);
    return 0;
}
