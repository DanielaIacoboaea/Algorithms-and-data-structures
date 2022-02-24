#include <stdio.h>

int main()
{
    int i, n = 0, x;
    int a[100];
    printf("x: ");
    scanf("%d", &x);

    while (x != 0)
    {
        a[n] = x % 10;
        x = x/10;
        n++;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
