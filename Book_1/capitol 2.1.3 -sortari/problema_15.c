/* se considera un vector ce contine elemente naturale din intervalul [c1.. c2]
(c2 - c1 < 10000); c1, c2 < 30000. sa se ordoneze valorile tabloului folosind sortarea
prin numararea aparitiilor fiecarui element (count sort);
*/

#include <stdio.h>

int main()
{
    int a[10000], ap[10000];
    int max, c1, c2, n, i, j, x, min, k;
    printf("c1,c2,n: ");
    scanf("%d,%d,%d", &c1, &c2, &n);
    max = c1;
    min = c2;
    for (i = 1; i <= n; i++)
    {
        
        printf("x: ");
        scanf("%d", &x);        
        printf("i: %d\n", i);
        ap[x-c1]++;
        printf("ap[x-c1]: %d\n", ap[x-c1]);
        if (x > max)
        {
            max = x;
            printf("max din if: %d\n", max);
        }
        if (x < min)
        {
            min = x;
            printf("min din if: %d\n", min);
        }
    }
    k = 0; 
    max = max-c1; 
    min = min - c1;
    for (i = min; i<=max; i++)
    {
        for (j = 1; j <= ap[i]; j++)
        {
            a[++k] = i + c1;
            printf("%d ", a[k]);
        }
    }
    return 0;
}
