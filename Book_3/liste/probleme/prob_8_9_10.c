#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elev{
    char nume[256];
    int note[4];

} elev;

typedef struct Nod{
    elev date;
    struct Nod* next;

} Nod;

void read_elev(elev* date_elev)
{
    char nume [256], prenume[256];
    int nota, i;
    printf("enter nume: \n");
    scanf("%s", nume);
    printf("enter prenume: \n");
    scanf("%s", prenume);

    strcpy(date_elev->nume, nume);
    strcat(date_elev->nume, " ");
    strcat(date_elev->nume, prenume);

    for(i = 1; i <= 3; i++)
    {
        printf("nota[%d]: \n", i);
        scanf("%d", &nota);
        date_elev->note[i] = nota;
    }
}

Nod* find_end(Nod* nod_curent) {
    while(nod_curent->next) {
        nod_curent = nod_curent->next;
    }
    return nod_curent;
}

void my_add(Nod** vf, elev date) {
    Nod* end;

    if(*vf == NULL) {
        *vf = (Nod*) malloc(sizeof(Nod));
        end = *vf;
    }
    else {
        end = find_end(*vf);
        end->next = (Nod*) malloc(sizeof(Nod));
        end = end->next;
    }

    end->date = date;
    end->next = NULL;
}

void my_print(Nod* nod_curent, int n) {
    int i, sum;
    float medie = 0;
    while(nod_curent) {
        printf("%s\n", nod_curent->date.nume);
        sum = 0;
        for(i = 1; i<=3; i++)
        {
            printf("%d ", nod_curent->date.note[i]);
            sum = sum + nod_curent->date.note[i];
        }
        printf(" media %s: %.2f\n", nod_curent->date.nume, sum/3.0);
        medie = medie + sum/3.0;
        nod_curent = nod_curent->next;
    }
    printf("\n medie generala: %.2f\n", medie/n);
}

int main()
{
    Nod* vf = NULL;
    elev temp;
    int n, i;
    printf("n:\n");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        read_elev(&temp);
        my_add(&vf, temp);
    }
    my_print(vf, n);
    return 0;
}