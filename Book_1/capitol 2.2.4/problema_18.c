/* sa se det multimea formata din elemente distincte de pe marginea unui tablou bidimensional patratic
ex: n = 3;
2 4 3 
3 4 6 
1 4 3
se va afisa
1 2 3 4 6 
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i, j, n, k, l, size, aux;
    int a[15][15];
    int v[15];
    bool ok;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    v[0] = a[0][0];
    size = 1;
    for (j = 1; j < n; j++)
    {
        ok = 1;
        for (k = 0; k < size; k++)
        {
            if (a[0][j] == v[k])
            {
                ok = 0;
            }
        }
        if (ok)
        {
            v[size] = a[0][j];
            size++;
        }
    }
    for (j = 0; j < n; j++)
    {
        ok = 1;
        for (k = 0; k < size; k++)
        {
            if (a[n-1][j] == v[k])
            {
                ok = 0;
            }
        }
        if (ok)
        {
            v[size] = a[n-1][j];
            size++;
        }
    }
    
    for (i = 1; i < n; i++)
    {
        ok = 1;
        for (k = 0; k < size; k++)
        {
            if (a[i][0] == v[k])
            {
                ok = 0;
            }
        }
        if(ok)
        {
            v[size] = a[i][0];
            size++;
        }
    }
    
    for (i = 1; i < n; i++)
    {
        ok = 1;
        for (k = 0; k < size; k++)
        {
            if (a[i][n-1] == v[k])
            {
                ok = 0;
            }
        }
        if(ok)
        {
            v[size] = a[i][n-1];
            size++;
        }
    }
    for (k = 0; k < size; k++)
    {
        for (l = size - 1; l > k; l--)
        {
            if (v[l] < v[l-1])
            {
                aux = v[l];
                v[l] = v[l-1];
                v[l-1] = aux;
            }
        }
    }

    for (k = 0; k < size; k++)
    {
        printf("%d ", v[k]);
    }

    return 0;
}
