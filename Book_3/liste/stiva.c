#include <stdio.h>
#include <stdlib.h>

typedef struct Nod
{
    int info;
    struct Nod* next;
} Nod;

void push_nod(Nod** vf, int value)
{
    Nod* temp;
    if(!(*vf))
    {
        *vf = (Nod* ) malloc(sizeof(Nod));
        (*vf)->info = value;
        (*vf)->next = NULL;
    }else
    {
        temp = (Nod* ) malloc(sizeof(Nod));
        temp->info = value;
        temp->next = (*vf);
        (*vf) = temp;
    }
}

void pop_nod(Nod** vf)
{
    Nod* temp;
    if(!(*vf))
    {
        printf("este este goala\n");
    }else{
        temp = (*vf);
        printf("am eliminat %d\n", temp->info);
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
    int data;

    push_nod(&vf, 1);
    push_nod(&vf, 2);
    push_nod(&vf, 3);

    my_print(vf);

    pop_nod(&vf);
    pop_nod(&vf);
    my_print(vf);
    return 0;
}