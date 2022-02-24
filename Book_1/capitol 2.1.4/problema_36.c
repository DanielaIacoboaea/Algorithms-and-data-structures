/* n elemente 
in fata oricarui element precedat (inaintea lui) de un element de semn contrar se introduce in element pozitiv 
a carui valoare este obtinuta prin alipirea cifrelor celor 2 numere de semne contrare, in ordine
ex: n = 6, a = (3, -1, 73, 5, -9, 2) se va afisa 
3 31 -1 173 73 5 59 -9 92 2
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[50], b[50];
    int i, n, j, m, x, y;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    i = 0;
    while (i < n)
    {
        if (a[i] * a[i+1] < 0)
        {
            x = abs(a[i]);
            y = abs(a[i+1]);
            while (y != 0)
            {
                
                x = x*10;
                y = y/10;
            }
            for (j = n; j > i+1; j--)
            {
                a[j+1] = a[j];
            }
                a[i+1] = x + abs(a[i+1]);
                i = i + 2;
                n = n + 1;
            
        }else
        {
            i++;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    /*
    m = 1;
    b[0] = a[0];
    j = 0;
    for (i = 0; i < n; i++)
    {
        x = abs(a[i]);
        y = abs(a[i+1]);
        if (a[i] * a[i+1] < 0)
        {
            j++;
            m++;
            while (y != 0)
            {
                y = y/10;
                x = x * 10 + y;
            }
            b[j] = a[i];
            m++;
            b[j+1] = x;
            m++;
            b[j+2] = a[i+1];
        }else
        {
            j++;
            m++;
            b[j] = a[i];
            m++;
            b[j+1] = a[i+1];
        }
    }
    for (j = 0; j < m; j++)
    {
        printf("%d ", b[j]);
    }
    */
    return 0;
}
