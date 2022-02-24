/* se considera un vector cu n elemente intregi.
sa se elimine cat mai putine elemente de la capetele vectorului, ast incat extremitatile 
sa fie valori consecutive.
ex: n = 9; (8, 2,4, 5, 2, 5, 3, 4, 6) se va afisa (2,4,5,2,5,3)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[50];
    int n, i, min, j, p1, p2, x; 
    printf("n: ");
    scanf("%d", &n);
    min = n;
    p1 = 0;
    p2 = -1;
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("i: %d\n", i);
        for (j = n - 1; j >= i; j--)
        {
            printf("j: %d\n", j);
            if (abs(a[i] - a[j]) == 1)
            {
                x = j;
                printf("x: %d\n", x);
                break;
            }
            if (n-x < min)
            {
                min = n - x;
                printf("min: %d\n", min);
                p1 = i;
                printf("p1: %d\n", p1);
                p2 = x;
                printf("p2: %d\n", p2);
            }
        }
    }
    for (i = p1; i <= p2; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
