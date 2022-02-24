/* creati un program care transforma toate literele mici din fisierul in.txt in majuscule 
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *f1, *f2;
    char x;
    f1 = fopen("in.txt", "r");
    f2 = fopen("out.txt", "w");
    while (!feof(f1))
    {
        fscanf(f1, "%c", &x);
        if (x != ' ' && x != '\n' && ((int)x > 96 || (int)x < 123))
        {
            fprintf(f2, "%c", toupper(x));
        }else
        {
            fprintf(f2,"%c", x);
        }
    }
    fclose(f1);
    fclose(f2);

    return 0;
}
