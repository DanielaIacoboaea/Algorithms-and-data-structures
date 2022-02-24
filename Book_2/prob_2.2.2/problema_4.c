#include <stdio.h>
int a[15], b[15], c[30];
int n, m;

void inter(int i, int j, int k)
{
    if (i < n && j< m)
    {
        printf("a[i]: %d, b[j]: %d\n", a[i], b[j]);
        if (a[i] < b[j])
        {
            c[k] = a[i];
            printf("c[k]: %d\n", c[k]);
            inter(i+1, j, k+1);
        }else
        {
            c[k] = b[j];
            printf("c[k]: %d\n", c[k]);
            inter(i, j+1, k+1);
        }
    }else
    {
        if (i < n)
        {
            c[k] = a[i];
            printf("c[k]: %d\n", c[k]);
            inter(i+1, j, k+1);
        }else
        {
            if (j < m)
            {
                c[k] = b[j];
                printf("c[k]: %d\n", c[k]);
                inter(i, j+1, k+1);
            }
        }
    }
}

int main()
{
    int i, j, k;
    printf("n,m:\n");
    scanf("%d,%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (j = 0; j < m; j++)
    {
        printf("b[%d]: ", j);
        scanf("%d", &b[j]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (j = 0; j < m; j++)
    {
        printf("%d ", b[j]);
    }
    printf("\n");
    inter(0,0,0);
    for (k = 0; k < n+m; k++)
    {
        printf("%d ", c[k]);
    }
    return 0;
}
