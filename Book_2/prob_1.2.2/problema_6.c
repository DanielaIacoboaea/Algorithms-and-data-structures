/* calcularea notei la purtare 
elev: nume, prenume, total absente, absente motivate 
pt fiecare10 absente nemotivate - se scade un punct
nr absente nemotivate > 50 - media 4
afisati numele si mediile in ordine descrescatoare 
ex: n = 6               se va afisa: 
Ionescu Vlad 17 - 10    Ionescu Ana 10
Popescu Ion 24 - 1      Ionescu Vlad 10
Ionescu Ana 8 - 6       Popescu Dan 10
Alexe Maria 20 - 4      Alexe Maria 9
Mitea Ilie 73 - 6       Popescu Ion 8
Popescu Dan 12 - 12     Mitea Ilie 4
*/

#include <stdio.h>
#include <string.h>

typedef struct elev{
    char nume[256];
    int absente, a_motivate, nota;
} elev;

int grade(int x, int y)
{
    int result = 10;
    int dif = x - y;
    if (y > 50)
    {
        result = 4;
    }else if (dif < 10)
    {
        result = 10;
    }else
    {
        while (dif > 9)
        {
            dif = dif - 10;
            result--;
        }
    }
    return result;
}

void sort_struct(elev lista[256], int n)
{
    int i, j;
    struct elev aux;
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (lista[j].nota > lista[j-1].nota)
            {
                aux = lista[j];
                lista[j] = lista[j-1];
                lista[j-1] = aux;
            }
        }
    }
}

int main()
{
    FILE *f;
    f = fopen("elevi.txt","r");
    int i, count, j;
    char nm[256], pn[256], nume_complet[256];
    elev student[256];
    count = 0;
    while (!feof(f))
    {
        fscanf(f, "%s %s %d - %d", nm, pn, &student[count].absente, &student[count].a_motivate);
        strcpy(nume_complet, nm);
        strcat(nume_complet, " ");
        strcat(nume_complet, pn);
        strcpy(student[count].nume, nume_complet);
        student[count].nota = grade(student[count].absente, student[count].a_motivate);
        count++;
    }
    for (i = 0; i < count; i++)
    {
        printf("%s %d\n", student[i].nume, student[i].nota);
    }
    printf("lista sortata\n");
    sort_struct(student, count);
    for (i = 0; i < count; i++)
    {
        printf("%s %d\n", student[i].nume, student[i].nota);
    }
    fclose(f);
    return 0;
}
