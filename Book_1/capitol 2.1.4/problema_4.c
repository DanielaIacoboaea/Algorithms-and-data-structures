/* se considera un sir de n elemente numere reale
sa se inlocuiasca fiecare element cu cel mai apropiat intreg si sa se afiseze in ordine inversa
de la ultimul catre primul
ex: n  = 6 si vectorul: (2.72, 4.35, 9.82, 1.0, 4.05, 2.45) se va afisa:
2 4 1 10 4 3 
*/

#include <stdio.h>

int main()
{
    float arr[15];
    int n, i;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%f", &arr[i]);
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (arr[i] - (int)(arr[i]) < 0.5)
        {
            printf("%d ", (int)(arr[i]));
        }else 
        {
            printf("%d ", (int)(arr[i]) + 1);
        }
    }
    return 0;
}
