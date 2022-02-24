/* fie o multime ce contine n elemente (n < 25)
sa se afiseze toate submultimile acestei multimi
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, i, ok;
    int lot[100], c[100];
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("lot[%d]: ", i);
        scanf("%d", &lot[i]);
    }
    for (i = 0; i < n; i++)
    {
        c[i] = 0;
    }
    ok = 1;
    while (ok)
    {
        i = n - 1;
        while (c[i] == 1 && i >= 0)
        {
            c[i] = 0;
            i--;
        }
        if (i == -1)
        {
            ok = 0;
        }else
        {
            c[i] = 1;
            printf("\n");
        }
        for (i = 0; i < n; i++)
        {
            if (c[i])
            {
                printf("%d ", lot[i]);
            }
        }
    }
    return 0;
}
