/* for recursiv (array, sa se printeze descrescator an, an-1, an-2 etc)
contor for decrementeaza valoarea la fiecare iteratie
*/

#include <stdio.h>

int a[15];

void afisare(int i)
{
    if (i >= 0)
    {
        printf("%d ", a[i]);
        afisare(i - 1);
    }
}

int main()
{
    int size, i;
    printf("n: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    afisare(size - 1);
    return 0;
}
