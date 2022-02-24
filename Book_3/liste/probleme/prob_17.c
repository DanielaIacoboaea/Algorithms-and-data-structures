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

Nod* concatenate_lists(Nod* vf1, Nod* vf2)
{
    Nod* end;
    end = find_end(vf1);
    end->next = vf2;

    return vf1;
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
    Nod* vf1 = NULL;
    Nod* vf2 = NULL;
    Nod* vf3 = NULL;
    int x, enter = 1, number;
    
    do
    {
        printf("enter value: \n");
        scanf("%d", &x);
        add_node(&vf1, x);
        printf("enter another value? yes: 1, no: 0\n");
        scanf("%d", &enter);

    } while (enter);

    enter = 1;
    do
    {
        printf("enter value: \n");
        scanf("%d", &x);
        add_node(&vf2, x);
        printf("enter another value? yes: 1, no: 0\n");
        scanf("%d", &enter);

    } while (enter);

    print_list(vf1);
    print_list(vf2);
    vf3 = concatenate_lists(vf1, vf2);
    print_list(vf3);

    return 0;
}