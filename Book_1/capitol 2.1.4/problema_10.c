/* ordonati descrescator elementele nenule pentru un vector cu n elemente intregi
ex n = 6; si vectorul (3, 0, 7, 0, 4, 5) se va afisa (7 0 5 0 4 3)
*/

#include <stdio.h>

int main()
{
    int arr[50], sort[50], c[50];
    int i, j, n, aux;
    printf("n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n -1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((arr[i] < arr[j]) && arr[i] != 0 && arr[j] != 0)
            {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    /*
    for (i = 0; i < n; i++)
    {
        sort[i] = 0;
        c[i] = arr[i];
    }
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (c[j] > c[i])
            {
                sort[i]++;
            }else 
            {
                sort[j]++;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("i: %d, sort[i]: %d \n", i, sort[i]);
    }
    for (i = 0; i < n; i++)
    {
        arr[sort[i]] = c[i];
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    */
    return 0;
}
