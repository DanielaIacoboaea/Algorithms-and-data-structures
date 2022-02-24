#include <stdio.h>

int max(int i, int j, int v[10])
{
    printf("i: %d, j: %d\n", i, j);
    int a, b;
    if(i==j)
    {
        printf("aaaa\n");
        printf("if i==j, i: %d j %d: \n", i, j);
        printf("v[%d]: %d\n", i, v[i]);
        return v[i];
    }else
    {
        printf("else: i: %d, j: %d\n", i, j);
        printf("bbbbb\n");
        a = max(i, (i+j)/2, v);
        printf("else a: %d\n", a);
        b = max((i+j)/2+1, j, v);
        printf("else b: %d\n", b);
        printf("else a: %d, b: %d\n", a, b);
        if (a>b)
        {
            printf("a> b if  i: %d, j: %d\n", i, j);
            printf("CCCCC\n");
            printf("else if a: %d\n", a);
            return a;
        }else{
            printf("a> b else i: %d, j: %d\n", i, j);
            printf("DDDDDD\n");
            printf("else if b: %d\n", b);
            return b;
        }
    }
}

int main()
{
    int n, i, maxim;
    int v[10]; 
    printf("n: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    maxim = max(1, n, v);

    printf("maxim: %d\n", maxim);

    return 0;
}