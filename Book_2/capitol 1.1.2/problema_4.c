/* citeste de la tastatura un sir de caractere care reprezinta un numar in baza 16
sa se realizeze un program care permite conversia in baza 10 a numarului citit
ex A1B: 2*16^2 + 1 * 16^1 + 11 * 16^0 = 2587;
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char a[256];
    int i, nr = 0, c;
    printf("enter string number:\n");
    fgets(a, sizeof(a), stdin);
    for (i = 0; i <strlen(a); i++)
    {
        nr = nr* 16 + c;
        if (a[i] <= '9')
        {
            c = a[i] - '0';
        }else
        {
            c = a[i] - 55;
        }
        printf("nr: %d\n", nr);
    }
    printf("%d\n", nr);
    return 0;
}
