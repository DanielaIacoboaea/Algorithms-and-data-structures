#include <stdio.h>

int t[50][50], sol[50], drum[50], n, max = 0, s;

void back(int k)
{
    int i, j;
    s = t[1][1];
    printf("s initial: %d\n", s);
    if (k == n+1)
    {
        for (i = 2; i <=n; i++)
        {
            s = s + t[i][sol[i]];
            printf("s: %d\n", s);
        }
        if (s > max)
        {
            printf("%d s din if\n", s);
            for (i = 1; i <=n; i++)
            {
                drum[i] = t[i][sol[i]];
            }
            max = s;
        }
    }else
    {
        for (i = sol[k-1]; i<= sol[k-1] + 1; i++)
        {
            sol[k] = i;
            back(k+1);
        }
    }
}

int main()
{
    int i, j;
    printf("n: \n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("t[%d][%d]: \n", i, j);
            scanf("%d", &t[i][j]);
        }
    }
    sol[1] = 1;
    back(2);
    printf("suma maxima: %d\n", max);
    for(i = 1; i<=n; i++)
    {
        printf("%d ", drum[i]);
    }
    return 0;
}