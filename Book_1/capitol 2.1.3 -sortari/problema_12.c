/* sa se afiseze cea mai lunga secventa de elemente consecutive de paritati diferite 
ex: n = 8 si sirul 2 4 3 3 4 7 8 2 seva afisa 3 4 7 8 
*/

#include <stdio.h>

int main()
{
    int a[15];
    int i, n, lmax = 0, lc = 1, pc = 1, pmax;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
 
    }
    for (i = 2; i <= n; i++)
    {
        if ((a[i] % 2) != (a[i-1] % 2))
        {
            lc++;
        }else
        {
            lc = 1;
            pc = i;
        }
        if (lmax < lc)
        {
            lmax = lc;
            pmax = pc;
        }
    }
    for (i = pmax; i <= lmax + pmax -1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
