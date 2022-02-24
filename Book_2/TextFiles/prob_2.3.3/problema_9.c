/* fisierul text input.txt 
sa se creeze fisierul output.txt care contine liniile numar de ordine impar din input.txt
*/

#include <stdio.h>

int main()
{
    FILE *f1, *f2;
    int count = 1;
    char x;
    f1 = fopen("input.txt", "r");
    f2 = fopen("output.txt", "w");
    while (!feof(f1))
    {
        fscanf(f1, "%c", &x);
        if (count % 2 != 0)
        {
            fprintf(f2, "%c", x);
        }
        if (x == '\n')
        {
            count++;
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
