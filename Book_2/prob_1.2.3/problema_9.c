#include <stdio.h>
#include <string.h>

typedef struct date_elev{
    char nume[256];
    int varsta;
    float inaltime;
} date_elev;

void sort_name(date_elev arr[256], int n)
{
    struct date_elev aux;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = n-1; j > i; j--)
        {
            if(arr[j].nume[0] < arr[j-1].nume[0])
            {
                aux = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = aux;
            }
        }
    }
}

int main()
{
    date_elev elev[256];
    date_elev aux;
    int n, i, j;
    char nume_temp[256], prenume_temp[256], nume_final[256];
    float h1, h2;
    printf("n: ");
    scanf("%d", &n);
    printf("h1, h2:\n");
    scanf("%f,%f", &h1, &h2);
    for (i = 0; i < n; i++)
    {
        printf("Nume, prenume:\n");
        scanf("%s%s", nume_temp, prenume_temp);
        strcpy(nume_final, nume_temp);
        strcat(nume_final, " ");
        strcat(nume_final, prenume_temp);
        strcpy(elev[i].nume, nume_final);
        printf("varsta,inaltime:\n");
        scanf("%d,%f", &elev[i].varsta, &elev[i].inaltime);
    }
    sort_name(elev, n);
    for (i = 0; i < n; i++)
    {
        if(elev[i].varsta >= 14 && (elev[i].inaltime >=h1 && elev[i].inaltime <=h2))
        {
            printf("%s\n", elev[i].nume);
            printf("%.2f\n", elev[i].inaltime);
        }
    }

    return 0;
}
