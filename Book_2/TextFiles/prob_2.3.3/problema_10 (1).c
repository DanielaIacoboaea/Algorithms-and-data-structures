/* sa se scrie un program care creeaza un fisier out,txt ce va contine pe o singura linie 
codurile ASCII ale tuturor caracterelor ce se afla in fisierul in.txt
*/

#include <stdio.h>

int main()
{
    FILE *f1, *f2;
    char x;
    f1 = fopen("in.txt", "r");
    f2 = fopen("out.txt", "w");
    while (!feof(f1))
    {
        fscanf(f1, "%c", &x);
        if (x != ' ' && (x < 48 || x > 57))
        {
            fprintf(f2, "%d", (int)x);
        }else
        {
            fprintf(f2, "%c", x);
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
