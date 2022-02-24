/* se considera un tablou bidimensional cu n linii si m coloane
realizati un program care identifica linia cu cele mai multe elemente divizibile cu primul element situat pe ea
ex: n = 3; m = 3
2 2 135
3 150 6
7 8 900
se va afisa 2
*/

#include <stdio.h>

int divisors(int x[], int size)
{
    int count = 0, r, i;
    for (i = 1; i < size; i++)
    {
        if (x[i] % x[0] == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int i, j, n, m, k, d_count, max = 0, line;
    int a[15][15];
    int v[15];
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    
    for (i = 0; i < n; i++)
    {
        k = 0;
        d_count = 0;
        for (j = 0; j < m; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
            v[k] = a[i][j];
            k++;
        }
        d_count = divisors(v, m);
        if (d_count > max)
        {
            max = d_count;
            line = i;
        }
    }
    printf("%d - linia cu cei mai multi divisori: %d divizori.\n", line+1, max);
    return 0;
}
