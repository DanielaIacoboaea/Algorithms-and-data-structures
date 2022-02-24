/* fie fisierul in.txt ce contine doar caractere alfanumerice 
realizati un program care creeaza fisierul out.txt in care se regasesc caracterele situate pe 
pozitii pare (al doilea, al patrulea, s.a.m.d) din cadrul liniilor cu numar de ordine impar
ex: in.txt      out.txt
ADFABET         DAE
M23CRI          2468
123456789
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, count_l = 1, p = 0;
    char x;
    FILE *f1;
    FILE *f2;
    f1 = fopen("in.txt", "r");
    f2 = fopen("out.txt", "w");
    while (!feof(f1))
    {
        fscanf(f1, "%c", &x);
        printf("%u\n", x);
        //printf("x: %c\n", x);
        p++;
        // printf("p: %d\n", p);
        // printf("count_l inainte while: %d\n", count_l);
        if (x != '\n')
        {
            if ((count_l % 2 != 0) && (p % 2 == 0)) 
            {
                fprintf(f2, "%c", x);
                // printf("x din if: %c\n", x);
            }
        }else
        {
            fprintf(f2, "\n");
            count_l++;
            // printf("count_l din if %d\n", count_l);
            p = 0;
            // printf("p din if: %d\n", p);
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
