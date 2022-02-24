/* afisati pentru un sir de n elemente care este numarul de aparitii al fiecarei valori
ex n = 6 si vectorul (3, 13, 3, 13, 8, 13) se va afisa
13 3
3 2 
8 1
*/

#include <stdio.h> 
#include <stdbool.h>

int main()
{
    int a[15], b[15];
    int i, n, m, j, nr;
    bool ok;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    m = 0;
    b[0] = a[0];
    for (i = 1; i < n; i++)
    {
        ok = 0;
        for (j = 0; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                ok = 1;
            }
        }
            if (ok == 0)
            {
                m = m+1;
                b[m] = a[i];
            }
    }
    
    for (i = 0; i <= m; i++)
    {
        nr = 0;
        for (j = 0; j < n; j++)
        {
            if (b[i] == a[j])
            {
                nr++;
            }
        }
        printf("%d, %d\n", b[i], nr);
    }
    return 0;
}
