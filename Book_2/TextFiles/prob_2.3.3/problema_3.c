/* se considera fisierul in.txt care contine 10 numere intregi scrise fiecare pe cate 1 linie 
afisati prima si ultima cifra a fiecarui numar fara a prelua valorile intr-un vector.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    FILE *f1;
    f1 = fopen("in.txt", "r");
    int x, r, p, u, count, x_temp;
    char t;
    while (!feof(f1))
    {
        fscanf(f1, "%d", &x);
        x_temp = x;
        count = 0;
        while (x_temp != 0)
        {
            r = x_temp % 10;
            if (count == 0)
            {
                u = r;
            }
            count++;
            x_temp = x_temp/10;
        }
        p = x/(pow(10, count-1));
        printf("%d %d\n", p, u);
    }
    fclose(f1);
    return 0;
}
