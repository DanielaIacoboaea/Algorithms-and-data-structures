/* se considera doi vectori ale caror elemente sunt ordonate crescator
sa se realizeze un altgoritm prin care se realizeaza operatia de interclasare a elementelor celor2 tablouri.
*/

#include <stdio.h>

int main()
{
    int a[50], b[50], c[50];
    int i, j, k, x, n, m;
    printf("n, m: ");
    scanf("%d,%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < m; i++)
    {
        printf("b[%d]: ", i);
        scanf("%d", &b[i]);
    }
    i = 0;
    j = 0;
    k = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }else
        {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    printf("i after while: %d\n", i);
    printf("j after while: %d\n", j);
    if (i <= n)
    {
        for (int p = i; p < n; p++)
        {
            c[k] = a[p];
            k++;
        }
    }
    if (j <= m)
    {
        for (int p = j; p < m; p++)
        {
            c[k] = b[p];
            k++;
        }
    }
    for (int p = 0; p < k; p++)
    {
        printf("%d ", c[p]);
    }
    
    /*for (i = j; i < m; i++)
    {
        c[++k] = b[i];
        printf("for i c[k++]: %d\n", c[++k]);
    }
    for (j = i; j < n; j++)
    {
        c[++k] = a[j];
        printf("for j c[k++]: %d\n", c[++k]);
    }
    for (i = 0; i < m+n; i++)
    {
        printf("%d ", c[i]);
    }
    */
    return 0;
}
