/* un fisier text in.txt in care se afla numere separate de caractere (orice caracter care nu este numar - separator)
out.txt - media aritmetica pe fiecare linie pt numerele de pe linia respectiva
ex: 
2..3a 403bx       136.00
2..2 A,..5        3.00
1.92              46.50
*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f1, *f2;
    char temp[50];
    int i, n;
    float s, c;
    f1 = fopen("in.txt", "r");
    f2 = fopen("out.txt", "w");
    while (!feof(f1))
    {
        s = 0;
        n = 0; 
        c = 0;
        if (!fgets(temp, 256, f1))
        {
            break;
        }
        //strcat(temp, '.');
        for (i = 0; i < strlen(temp); i++)
        {
            if (temp[i] >= '0' && temp[i] <= '9')
            {
                c = c* 10 + temp[i] - '0';
                printf("c: %.2f\n", c);
            }else if (c)
            {
                s = s+c;
                n++;
                c = 0;
            }
        }
        fprintf(f2, "%.2f\n", s/n);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
