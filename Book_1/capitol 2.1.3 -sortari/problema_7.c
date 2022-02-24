/* se considera un tablou unidimensional ce contine n caractere distincte
sa se afiseze permutarea circulara a lui care incepe cu cel mai mic caracter lexicografic
*/

#include <stdio.h>

int main()
{
    char a[100], min;
    int i, j, n, p;
    printf("n: ");
    scanf("%d", &n);
    printf("a[0]:");
    scanf(" %c", &a[0]);
    getchar();
    p = 0;
    min = a[0];
    for (i = 1; i < n; i++)
    {
        printf("a[%d]:", i);
        scanf(" %c", &a[i]);
        if (a[i] < min)
        {
            min = a[i];
            p = i;
        }
    }
    for (i = 0; i < p; i++)
    {
        a[n+i] = a[i];
    }
    for (i = p; i< n+p; i++)
    {
        a[i-p] = a[i];
    }
    for (i = 0; i < n; i++)
    {
        printf("%c ", a[i]);
    }
    return 0;
}
