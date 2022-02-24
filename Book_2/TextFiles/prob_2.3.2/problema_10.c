/* se considera fisierul text in.txt ce contine numere intregi dispuse pe mai multe linii
numerele sunt separate in cadrul liniilor prin caracterul","
scrieti un program ce creeaza un fisier out.txt ce contine pe fiecare linie suma numerelor situate pe aceeasi linie in fisierul
in.txt 
*/

#include <stdio.h>

int main()
{
    FILE *f1, *f2;
    int x, sum = 0;
    char y;
    f1 = fopen("in.txt", "r");
    f2 = fopen("out.txt", "w");
    while (!feof(f1))
    {
        fscanf(f1, "%d%c", &x, &y);
        printf("x: %d, y: %c\n", x, y);
        sum = sum + x;
        printf("sum: %d\n", sum);
        if (y == '\n')
        {
            fprintf(f2, "%d\n", sum);
            sum = 0;
        }
    }
    fclose(f1);
    fclose(f2);

    return 0;
}
