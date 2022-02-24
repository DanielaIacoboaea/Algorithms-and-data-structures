/* se considera fisierul in.txt ce contine pe prima linie un nr natural n, iar pe a doua linie n numere intregi
afisati pe ecran primul si ultimul numar de pe linia a doua
*/

#include <stdio.h>

int main()
{
    FILE *f;
    int n, i, x;
    f = fopen("in.txt", "r");
    fscanf(f, "%d", &n);
   
    for (i = 0; i < n; i++)
    {
        if (feof(f))
        {
            break;
        }
        fscanf(f, "%d", &x);
        if (i == 0)
        {
            printf("%d ", x);
        }
        if (i == n-1)
        {
            printf("%d ", x);
            break;
        }
    }
    fclose(f);
    return 0;
}
