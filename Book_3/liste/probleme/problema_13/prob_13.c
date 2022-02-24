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

void print_in_file(Nod* list, FILE** f2)
{
    Nod* temp;
    temp = list;
    while(temp)
    {
        fprintf(*f2, "%d ", temp->info);
        temp = temp->next;
    }
    fprintf(*f2, "\n");
}

int main()
{
    FILE *f, *f2;
    int x;
    Nod* vf_par = NULL;
    Nod* vf_impar = NULL;

    f = fopen("numere.txt", "r");
    f2 = fopen("liste_out.txt", "w");

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

    print_in_file(vf_par, &f2);
    print_in_file(vf_impar, &f2);

    fclose(f);
    fclose(f2);
    return 0;
}