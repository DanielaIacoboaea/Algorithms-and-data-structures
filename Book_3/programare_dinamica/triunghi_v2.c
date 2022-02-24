#include <stdio.h>

int main()
{
    int t[50][50], c[50][50], drum[50][50];
    int n, i, j;

    printf("n: \n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("t[%d][%d]: ", i, j);
            scanf("%d", &t[i][j]);
        }
    }

    for (j = 1; j <= n; j++)
    {
        c[n][j] = t[n][j];
    }

    for(i = n - 1; i >= 1; i--)
    {
        for(j = 1; j <= i; j++)
        {
            if (c[i+1][j] <  c[i+1][j+1])
            {
                c[i][j] = t[i][j]+ c[i+1][j+1];
                drum[i][j] = j+1;

            }else{
                c[i][j] = t[i][j] + c[i+1][j];
                drum[i][j] = j;
            }
        }
    }

    printf("suma maxima: %d\n", c[1][1]);

    i = 1;
    j = 1;

    while (i <= n)
    {
        printf("%d ", t[i][j]);
        j = drum[i][j];
        i++;
    }

    return 0;
}