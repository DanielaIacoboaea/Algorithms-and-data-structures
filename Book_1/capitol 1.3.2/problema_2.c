/* n = 35;
nr de elevi premiati: 10
elevii nepremiati: 
25 24 23 22 21
20 19 18 17 16
15 14 13 12 11
10 9   8  7  6
5  4   3  2  1
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int n, k, p, i, j, e_prem, putere, count = 0;
    printf("n: ");
    scanf("%d", &n);

    for (i = 2; i < n; i++) 
    {
        k = pow(i, 2);
        if (k < n)
        {
            e_prem = n - k;
            putere = k;
        }
    }
    printf("numarul de elevi premiati: %d\n", e_prem);

    for (j = putere; j >= 1; j--)
    {
        printf("%d ", j);
        count++;
        if (pow(count, 2) == putere)
        {
            printf("\n");
            count = 0;
        }
    }
    return 0;
}
