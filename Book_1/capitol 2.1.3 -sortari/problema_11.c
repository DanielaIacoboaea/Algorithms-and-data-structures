/* afisati cifrele distincte ale unui numar in ordine crescatoare a nr lor de aparitii
ex: n = 21223 se va afisa 1 3 2
*/

#include <stdio.h>

int main()
{
    int a[10];
    int i, n, r, count = 1;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < 10; i++)
    {
        a[i] = 0;
    }
    while (n != 0)
    {
        r = n % 10;
        a[r]++;
        n = n/10;
    }
    while (count <= 9)
    {
        for (i = 0; i < 10; i++)
        {
            if (a[i] == count)
            {
                printf("%d ", i);
            }
        }
        count++;
    }
    printf("\n");

    return 0;
}
