/* se considera un tablou unidimensional cu n elemente numere intregi
stergeti toate aparitiile primului element si afisati elementele ramase
ex: n = 5 si vectorul (3, 4, 3, 3, 8) se va afisa 4 8
*/

#include <stdio.h>

int main()
{
    int arr[15];
    int i, n, x, j;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    x = arr[0];
    i = 1;
    while (i < n +1)
    {
        if (arr[i] == x)
        {
            for (j = i; j < n - 1; j++)
            {
                arr[j] = arr[j+1];
            }
            n--;
        }else
        {
            i++;
        }
    }
    for (j = 1; j < n; j++)
    {
        printf("%d ", arr[j]);
    }
    /*
    for (i = 1; i < n; i++)
    {
        if (arr[i] != arr[0])
        {
            printf("%d ", arr[i]);
        }
    }
    */ 
    return 0;
}
