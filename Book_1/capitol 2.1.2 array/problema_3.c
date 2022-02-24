#include <stdio.h>

int main()
{
    int i, n, j, k, a[100];
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]:", i);
        scanf("%d", &a[i]);
    }
    i = 0; 
    j = n - 1;
    while (a[i] == a[j] && i <= j)
    {
        i = i + 1;
        printf("i: %d\n", i);
        j = j - 1;
        printf("j: %d\n", j);
    }
    for (k = i; k <= j; k++)
    {
        printf("%d ", a[k]);
    }
    return 0;
}
