#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* next;
} Nod;

Nod* find_end(Nod* nod_curent)
{
    Nod* vf = nod_curent;

    while(nod_curent->next != vf)
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
        Nod* newNod = (Nod* ) malloc(sizeof(Nod));
        end->next = newNod;
        end = newNod;
    }

    end->info = value;
    end->next = *vf;
}

void print_list(Nod* vf)
{
    Nod* temp;
    temp = vf;
    while(temp->next != vf)
    {
        printf("%d  ", temp->info);
        temp = temp->next;
    }
    if(temp->next == vf)
    {
        printf("%d  ", temp->info);
    }
    printf("\n");
}

void move_left(Nod** vf)
{
    Nod* temp = *vf;
    int vf_info = (*vf)->info;
    while(temp->next != *vf)
    {
        temp->info = temp->next->info;
        temp = temp->next;
    }
    if(temp->next == *vf)
    {
        temp->info = vf_info;
    }
}

int main()
{
     Nod* vf = NULL;
     int info_end;
     Nod* end = NULL;

     add_node(&vf, 1);
     add_node(&vf, 2);
     add_node(&vf, 3);
     add_node(&vf, 4);
     add_node(&vf, 5);

     print_list(vf);
    
     end = find_end(vf);
     info_end = end->info; 
    
     while(vf->info != info_end)
     {
        move_left(&vf);
        print_list(vf);
     }
     return 0;
}