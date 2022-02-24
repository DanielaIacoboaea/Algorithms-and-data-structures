#include <stdio.h>

int a[50], n;

int nr(int x, int c)
{
    if (x == 0)
    {
        return 0;
    }else
    {
        if (x % 10 == c)
        {
            return nr(x/10, c) + 1;
        }else
        {
            return nr(x/10, c);
        }
    }
}

int mx(int x)
{
    if (x == 0)
    {
        return 0;
    }else
    {
        if (x % 10 > mx(x/10))
        {
            return x % 10;
        }else
        {
            return mx(x/10);
        }
    }
}

void cm(int i, int *c, int *m)
{
    if (i < n)
    {
        if (mx(a[i]) > *c)
        {
            *c = mx(a[i]);
            *m = nr(a[i], *c);
        }
    }else
    {
        if (mx(a[i]) == *c)
        {
            *m = *m + nr(a[i], *c);
        }
    }
    cm(i+1, c, m);
}

int main()
{
    int i, max_d, max_count;
    int *p = &max_d;
    int *p_count = &max_count;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    cm (0, p, p_count);
    printf("c: %d, m: %d\n", *p, *p_count);
    return 0;
}
