/* n elemente vector
sa se realizeze un program care sterge elementele situate intre prima aparitie a unui cub perfect 
si ultima aparitie a unui element cub perfect
ex: n = 8; a = (13, 26, 27, 54, 112, 8, 2197, 600) se va afisa a = (13, 26, 600)
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int perfectCube(int x)
{
    bool ok = 0;
    int i;
    for (i = 1; i < x; i++)
    {
        if (x == pow(i, 3))
        {
            ok = 1;
        }
    }
    return ok;
}

int main()
{
    int a[15];
    int n, i, p_min = 0, p_max = 0, j;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%i]: ", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (perfectCube(a[i]))
        {
            p_min = i;
            break;
        }
    }
    for (j = n - 1; j > 0; j--)
    {
        if (perfectCube(a[j]))
        {
            p_max = j;
            break;
        }
    }
    
    for (i = 0; i < p_min; i++)
    {
        printf(" %d ", a[i]);
    }
    for (i = p_max+1; i < n; i++)
    {
        printf(" %d ", a[i]);
    }

    return 0;
}
