/* fisierul in.txt contine caractere alfanumerice 
sa se creeze un fisier out.txt in care se afla doar numerele preluate in ordine de pe liniile fisierului 
ex: A23sc345ss5e
se va afisa 
23 345 5
*/

#include <stdio.h>

int main()
{
    FILE *f1, *f2;
    char x, space_count; 
    f1 = fopen("in.txt", "r");
    f2 = fopen("out.txt", "w");
    while (!feof(f1))
    {
        fscanf(f1, "%c", &x);
        if (((int)x > 64 && (int)x < 91) || ((int)x > 96 && (int)x < 123))
        {
            space = ' ';
            fprintf(f2, "%c", space);
        }else
        {
            fprintf(f2, "%c", x);
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
