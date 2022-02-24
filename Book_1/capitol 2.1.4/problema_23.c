/* creati un program care sorteaza elementele situate intre elementul minim si maxim dintr-un vector de nr intregi
daca minimul si maximul se afla pe pozitii consecutive, se va afisa mesajul "nu se efectueaza sortarea"
ex: n = 7 si elementele 14, -13, 21, 1, 120, 1000, 21 se va afisa:
14 -13 1 21 120 1000 21
*/

#include <stdio.h>

int main()
{
    int a[15];
    int i, j, aux, p_min, p_max, min, max, n;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    min = a[0];
    max = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            p_min = i;
        }
        if (a[i] > max)
        {
            max = a[i];
            p_max = i;
        }
    }
    printf("min:%d se afla pe pozitia min %d\n", min, p_min);
    printf("max:%d se afla pe pozitia max %d\n", max, p_max);
    if (p_max == p_min + 1)
    {
        printf("nu se efectueaza sortarea\n");
    }else 
    {
        for (i = p_min; i < p_max; i++)
        {
            for (j = i + 1; j < p_max; j++)
            {
                if (a[i] > a[j])
                {
                    aux = a[i];
                    a[i] = a[j];
                    a[j] = aux;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
