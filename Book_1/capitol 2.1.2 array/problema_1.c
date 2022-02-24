cd #include <stdio.h>

int main()
{
    int n, i, a[100], temp;
    printf("n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("a[%d] ", i);
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n; i++)
    {
        if (a[i] > a[i+1])
        {
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
    for (i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
