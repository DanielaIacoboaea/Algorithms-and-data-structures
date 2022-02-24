/* foloseste proprietatea recrusivitatii de revenire in subprograme pt executarea instructiunilor 
abandonate in ordinea inversa a autoapelurilor (mecanismul stivei Last in - First out)
*/

#include <stdio.h>

int a[50], size;

void afisare(int i)
{
    if (i < size)
    {
        afisare(i+1);
        printf("%d ", a[i]);
    }
}

int main()
{
    int i;
    printf("n: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    afisare(0);
    return 0;
}
