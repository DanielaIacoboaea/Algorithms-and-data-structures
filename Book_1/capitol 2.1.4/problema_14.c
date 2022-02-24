/* determinati cea mai lunga secventa de elemente pozitive din cadrul unui vector
ex n = 6 si vectorul (3, -4, 3, 13, 8, -3) se va afisa 3 13 8
*/

#include <stdio.h>

int main()
{
    int a[15];
    int i, l = 0, l_max = 0, n, p_max;
    printf("n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    
    for (i = 0; i < n; i++)
    {
        printf("i: %d\n", i);
        printf("a[i]: %d\n", a[i]);
        if (a[i] > 0)
        {
            l++;
            printf("l din if: %d\n", l);
            if (l > l_max)
            {
                l_max = l;
                printf("l_max din if: %d\n", l_max);
                p_max = i;
                printf("p_max din if: %d\n", p_max);
            }
        }else
        {
            l = 0;
            //p_max = 0;
            printf("l din else: %d\n", l);
        }
    }
    
    for (i = (p_max + 1) - l_max; i <= p_max; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
