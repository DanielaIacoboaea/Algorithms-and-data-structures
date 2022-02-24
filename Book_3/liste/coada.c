#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* next;

}Nod;

void add_node(Nod** vf, Nod** end, int value)
{
    Nod* temp;
    if(!(*vf))
    {
        (*vf) = (Nod* ) malloc(sizeof(Nod));
        (*vf)->info = value;
        (*vf)->next = NULL;
        (*end) = (*vf);
    }else
    {
        temp = (Nod* ) malloc(sizeof(Nod));
        (*end)->next = temp;
        temp->info = value;
        temp->next = NULL;
        (*end) = temp;
    }
}

void delete_node(Nod** vf)
{
    Nod* temp;

    if(!(*vf))
    {
        printf("lista este goala\n");
    }else{
        printf("am eliminat valoarea %d\n", (*vf)->info);
        temp = *vf;
        (*vf) = (*vf)->next;
        free(temp);
        temp = NULL;
    }
}

void my_print(Nod* nod_curent) {
    while(nod_curent) {
        printf("%d\n", nod_curent->info);
        nod_curent = nod_curent->next;
    }
}

int main()
{
    Nod* vf = NULL;
    Nod* end = NULL;

    add_node(&vf, &end, 1);
    add_node(&vf, &end, 2);
    add_node(&vf, &end, 3);
    add_node(&vf, &end, 4);

    my_print(vf);

    delete_node(&vf);
    delete_node(&vf);
    my_print(vf);

    return 0;
}