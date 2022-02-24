//counting sort 

#include <stdio.h>

int main()
{
    int a[100], b[100], c[100];
    int i, n, j, ok;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        b[i] = 0;
        c[i] = a[i]; 
    }
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (c[j] < c[i])
            {
                b[i]++;
            }else 
            {
                b[j]++;
            }
        }
    }
    printf("a[i]: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n b[i]: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n c[i]: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }
    for (i = 0; i < n; i++)
    {
        a[b[i]] = c[i];
    }
    printf("a[i] sortat: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
