/* fisierul IN.txt sufera urmatoarea prelucrare: de pe fiecare linie sunt sterse toate caracterele cu exceptia 
primului si ultimului caracter 
realizati un program care efectueaza aceasta operatie asupra fisierului IN.txt.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char s[256];
    //char *ps = &s[0];
    FILE *f1 = fopen("In.txt", "r");
    FILE *f2 = fopen("O.txt", "w");
    while (fgets(s, sizeof(s), f1) != NULL)
    {
        //printf("%s ", s);
        printf("%c%c\n", s[0], s[strlen(s)-2]);
        
    }
    /*while (!feof(f1))
    {
        printf("feof: %d\n", feof(f1));
        fscanf(f1, "%s", s);
        printf("%s\n", s);
        printf("%lu \n", strlen(s));
        printf("s[0]: %c\n", s[0]);

        if (strlen(s) == 1)
        {
            fprintf(f2, "%c\n", s[0]);
        }else
        {
            fprintf(f2, "%c", s[0]);
            fprintf(f2, "%c", s[strlen(s) - 1]);
            fprintf(f2, "\n");
        }
    }*/
        fclose(f1);
        fclose(f2);
        //unlink("In.txt");
        //rename("O.txt", "In.txt");
    return 0;
}
