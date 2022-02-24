#include <stdio.h>

int main()
{
    int nr[10];
    int c, max = 0, i, n, j, x;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < 10; i++)
    {
        nr[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        printf("j: ");
        scanf("%d",&j);
        while (j != 0)
        {
            x = j % 10;
            nr[x] = nr[x] + 1;
            if (max < nr[x])
            {
                max = nr[x];
                c = x;
            }
            j = j/10;
        }
    }
    printf("%d\n", c);
    return 0;
}
