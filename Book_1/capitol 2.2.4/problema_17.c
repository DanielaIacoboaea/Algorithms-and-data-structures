/* sa se det elementul cu numarul maxim de aparitii al unui tablou bidimenional cu n linii si m coloane
ex pt n = 3, m = 4

2  4 13 2
3  4 60 4
16 4 30 4 
se va afisa 4 apare de 5 ori 
*/

#include <stdio.h>

int main()
{
    int i, j, n, m, num, max_count = 0, k, l, size;
    int a[10][10];
    int v[100], count[100];
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
        count[k] = 1;
    }
    for (k = 0; k+1 < size; k++)
    {
        for (l = k + 1; l < size; l++)
        {
            if (v[k] == v[l])
            {
                count[k]++;
            }
        }
        if (count[k] > max_count)
        {
            max_count = count[k];
            num = v[k];
        }
    }
    printf("numarul %d apare de %d ori.\n", num, max_count);
    return 0;
}
