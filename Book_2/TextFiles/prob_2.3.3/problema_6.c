/* se considera 2 fisiere i1.txt si i2.txt
unul contine numere reprezentand varsta unor elevi, iar liniile corespunzatoare din celalalt fisier, numele acestora (majuscule)
sa se afiseze pe ecran codificarile numelor celor mai tineri elevi
ex:
i1.txt:
13
15
16
13
i2.txt:
I D
*/

#include <stdio.h>

typedef struct names
{
    int x; 
    char y;
} names;
int main()
{
    FILE *f1, *f2;
    int min = 100, age, i = 0, count = 1;
    char name;
    names print[15];

    f1 = fopen("i1.txt", "r");
    f2 = fopen("i2.txt", "r");
    
    while (!feof(f1) && !feof(f2))
    {
        fscanf(f1, "%d", &age);
        fscanf(f2, "%c", &name);
        
        if (name == '\n')
        {
            fscanf(f2, "%c", &name);
        }
        if (age <= min)
        {
            min = age;
            print[i].x = age;
            print[i].y = name;
            count++;
            i++;
            //printf("%c", name);
        }
    }
    for (i = 0; i < count; i++)
    {
        if (print[i].x == min)
        {
            printf("%c ", print[i].y);
        }
    }
    fclose(f1);
    fclose(f2);

    return 0;
}
