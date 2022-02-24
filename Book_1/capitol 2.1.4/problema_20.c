/* afisati cifrele distincte ale unui numar in ordine crescatoare a numarului lor de aparitii
ex: n = 355222 se va afisa 3 5 2
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a[10], b[10], c[10];
    int i, rem, n, d = 0, p, count = 0, count_max = 0;
    bool ok;
    printf("n: ");
    scanf("%d", &n);
    
    i = 0;
    while (n != 0)
    {
        rem = n % 10;
        a[i] = rem;
        n = n / 10;
        d++;
        i++;
    }
    for (i = 0; i < d; i++)
    {
        b[i] = 0;
    }
    b[0] = a[0];
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }

        }
    }
    return 0;
}
