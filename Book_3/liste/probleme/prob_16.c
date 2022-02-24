#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void create_number(Nod* vf)
{
    int number = 0;
    int power = 0;
    Nod* temp = vf;
    while(temp)
    {
        power++;
        temp = temp->next;
    }
    while (vf->info == 0)
    {
        vf = vf->next;
        power--;
    }
    while(vf)
    {
        number = number + (vf->info * pow(10, power-1));
        power--;
        vf = vf->next;
    }
    printf("numarul este: %d\n", number);

}

int main()
{
    Nod* vf = NULL;
    int x, enter = 1, number;
    
    do
    {
        printf("enter value: \n");
        scanf("%d", &x);
        add_node(&vf, x);
        printf("enter another value? yes: 1, no: 0\n");
        scanf("%d", &enter);

    } while (enter);

    print_list(vf);
    create_number(vf);
    return 0;
}