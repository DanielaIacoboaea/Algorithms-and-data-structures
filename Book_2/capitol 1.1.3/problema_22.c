/* de la tastatura se citeste un sir maxim de 10 caractere
realizati un proram care verifica daca acet sir poat reprezenta un numar real exprimat in forma zecimala cu zecimale exacte
ex pt sirul "31.0.234" se va afisa mesajul nu
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char a[15];
    int i, count = 0;
    bool ok = 0;
    float num;
    int x, y;
    printf("enter string:\n");
    scanf("%s", a);
    printf("%s\n", a);
   /* for (i = 0; i < strlen(a); i++)
    {
        if (a[i] == '.')
        {
            ok = 1;
            count++;
        }
    }
    if (ok == 0 && count != 1)
    {
        printf("NU\n");
    }else if (strlen(a) >= 5 && count == 1)
    {
        printf("DA\n");
    } */
    if (sscanf(a, "%d.%d", &x, &y) == 2 && (y>=100 && y <=1000))
    {
        printf("DA\n");
    }else
    {
        printf("NU\n");
    }
    return 0;
}
