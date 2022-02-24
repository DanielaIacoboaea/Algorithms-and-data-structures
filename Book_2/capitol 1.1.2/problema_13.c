/* fisierul text p.txt contine pe mai multe linii un altgoritm in pseudocod
singurele cuvinte cheie ce se regasesc in fisier sunt: intreg, daca, atunci, altfel, citeste, scrie, stop
sa se det numarul de variabile folosite in algoritm si identificarii acestora 
toate caracterele au coduri ASCII asociate 
liniile din fisier se termina cu caracterul ;
ex pt seventa "daca a>b atunci cc=c altfel d =a+b stop;" se va afisa:
5
a b xx c d
*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f;
    int i, j, m, ok;
    char a[8][11] = {"intreg","citeste","scrie","daca","atunci","altfel","stop"};
    char s[256], x[256], v[51][11];
    f = fopen("P.txt", "r");

    for (m = 0; !feof(f);)
    {
        fgets(x, 256, f);
        strcat(x, " ");
        for (i = 0; i <strlen(x); i++)
        {
            if (x[i] >= 'a' && x[i] <= 'z')
            {
                strncat(s, x+i, 1);
            }else if (strlen(s))
            {
                ok = 1;
                for (j = 0; j < 7; j++)
                {
                    if(!strcmp(a[j], s))
                    {
                        ok = 0;
                    }
                }
                for (j = 0; j < m; j++)
                {
                    if(!strcmp(v[j],s))
                    {
                        ok = 0;
                    }
                }
                if (ok)
                {
                    strcpy(v[m++], s);
                }
                memset(s, 0, sizeof(s));
            }
        }
    }
    printf("%d\n", m);
    for (i = 0; i < m; i++)
    {
        printf("%s ", v[i]);
    }
    fclose(f);
    return 0;
}
