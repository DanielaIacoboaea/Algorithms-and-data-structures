//insertion sort

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a[100], i, n, j, aux, ok;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n; i++)
    {
        printf("i: %d\n", i);
        aux = a[i];
        printf("aux %d este a[%d]: %d\n", aux, i, a[i]);
        j = i - 1;
        printf("j: %d\n", j);
        ok = 0;
        printf("ok: %d\n", ok);
        while (j >= 0 && !ok)
        {
            if (aux < a[j])
            {
                a[j+1] = a[j];
                printf("a[j+1] %d\n", a[j+1]);
                j--;
                printf("j: %d\n", j);
            }else 
            {
                ok = 1;
                printf("ok din else: %d\n", ok);
            }
        }
        a[j+1] = aux;
        printf("a[j+ 1] din for: %d\n", a[j+1]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

