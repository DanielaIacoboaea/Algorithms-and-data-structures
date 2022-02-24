#include <stdio.h>

int main()
{
    int i, j, n;
    int a[2][2];
    int *p = &a[0][0];
    printf("n: ");
    scanf("%d", &n);
    printf("%p\n", &a[0][0]);
    printf("%p\n", &a[0][1]);
    printf("%p\n", &a[1][0]);
    printf("%p\n", &a[1][1]);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n*n; i++)
    {
        printf("%d ", *(p+i));
    }
    printf("\n%d ", a[1][0]);
    //printf("%d ", *(p+1));
    return 0;
}
