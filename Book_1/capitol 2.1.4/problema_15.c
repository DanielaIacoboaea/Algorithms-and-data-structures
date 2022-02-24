/* determinati multimea ce se formeaza cu elementele unui vector
de ex: n = 6 si vectorul (3, 13, 3, 13, 8, 13) se va afisa 3 13 8
*/

#include <stdio.h>

int main()
{
    int a[15], b[15], c[15];
    int i, j, n, count = 0;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        b[i] = 0;
        c[i] = a[i];
    }
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (c[j] < c[i])
            {
                b[i]++;
            }else
            {
                b[j]++;
            }
        }
    }
    
    for (i = 0; i < n; i++)
    {
        a[b[i]] = c[i];
    }
    printf("%d ", a[0]);
    for (i = 0; i < n - 1; i++)
    {
        if (a[i+1] != a[i])
        {
            printf("%d ", a[i+1]);
        }
    }

    return 0;
}


