#include <stdio.h>

int x;

int fib(int n)
{
    if (n <= 2)
    {
        return 1;
    }else
    {
        return fib(n-1) + fib(n-2);
    }
}

void gen(int v, int n)
{
    int y;
    if (fib(n+1) <= v)
    {
        gen(v, n+1);
    }else
    {
        y = fib(n);
        printf("%d ", y);
        if (v-y > 0)
        {
            gen(v-y, 0);
        }
    }
}

int main()
{
    printf("x: ");
    scanf("%d", &x);
    gen(x, 0);
    return 0;
}
