/* se considera fisierul real.txt
sa se creeze un alt fisier intreg.txt in care sa se regaseasca valorile din primul fisier rotunjite 
fiecare dintre ele la cel mai apropiat intreg si dispuse in aceaasi ordine
ex: real.txt
2.3 4.05
1.0 12.8 3.45
1.93
intreg.txt:
2 4 
1 13 3 
2
*/

#include <stdio.h>

int main()
{
    FILE *f1, *f2;
    float x;
    int y;
    char space;
    f1 = fopen("real.txt", "r");
    f2 = fopen("intreg.txt", "w");
    while (!feof(f1))
    {
        fscanf(f1, "%f%c", &x, &space);
        if (x - (int)x >= 0.5)
        {
            y = (int)x + 1;
        }else
        {
            y = (int)x;
        }
        fprintf(f2,"%d ", y);
        if (space == '\n')
        {
            fprintf(f2,"\n");
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
