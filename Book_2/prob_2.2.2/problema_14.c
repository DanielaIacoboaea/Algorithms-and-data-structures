#include <stdio.h>

void S(int n, int i, int j)
{
    if (i <= n)
    {
        if (j <= i)
        {
            printf("* ");
            S(n, i, j+1);
        }else
        {
            printf("\n");
            S(n, i+1, 1);
        }
    }else
    {
        if (i <= 2*n)
        {
            if (j < 2*n-i+1)
            {
                printf("* ");
                S(n, i, j+1);
            }
        }else
        {
            printf("\n");
            S(n, i+1, 1);
        }
    }
}

int main()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    S(n, 1, 1);
    return 0;
}
