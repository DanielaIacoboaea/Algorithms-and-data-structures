#include <stdio.h>

int n, a[20][20];

void inv(int l, int i, int j)
{
    int x;
    if (i <= j)
    {
        x = a[l][i];
        a[l][i] = a[l][j];
        a[l][j] = x;
        inv(l, i+1, j-1);
    }
}

void M(int i, int k)
{
    if (i < n)
    {
        inv(i, 0, k-1);
        inv(i, 0, n-1);
        inv(i, 0, n-k-1);
        M(i+1, k);
    }
}

int main()
{
    int i, j;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a: \n");
            scanf("%d", &a[i][j]);
        }
    }
    M(0, 3);
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
