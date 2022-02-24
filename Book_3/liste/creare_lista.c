#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod *adr_urm;
} Nod;

void Adaug(Nod *z, int nr)
{
    Nod *c = (Nod*)malloc(sizeof(Nod));
    c->adr_urm = (Nod*)malloc(sizeof(Nod));
    c->info = nr;
    c->adr_urm = z;
    z = c;
}

void Tip(Nod *x)
{
    Nod *c = x;
    while (c)
    {
        printf("%d" , c->info);
        printf("\n");
        c = c-> adr_urm;
    }
}

int main()
{
    Nod *v;
    int numar;
    printf("numar: ");
    scanf("%d", &numar);
    while (numar)
    {
        Adaug(v, numar);
        printf("%d ", v->info);
        printf("numar: ");
        scanf("%d", &numar);
    }
    Tip(v);
    free(v);
    return 0;
}