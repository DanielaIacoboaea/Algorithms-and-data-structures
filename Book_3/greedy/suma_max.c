#include <stdio.h>

void greedy_max(int a[20], int b[20], int* length, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            (*length)++;
            printf("length: %d\n", *length);
            b[*length] = a[i];
        }
    }
}

int main()
{
    int n, m = -1, i;
    int a[20], b[20];
    printf("n:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("a[%d]: \n", i);
        scanf("%d", &a[i]);
    }

    greedy_max(a, b, &m, n);

    for(i = 0; i <=m; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}