#include <stdio.h>

void sort(int p, int q, int a[10])
{
    int m;
    if (a[p] > a[q])
    {
        m = a[p];
        a[p] = a[q];
        a[q] = m;
    }
}

void interc(int p, int q, int m, int a[10])
{
    int b[10], i, j, k;
    i = p;
    j = m+1;
    k = 1;
    while (i <= m && j <= q)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i = i+1;
            k = k+1;
        }else{
            b[k] = a[j];
            j = j+1;
            k = k+1;
        }
    }
    if(i <= m )
    {
        for (j = i; j <=m; j++)
        {
            b[k] = a[j];
            k = k+1;
        }
    }else{
        for(i = j; j<= q; j++)
        {
            b[k] = a[i];
            k = k+1;
        }
    }
    k = 1;
    for (i = p; i < q; i++)
    {
        a[i] = b[k];
        k = k+1;
    }
}

void divimp(int p, int q, int a[10])
{
    int m;
    if((q-p)<=1)
    {
        sort(p,q,a);
        
    }else
    {
        m = (p+q)/2;
        divimp(p,m,a);
        divimp(m+1,q,a);
        interc(p,q,m,a);
    }
}

int main()
{
    int a[10];
    int i, n;
    printf("n: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    divimp(1, n, a);

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}