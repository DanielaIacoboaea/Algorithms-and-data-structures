#include <stdio.h>

int n;

int T(int x)
{
    if (x == 0)
    {
        return 0;
    }else
    {
        if (x % 2 == 0)
        {
            return x % 10 + 10 * T(x/10);
        }else
        {
            return T(x/10);
        }
    }
}

void M(int i)
{
    int x;
    if (i <= n)
    {
        printf("x: ");
        scanf("%d", &x);
        M(i+1);
        printf("%d ", T(x));
    }
}

int main()
{
    printf("n: ");
    scanf("%d", &n);
    M(1);
    return 0;
}
