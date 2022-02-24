#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* next;
} Nod;

Nod* find_end(Nod* nod_curent)
{
    while(nod_curent->next)
    {
        nod_curent = nod_curent->next;
    }
    return nod_curent;
}

void add_node(Nod** vf, int value)
{
    Nod* end;

    if(*vf == NULL)
    {
        *vf = (Nod* ) malloc(sizeof(Nod));
        end = *vf;
    }else
    {
        end = find_end(*vf);
        end->next = (Nod* ) malloc(sizeof(Nod));
        end = end->next;
    }

    end->info = value;
    end->next = NULL;
}

void print_list(Nod* vf)
{
    Nod* temp;
    temp = vf;
    while(temp)
    {
        printf("%d  ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Nod* vf = NULL;
    FILE *f;
    char x;
    int number;
    f = fopen("cifre.txt", "r");
    while(!feof(f))
    {
        fscanf(f, "%c", &x);
        number = x - 48;
        add_node(&vf, number);
    }
    print_list(vf);
    return 0;
}