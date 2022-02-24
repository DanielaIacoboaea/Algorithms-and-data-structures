#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod *next;
} Nod;

void print_list(Nod *el_curent)
{
    while(el_curent)
    {
        printf("%d ", el_curent->info);
        el_curent = el_curent->next;
    }
    printf("\n");
}

void double_list(Nod *el_curent)
{
    while(el_curent)
    {
        el_curent->info = 2 * el_curent->info;
        el_curent = el_curent->next;
    }
}

Nod *lista_corigenti(Nod *lista_note)
{
    Nod *vf_corigenti, *sf_corigenti;
    vf_corigenti = (Nod*)malloc(sizeof(Nod));
    sf_corigenti = vf_corigenti;

    while(lista_note)
    {
        sf_corigenti->info = lista_note->info >= 5;
        if(lista_note->next == NULL)
        {
            sf_corigenti->next = NULL;
        }else
        {
            sf_corigenti->next = (Nod*)malloc(sizeof(Nod));
             sf_corigenti = sf_corigenti->next;
        }

        lista_note = lista_note->next;
    }

    return vf_corigenti;
}

int main()
{
    Nod *vf, *tmp, *vf_corigenti;

    vf = (Nod*)malloc(sizeof(Nod));
    vf->info = 3;
    vf->next = NULL;

    tmp = (Nod*)malloc(sizeof(Nod));
    tmp->info = 8;
    tmp->next = NULL;

    vf->next = tmp;

    print_list(vf);

    vf_corigenti = lista_corigenti(vf);
    print_list(vf_corigenti);

    double_list(vf);
    print_list(vf);

    add_node()

    return 0;
}