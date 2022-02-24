#include <stdio.h>

int n;

void print_even(int i, int a[50])
{
    if (i < n)
    {
        a[i] = 2 * (n-i-1);
        print_even(i+1, a);
    }
}

int main()
{
    int a[50], i;
    printf("n: ");
    scanf("%d", &n);
    print_even(0, a);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
