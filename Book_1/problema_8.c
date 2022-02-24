/* la alegeri au participat N alegatori < 1.000.000, exprimandu-si votul sub forma unui numar care reprezinta codul candidatului 
sa se determina daca exita un candidat majoritar. nr de aparitii al codului sau este > n/2
ex: n = 7; 1 1 3 1 2 1 1 raspuns: 1;
*/

#include <stdio.h>

int main()
{
    int n, c, max_c = 0, i, count = 0;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("vote: ");
        scanf("%d", &c);
        if (c == max_c)
        {
            count++;
        }else 
        {
            count--;
        }
        if (count <= 0)
        {
            max_c = c;
            count = 1;
        } 
    }
    printf("participatul cu nr max de voturi este: %d", max_c);
    return 0;
}
