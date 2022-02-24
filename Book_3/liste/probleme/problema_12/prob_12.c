#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* next;
} Nod;

Nod* find_end(Nod* curent)
{
    while(curent->next)
    {
        curent = curent->next;
    }
    return curent;
}

void add_node(Nod** vf, int number)
{
    Nod* end;
    if((*vf) == NULL)
    {
        *vf = (Nod*) malloc(sizeof(Nod));
        end = *vf;
    }else
    {
        end = find_end(*vf);
        end->next = (Nod*) malloc(sizeof(Nod));
        end = end->next;
    }
    end->info = number;
    end->next = NULL;
}

void print_list(Nod* list)
{
    Nod* temp;
    temp = list;
    while(temp)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    FILE *f;
    int x;
    Nod* vf_par = NULL;
    Nod* vf_impar = NULL;

    f = fopen("numere.txt", "r");
    while(!feof(f))
    {
        fscanf(f, "%d", &x);
        if (x % 2 == 0)
        {
            add_node(&vf_par, x);
        }else{
            add_node(&vf_impar, x);
        }
    }

    print_list(vf_par);
    print_list(vf_impar);
    return 0;
}