/* se considera un tablou unidimensional cu n (< 100) elemente
sa se det numarul minim de subsiruri strict crescatoare de valori consecutive 
in care poate fi partitionat vectorul 
prin subsir se intelege o setiune din vectorul initial care nu se afla neaparat pe pozitii consecutive 
ex: n = 7; a = (3, 10, 4, 4, 5, 11, 6) se va afisa: 3 (3, 4, 5, 6; 10 11; 4)
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a[15], b[15];
    int i, j, aux, count = 0, n, m;
    bool ok;
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
    m = 0;
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i+1] - a[i] == 1)
        {
            printf(" %d, %d ", a[i], a[i+1]);
        }else if (a[i+1] == a[i])
        {
            b[j] = a[i];
            m++;
            j++;
            count++;
        }else if (a[i+1] - a[i] > 1)
        {
            printf("; ");
            count++;
        }
    }
    for (j = 0; j < m; j++)
    {
        printf(" %d ", b[j]);
    }
    printf("\n count: %d\n", count);

    return 0;
}
