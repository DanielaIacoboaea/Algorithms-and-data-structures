#include <stdio.h>

int main()
{
    int v[20], l[20];
    int i, n, max, k, t;

    printf("n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("v[%d]: \n", i);
        scanf("%d", &v[i]);
    }

    l[n] = 1;

    for(k = n-1; k >=1; k--)
    {
        max = 0;
        for (i = k+1; i <= n; i++)
        {
            if(v[i] >= v[k] && l[i] > max)
            {
                max = l[i];
            }
        }
        l[k] = 1+ max;
    }

    max = l[1];
    t = 1;

    for(k = 1; k <= n; k++)
    {
        if(l[k] > max)
        {
            max = l[k];
            t = k;
        }
    }
    printf("lungimea maxima: %d\n", v[t]);

    for(i = t+1; i<=n; i++)
    {
        if(v[i] >= v[t] && l[t] == max-1)
        {
            printf("%d ", v[i]);
            max--;
        }
    }

    return 0;
}