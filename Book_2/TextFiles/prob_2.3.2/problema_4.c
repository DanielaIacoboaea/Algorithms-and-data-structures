/* in fisierul in.txt exista pe prima linie un sir crescator de numere naturale
citirea din fisier a unui nou numar este conditionata de obtinerea ca suma formata din termeni distincti din fisier
a unui sir de nr consecutive incepand cu 1
sa se det numarul maxim care se poate obtine respectand regula data

ex:
in.txt
1 2 4 10 11 32 324 3241 54321
se va afisa 7
*/

#include <stdio.h>

int main()
{
    int n, curent, s = 0, i;
    FILE *f = fopen("in.txt", "r"); 
    do
    {
        fscanf(f, "%d", &curent);
        if (curent>s+1)
        {
            printf("nr maxim ");
            printf("%d\n", s);
            break;
        }
        s = s+ curent;
    }while(!feof(f));
    fclose(f);
    return 0;
}
