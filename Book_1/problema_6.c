/* n, m, k; n^m % k == 0;
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, k, i, p, count = 0, x;
    printf("n ,m ,k ");
    scanf("%d,%d,%d", &n, &m, &k);

    for (i = 0; i < n; i++)
    {
        printf("x: ");
        scanf("%d", &x);
        p = pow(x, m);
        if (p % k == 0)
        {
            count++;
            printf("%d ", x);
        }
    }
    printf("%d numere ^ %d se divid cu %d\n", count, m, k);

    return 0 ;
}
