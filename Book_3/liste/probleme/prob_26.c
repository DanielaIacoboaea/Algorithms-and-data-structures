#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* next;

} Nod;

typedef struct Nod_doubly{
    int data;
    struct Nod_doubly* next;
    struct Nod_doubly* prev;

} Nod_doubly;

Nod* find_end(Nod* curent)
{
    while(curent->next)
    {
        curent = curent->next;
    }
    return curent;

}

void add_node(Nod** vf, int data)
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
    end->info = data;
    end->next = NULL;
}

void print_list(Nod* vf)
{
    Nod* temp = vf;
    while(temp)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

Nod_doubly* find_end_doubly(Nod_doubly* curent)
{
    while(curent->next)
    {
        curent = curent->next;
    }
    return curent;
}

void add_doubly_node(Nod_doubly** start, int to_add)
{
    Nod_doubly* newNode, *end;

    if(*start == NULL)
    {
        newNode = (Nod_doubly* ) malloc(sizeof(Nod_doubly));

        newNode->prev = NULL;
        newNode->data = to_add;
        newNode->next = NULL;
        *start = newNode;

    }else{

        end = find_end_doubly(*start);
        newNode = (Nod_doubly* ) malloc(sizeof(Nod_doubly));
        end->next = newNode;
        newNode->prev = end;
        newNode->data = to_add;
        newNode->next = NULL;
    }
}

void create_doubly_list(Nod* vf, Nod_doubly** start)
{
    Nod* temp = vf;
    int value;

    while(temp)
    {
        value = temp->info;
        add_doubly_node(&(*start), value);
        temp = temp->next;
    }
}

void print_doubly_list(Nod_doubly* vf_doubly)
{
    Nod_doubly* temp = vf_doubly;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Nod* vf = NULL;
    Nod_doubly* vf_doubly = NULL;

     add_node(&vf, 1);
     add_node(&vf, 9);
     add_node(&vf, 2);
     add_node(&vf, 4);
     add_node(&vf, 11);

    print_list(vf);

    create_doubly_list(vf, &vf_doubly);
    print_doubly_list(vf_doubly);

    return 0;
}