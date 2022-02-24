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

int insert_after(Nod** vf, int after, int value)
{
    int index = 0;
    Nod* temp = *vf;
    Nod* new_node;

    while(temp->next != *vf)
    {
        index++;
        if(temp->info == after)
        {
            new_node = (Nod* ) malloc(sizeof(Nod));
            new_node->info = value;
            new_node->next = temp->next;
            temp->next = new_node;
            return index;
        }
        temp = temp->next;
    }
    if(temp->next == *vf)
    {
        if(temp->info == after)
        {
                new_node = (Nod* ) malloc(sizeof(Nod));
                temp->next = new_node;
                new_node->info = value;
                new_node->next = *vf;
                return index;
        }
    }
    return -1;
}

int delete_by_value(Nod** vf, int x)
{
    int index = 0;
    Nod* cursor = *vf;
    Nod* end;

    if((*vf)->info == x)
    {
        end = find_end(*vf);
        *vf = (*vf)->next;
        end->next = *vf;
        return index;
    }

    while(cursor && cursor->next->next != *vf)
    {
        index++;

        if(cursor->next->info == x)
        {
            cursor->next = cursor->next->next;
            return index;
        }
        cursor = cursor->next;
    }

    if(cursor->next->next == *vf && cursor->next->info == x)
    {
        cursor->next = *vf;
        return index;
    }
    return -1;
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

int main()
{
     Nod* vf = NULL;

     int i;

     add_node(&vf, 1);
     add_node(&vf, 2);
     add_node(&vf, 3);
     add_node(&vf, 4);

     print_list(vf);

     /*i = insert_after(&vf, 3, 11);

     if(i != -1)
     {
         print_list(vf);
     }else{
         printf("valoarea nu a fost gasita\n");
     } */

     i = delete_by_value(&vf, 4);
     if(i != -1)
     {
         print_list(vf);
     }else{
         printf("valoarea nu a fost gasita\n");
     }

     return 0;
}




