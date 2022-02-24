#include <stdio.h>

int n;

int T(int x)
{
    if (x <= 1)
    {
        return 1;
    }else
    {
        return x + T(x-1);
    }
}

void M(int i, int j, int a[20][20])
{
    if (i < n)
    {
        if (j < n)
        {
            a[i][j] = T(n * i + j + 1);
            M(i, j+1, a);
        }
    }else
    {
        M(i+1, 0, a);
    }
}

int main()
{
    int i, a[20][20], j;
    printf("n: ");
    scanf("%d", &n);
    M(0, 0, a);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
