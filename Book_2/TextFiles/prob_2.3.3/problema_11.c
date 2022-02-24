/* sa se scrie un program care determina caracterul neimprimabil (cod ASCII mai mic decat 32)
cu frecventa de aparitie maxima in fisierul in.txt
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *f1;
    char x;
    int count = 0, count_temp = 0;
    f1 = fopen("in.txt", "r");
    while (!feof(f1))
    {
        fscanf(f1, "%c", &x);
        if ((int)x < 32)
        {
            /*count_temp++;
            if (count_temp > count)
            {
               count = count_temp;
               printf("%d ", count);
            }*/
           printf("Found non-printable character with ASCII code: %d\n", (int)x);
        }
    }
    fclose(f1);
    return 0;
}
