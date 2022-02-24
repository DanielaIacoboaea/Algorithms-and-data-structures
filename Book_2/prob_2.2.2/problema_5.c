#include <stdio.h>

int a[15], b[15];
int n;

int Ok(int x, int i, int k)
{
    if (i >= k)
    {
        return 0;
    }else
    {
        if (x == b[i])
        {
            return 1;
        }else
        {
            return Ok(x, i+1, k);
        }
    }
}

void Det(int i, int *k)
{
    if (i < n)
    {
        if (!Ok(a[i], 0, *k))
        {
            k++;
            b[*k-1] = a[i];
        }
        Det(i+1, k);
    }
}

int main()
{
    int i, j = 0;
    int *size = &j;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    Det(0, size);
    for (i = 0; i < *size; i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}
