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

void delete_list(Nod** vf)
{
    Nod* temp;
    while(*vf)
    {
        temp = *vf;
        *vf = (*vf)->next;
        free(temp);
        temp = NULL;
    }
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

    int x, enter = 1;
    
    do
    {
        printf("enter value: \n");
        scanf("%d", &x);
        add_node(&vf, x);
        printf("enter another value? yes: 1, no: 0\n");
        scanf("%d", &enter);

    } while (enter);

    delete_list(&vf);
    if(vf == NULL)
    {
        printf("delete succesful\n");
    }else{
        printf("delete not succesful\n");
    }
    return 0;
}
