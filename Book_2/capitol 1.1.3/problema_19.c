/* text de max 255 caractere litere mici sau spatii
realizati un program care rescrie textul a.i cuvintele sa apara ordonate alfabetic
ex: pt sirul de caractere 'ieri am venit devreme se va afisa
am devreme ieri venit.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *sort_chr(char x[256])
{
    char aux;
    for (int i = 0; i < strlen(x); i++)
    {
        for (int j = strlen(x) - 1; j > i; j--)
        {
            if (x[j] < x[j-1])
            {
                aux = x[j];
                x[j] = x[j-1];
                x[j-1] = aux;
            }
        }
    }
    return x;
}

int main()
{
    char a[256], c[256];
    int i, j, k;
    printf("enter string: \n");
    fgets(a, sizeof(a), stdin);
    
    j = 1;
    c[0] = a[0];
    for (i = 1; i < strlen(a); i++)
    {
        if (a[i-1] == ' ' && isalpha(a[i]))
        {
            c[j] = a[i];
            j++;
        }
    }
    printf("%s\n", c);
    sort_chr(c);
    printf("%s", c);

    for (i = 0; i < strlen(c); i++)
    {
        for (j = 0; j < strlen(a); j++)
        {
            if (c[i] == a[j] && j == 0)
            {
                k = j;
                while (a[k] != ' ')
                {
                    printf("%c", a[k]);
                    k++;
                }
                printf(" ");
            }
            if (c[i] == a[j] && (j != 0 && a[j-1] == ' '))
            {
                k = j;
                while (a[k] != ' ')
                {
                    printf("%c", a[k]);
                    k++;
                }
                printf(" ");
            }
        }
    }
    return 0;
}

