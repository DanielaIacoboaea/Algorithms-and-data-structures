/* se considera un sir de n caractere citite de la tastatura.
care este caracterul care apare de cel mai multe ori si care este numarul de aparitii?
*/

#include <stdio.h>

int main()
{
    char a[15];
    char v;
    int i, n, nr, x;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf(" %c", &a[i]);
    }
    i = 0;
    nr = 0;
    while (i < n+1)
    {
        x = i;
        while (a[i] == a[x] && (i <= n))
        {
            i++;
        }
        if ((i - x) > nr)
        {
            nr = i - x;
            v = a[x];
        }
    }
    printf("%c, %d\n", v, nr);
    return 0;
}
