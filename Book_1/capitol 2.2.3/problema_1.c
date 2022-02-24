/* completati elementele unui tablou bidimensional patratic de ordin n
sub forma unor patrate concentrice de valori consecutive, incepand cu 1
ex: n = 4 elementele tabloului vor fi:

1 1 1 1 
1 2 2 1 
1 2 2 1
1 1 1 1

*/

#include <stdio.h>

int main()
{
    int i, j, n, x, p, up_to;
    int a[15][15];
    printf("n: ");
    scanf("%d", &n);
    x = 1;
    p = 0;
    up_to = n;
    while (x <= (n+1)/2)
    {
        for (i = p; i < up_to; i++)
        {
            for (j = p; j < up_to; j++)
            {
                a[i][j] = x;
            }
        }
        x++;
        p++;
        up_to--;
    }

    /*for (i = 1; i < n -1; i++)
    {
        for (j = 1; j < n - 1; j++)
        {
            a[i][j] = x;
        }
    }*/

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

