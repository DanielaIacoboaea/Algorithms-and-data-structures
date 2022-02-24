/* in.txt contine numere intregi pe mai multe linii 
se doreste inlocuirea in fisier a tuturor aparitiilor unui numar x cu un alt numar y citit de la tastatura
realizati un program care permite efectuarea acestei modificari asupra continutului fisierului in.txt
*/

#include <stdio.h>

int main()
{
    FILE *f1;
    FILE *f2;
    int x, y, num;
    char c;
    f1 = fopen("in.txt", "r");
    f2 = fopen("out.txt", "w");
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);
    while (!feof(f1))
    {
        fscanf(f1, "%d%c", &num, &c);
        if (num != x)
        {
            fprintf(f2, "%d ", num);
        }else
        {
            fprintf(f2, "%d ", y);
        }
        if (c == '\n')
        {
            fprintf(f2,"\n");
        }
    }
    fclose(f1);
    fclose(f2);

    return 0;
}
