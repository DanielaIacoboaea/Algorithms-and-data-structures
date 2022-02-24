/* sa se rearanjeze elementele unei matrice de dimensiune n*m astfel incat ele sa fie ordonate 
crescator atat pe linii cat si pe coloane
ex: n = 3, m = 4
3 1 8 9
4 6 5 7 
2 0 1 3
se va afisa

0 1 1 2
3 3 4 5 
6 7 8 9 
*/

#include <stdio.h>

int main()
{
    int i, j, n, m, k, size, aux, l, count = 0;
    int a[15][15];
    int v[50];
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    size = n * m;
    k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
            v[k] = a[i][j];
            k++;
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
        count++;
        if (count == m)
        {
            printf("\n");
            count = 0;
        }
    }
    
    return 0;
}
