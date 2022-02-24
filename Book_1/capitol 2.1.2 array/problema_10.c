#include <stdio.h>

int main()
{
    int a[100];
    int max, i, n, k, x, nr = 1;
    printf("n: ");
    scanf("%d", &n);
    printf("a[1]: ");
    scanf("%d", &a[0]);
    for (i = 1; i < n; i++)
    {
        printf("x: ");
        scanf("%d", &x);
        k = 0;
        while (x <= a[k] && k < nr)
        {
            k = k + 1;
        }
        if (k == nr + 1)
        {
            nr = nr + 1;
        }
        a[k] = x;
    }
        
    for (i = 0; i < nr; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
