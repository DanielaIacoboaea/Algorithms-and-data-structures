#include <stdio.h>

int a[50], n;

int ok(int x, int i)
{
    if (i >x/2)
    {
        return 1;
    }else
    {
        if (x % 2 == 0)
        {
            return 0;
        }else
        {
            return ok(x, i+1);
        }
    }
}

int nr(int i, int k)
{
    if (i < n)
    {
        printf("i: %d\n", i);
        printf("a[i]: %d\n", a[i]);
        if (ok(a[i], 2))
        {
            k++;
            printf("k: %d\n", k);
        }
        return nr(i+1, k);
    }else
    {
        return k;
    }
}

int main()
{
    int i, count = 0;
    //int *p = &count;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    //nr(0, count);
    printf("nr: %d\n", nr(0, 0));
    return 0;
}
