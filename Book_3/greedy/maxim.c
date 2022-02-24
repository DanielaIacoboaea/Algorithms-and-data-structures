#include <stdio.h>

void sorteaza(int a[20], int n)
{
    int temp, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = n-1; j > i; j--)
        {
            if (a[j] < a[j-1])
            {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}


int main()
{
    int a[20], b[20];
    int m, n, i, suma = 0;
    printf("m,n: \n");
    scanf("%d,%d", &m, &n);
    for(i = 0; i < m; i++)
    {
        printf("a[%d]: \n", i);
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n; i++)
    {
        printf("b[%d]: \n", i);
        scanf("%d", &b[i]);
    }

    sorteaza(a, m);
    sorteaza(b, n);

    for(i = 0; i < m; i++)
    {
        suma = suma + (a[i] * b[n-m+1]);
    }
    printf("E: %d\n", suma);

    return 0;
}