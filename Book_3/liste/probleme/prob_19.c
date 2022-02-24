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
    Nod* end = NULL;
    int temp;

    int x, enter = 1;
    
    do
    {
        printf("enter value: \n");
        scanf("%d", &x);
        add_node(&vf, x);
        printf("enter another value? yes: 1, no: 0\n");
        scanf("%d", &enter);

    } while (enter);

    print_list(vf);

    end = find_end(vf);
    temp = vf->info;
    vf->info = end->info;
    end->info = temp;
    print_list(vf);
    return 0;
}