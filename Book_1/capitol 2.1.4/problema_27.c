/* a (n elemente) si b (m elemente) 
verificati daca exista in b o secventa de n elemente pe pozitii consecutive (nu neaparat in aceeasi ordine)
daca nu exista, afisati 0, altfel afisati primul indice din B de la care se regasesc toate elementele din A.
ex: n = 3, m = 7, a=(2, 4, 1) si b = (3, 4, 8, 4, 2, 1, 9) se va afisa: 4
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a[50], b[50];
    int i, j, n, m, p, count = 0;
    bool ok;
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (j = 0; j < m; j++)
    {
        printf("b[%d]: ", j);
        scanf("%d", &b[j]);
    }
    for (j = 0; j < m; j++)
    {
        ok = 0;
        for (i = 0; i < n; i++)
        {
            if (b[j] == a[i])
            {
                ok = 1;
                count++;
            }
        }
        if (ok == 1 && count == 1)
        {
            p = j;
        }else if (ok == 0)
        {
            count = 0;
        }
        if (count == n)
        {
            break;
        }
    }
    if (count == 0)
    {
        printf("nu exista\n");
    }else 
    {

        printf("pozitia: %d\n", p);
    }
    return 0;
}
