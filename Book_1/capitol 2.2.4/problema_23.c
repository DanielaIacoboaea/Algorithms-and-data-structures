/* se considera un tablou bidimensional cu n linii si n coloane 
cele doua diagonale impart tabloul in patru regiuni in forma de triunghi
se cere sa se det  suma componentelor din interiorul fiecarei zone
ex: n = 5

0 1 1 1 0
2 0 1 0 3
2 2 0 3 3
2 0 4 0 3
0 4 4 4 0

se va afisa:
suma(z1) = 4
suma(z2) = 8
suma(z3) = 12
suma(z4) = 16
*/

#include <stdio.h>

int main()
{
    int i, j, n, s_z1 = 0, s_z2 = 0, s_z3 = 0, s_z4 = 0;
    int a[15][15];
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n/2; i++)
    {
        for (j = i+1; j < n-1-i; j++)
        {
            s_z1 = s_z1 + a[i][j];
        }
    }
    printf("suma(z1) = %d\n", s_z1);

    for (i = 1; i < n-1; i++)
    {
        for (j = n/2 - 1; j >= 0; j--)
        {
            if (i == j)
            {
                j--;
            }else if (j == n-1-i)
            {
                j--;
            }
            s_z2 = s_z2 + a[i][j];
        }
    }
    printf("suma(z2) = %d\n", s_z2);

    for (i = 1; i < n-1; i++)
    {
        for (j = n/2 + 1; j < n; j++)
        {
            if (i == j)
            {
                j++;
            }else if (j == n-1-i)
            {
                j++;
            }
            s_z3 = s_z3 + a[i][j];
        }
    }
    printf("suma(z3) = %d\n", s_z3);

    for (i = n-1; i >n/2; i--)
    {
        for (j = i-1; j > 0; j--)
        {
            s_z1 = s_z1 + a[i][j];
            if (i == j)
            {
                j--;
            }else if (j == n-1-i)
            {
                j--;
            }
            s_z4 = s_z4 + a[i][j];
        }
    }
    printf("suma(z4) = %d\n", s_z4);
    return 0;
}
