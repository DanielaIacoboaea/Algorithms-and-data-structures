/* fisierul real.txt. sa se afiseze in fisierul frac.txt partea fractionara pe o singura linie
ex:
real.txt
2.3 4.05
1.0 12.8 3.45
1.93
fract.txt:
0.3 0.05 0.0 0.8 0.45 0.93
*/

#include <stdio.h>

int main()
{
    FILE *f1, *f2;
    float x;
    float y;
    f1 = fopen("real.txt", "r");
    f2 = fopen("fract.txt", "w");
    while (!feof(f1))
    {
        fscanf(f1, "%f", &x);
        y = x - (int)x;
        fprintf(f2,"%.2f ", y);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
