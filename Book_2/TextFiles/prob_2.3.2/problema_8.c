/* fisierul text in.txt contine pe prima linie un sir de caractere alfanumerice
creati un fisier text out.txt in care sa se regaseasca continutul din in.txt dispus 
pe mai multe linii in felul urmator:
pe prima linie primul carater, pe a doua linie urmatoarele 2 caractere etc, pana cand au fost plasate toate caracterele
ultima linie va avea mai putine caractere decat linie precedenta
ex:
in.txt
MWQDWEFR 
out.txt
M
WQ
DWE
FR
*/

#include <stdio.h>

int main()
{
    FILE *f1;
    FILE *f2;
    int ch_count = 0, count = 1;
    char x;
    f1 = fopen("in.txt", "r");
    f2 = fopen("out.txt", "w");
    while (!feof(f1))
    {
        ch_count = 0;
        for (ch_count = 0; ch_count < count; ch_count++)
        {
            fscanf(f1, "%c", &x);
            fprintf(f2, "%c", x);
        }
        fprintf(f2,"\n");
        count++;
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
