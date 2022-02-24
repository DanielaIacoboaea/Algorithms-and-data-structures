#include <stdio.h>

int main()
{
    int a[100];
    int max = 1, i, n;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("%d\n", a[0]);
    for (i = 1; i < n; i++)
    {
        if (a[i] < a[i-1])
        {
            max++;
            printf(" * %d", a[i]);
        }else 
        {
            printf("%d ", a[i]);
        }
    }
    printf("max: %d\n", max);
    return 0;
}
