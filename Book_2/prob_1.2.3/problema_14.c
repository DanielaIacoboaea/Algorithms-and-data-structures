#include <stdio.h>
#include <string.h>

typedef struct elev
{
    char nume[256];
    int nota_1, nota_2;
    float medie;
} elev;

int main()
{
    FILE *f1, *f2, *f3;
    f1 = fopen("note.txt","r");
    f2 = fopen("nume.txt","r");
    f3 = fopen("final.txt","w");
    char nume[256], prenume[256], nume_final[256];
    int i, count = 0, j;
    elev e[256], aux;
    while (!feof(f1) && !feof(f2))
    {
        fscanf(f1, "%d %d", &e[count].nota_1, &e[count].nota_2);
        e[count].medie = (e[count].nota_1 + e[count].nota_2)/2.0;
        fscanf(f2, "%s %s", nume, prenume);
        strcpy(nume_final, nume);
        strcat(nume_final, " ");
        strcat(nume_final, prenume);
        strcpy(e[count].nume, nume_final);
        count++;
    }
    for (i = 0; i < count; i++)
    {
        for (j = count - 1; j > i; j--)
        {
            if (e[j].medie > e[j-1].medie)
            {
                aux = e[j];
                e[j] = e[j-1];
                e[j-1] = aux;
            }
        }
    }
    for (i = 0; i < count-1; i++)
    {
        if (e[i].medie == e[i+1].medie && e[i].nume[0] > e[i+1].nume[0])
        {
            aux = e[i];
            e[i] = e[i+1];
            e[i+1] = aux;
        }
    } 
    for (i = 0; i < count; i++)
    {
        fprintf(f3, "%s %.2f\n", e[i].nume, e[i].medie);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}
