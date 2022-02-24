#include <stdio.h>

int n, a[50];

int min(int i)
{
    printf("i: %d\n", i);
    if (i == n-1) 
    {
        return a[n-1];
    }else
    {
        printf("a[i]: %d\n", a[i]);
        printf("min(i+1): %d\n", min(i+1));
        if (a[i] < min(i+1))
        {
            return a[i];
        }else
        {
            return min (i+1);
        }
    }
}

int main()
{
    int i;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("%d\n", min(0));
    return 0;
}
