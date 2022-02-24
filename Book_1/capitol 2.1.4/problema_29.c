/* numar are forma unui munte daca cifrele formeaza initial un sir crescator, apoi un sir descrescator
ex: 2556431 - munte 
verificati daca n citit de la tastatura verifica regula precizata
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a[15], b[15];
    int n, i, j, rem, count = 0, p, k, x;
    bool ok_asc = 0, ok_desc = 0;
    printf("n: ");
    scanf("%d", &n);
    i = 0;
    while (n != 0)
    {
        rem = n % 10;
        a[i] = rem;
        i++;
        n = n/10;
        count++;
    }
    for (i = 0; i < count; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    j = count - 1;
    for (i = 0; i < count; i++)
    {
        b[j] = a[i];
        j--;
    }
    for (j = 0; j < count; j++)
    {
        printf("%d ", b[j]);
    }
    j = 1;
    x = j;
    while (b[j-1] < b [j] && j <= count)
    {
        j = j + 1;
    }
    if (x == j)
    {
        j = count + 1;
    }
    while (b[j] > b[j+1] && j < count)
    {
        j = j+1;
    }
    if (j == count)
    {
        printf("este munte\n");
    }else
    {
        printf("nu este munte\n");
    }


    /*
    for (j = 0; j < count; j++)
    {
        if (b[j] < b[j+1])
        {
            ok_asc = 1;
        }else 
        {
            p = j;
        }
    }
    for (j = p; j < count; j++)
    {
        if (b[j] > b[j+1])
        {
            ok_desc = 1;
        }else 
        {
           ok_desc = 0;
        }
    }
    for (j = 0; j < p; j++)
    {
        if (b[j] < b[j+1])
        {
            ok_asc = 1;
        }else 
        {
            ok_desc = 0;
        }
    }

    printf("\n");
    if (ok_asc == 1 && ok_desc == 1)
    {
        printf("numarul este munte\n");
    }else
    {
        printf("numarul nu este munte\n");
    }
    */

    return 0;
}
