/* scrieti un program care verifica daca doua fisiere text i1.txt si i2.txt au continut identic 
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool ok = 0;
    char x;
    char y;
    FILE *f1;
    FILE *f2;
    f1 = fopen("i1.txt", "r");
    f2 = fopen("i2.txt", "r");
    while (!feof(f1) && !feof(f2))
    {
        fscanf(f1, "%c", &x);
        fscanf(f2, "%c", &y);
        if (x == y)
        {
            ok = 1;
        }else 
        {
            ok = 0; 
            printf("Fisierele sunt diferite!\n");
            break;
        }
    }
    if(ok)
    {
        printf("Fisierele sunt identice!\n");
    }
    fclose(f1);
    fclose(f2);

    return 0;
}

