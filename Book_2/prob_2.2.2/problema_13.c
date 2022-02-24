#include <stdio.h>

int n;

void S(int i, int j)
{
    if (i <= n)
    {
        if (j < 2*i - 1)
        {
            printf("%d ", j);
            S(i, j+1);
        }
    }else
    {
        printf("\n");
        S(i+1, 1);
    }
}

int main()
{
    printf("n: ");
    scanf("%d", &n);
    S(1, 1);
    return 0;
}
