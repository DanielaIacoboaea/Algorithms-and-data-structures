/* se considera doua fisiere i1.txt si i2.txt.
verificati care dintre ele contine mai multe caractere
afisati numele fisierului.
*/

#include <stdio.h>

int main()
{
    FILE *f1, *f2;
    char x, y;
    int count_i1 = 0, count_i2 = 0;
    f1 = fopen("i1.txt","r");
    f2 = fopen("i2.txt", "r");
    while (!feof(f1))
    {
        fscanf(f1, "%c", &x);
        printf("x: %c\n", x);
        if (x != ' ' && x != '\n')
        {
            printf("count_i1: %d\n", count_i1);
            count_i1++;
        }
    }
    printf("count_i1: %d\n", count_i1);
    while (!feof(f2))
    {
        fscanf(f2, "%c", &y);
        printf("y: %c", y);
        if (y != ' ' && y != '\n')
        {
        count_i2++;
        printf("count_i2: %d\n", count_i2);
        }
    }
    printf("count_i2: %d\n", count_i2);
    if (count_i1 > count_i2)
    {
        printf("Fisierul i1 are mai multe caractere\n");
    }else if (count_i1 < count_i2)
    {
        printf("Fisierul i2 are mai multe caractere\n");
    }else 
    {
        printf("Fisierele au un numar egal de caractere\n");
    }
    
    fclose(f1);
    fclose(f2);
    return 0;
}
