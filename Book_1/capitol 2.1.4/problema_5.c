/* sa se calculeze suma tuturor elementelor pare situate pe pozitii impare
ex: n = 5 si 3, 4, 6, 7, 8 se va afisa 14;
*/

#include <stdio.h>

int main()
{
    int arr[15];
    int i, sum = 0, n;
    printf("n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
        if ((i % 2 != 0) && (arr[i] % 2 == 0))
        {
            sum = sum + arr[i];
        }
    }
    printf("suma este: %d\n", sum);
    return 0;
}
