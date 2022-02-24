/* sa se inlocuiasca toate caracterele neimprimabile din fisierul text A.in 
prin codul ASCII al lor, precedat de caracterul "#"
*/

#include <stdio.h>
#include <string.h>

int main()
{
    //char x;
    char x[256];
    FILE *f1;
    FILE *f2;
    f1 = fopen("a.in.txt", "r");
    f2 = fopen("b.in.txt", "w");
    while (fgets(x, sizeof(x), f1) != NULL)
    {
        if (strlen(x) < 1)
        {
            fprintf(f2, "%s ", x);
        }else
        {
            fprintf(f2, "#%d ", (int)x);
        }
    }
    /*while (!feof(f1))
    {
        fscanf(f1, "%c", &x);
        if (x <= 32)
        {
            fprintf(f2, "#%d ", (int)x);
        }else
        {
            fprintf(f2, "%c ", x);
        }
    }
        //fscanf(f1,"\n");
        //fprintf(f2,"\n");
    */
    fclose(f1);
    fclose(f2);

    return 0;
}
