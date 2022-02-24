/* bubble sort 
*/

#include <stdio.h>

int main()
{
    int a[100], i, n, j, aux;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j] < a[j-1])
            {
                aux = a[j];
                a[j] = a[j-1];
                a[j-1] = aux;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
