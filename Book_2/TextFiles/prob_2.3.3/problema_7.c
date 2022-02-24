/* in.txt are pe fieare linie caractere alfanumerice
in fisierul out.txt se vor regasi pe fiecare linie corespunzatoare doar literele (au fost eliminate cifrele)
*/

#include <stdio.h>

int main()
{
    FILE *f1, *f2;
    char y;
    int x;
    f1 = fopen("in.txt", "r");
    f2 = fopen("out.txt", "w");
    while (!feof(f1))
    {
        fscanf(f1, "%c", &y);
        if (((int)y > 64 && (int)y < 91) || ((int)y > 96 && (int)y < 123))
        {
            fprintf(f2, "%c", y);
        }
        if (y == '\n')
        {
            fprintf(f2,"\n");
        }
        if (y ==' ')
        {
            fprintf(f2," ");
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}

