/* scrieti un program care creaza un fisier i3 prin concatenarea continuturilor a doua fisiere i1 si i2
*/

#include <stdio.h>

int main()
{
    FILE *f1, *f2, *f3;
    char x, y;
    f1 = fopen("i1.txt", "r");
    f2 = fopen("i2.txt", "r");
    f3 = fopen("i3.txt", "w");
    while (!feof(f1))
    {
        fscanf(f1,"%c", &x);
        fprintf(f3, "%c", x);
    }
    while (!feof(f2))
    {
        fscanf(f2,"%c", &y);
        fprintf(f3, "%c", y);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}
