#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* prev;
    struct Nod* next;

}Nod;

void create_head(Nod** vf, Nod** end, int data)
{
    Nod* temp = (Nod* ) malloc (sizeof(Nod));
    temp->info = data;
    temp->prev = NULL;
    temp->next = NULL;

    *vf = temp;
    *end = temp;
}

void create_add_right(Nod** vf, Nod** end, int elements)
{
    int i, data;
    Nod* to_add = NULL;
    for(i = 1; i < elements; i++)
    {
        printf("data: \n");
        scanf("%d", &data);
        to_add = (Nod* ) malloc(sizeof(Nod));
        to_add->info = data;
        to_add->next = NULL;
        to_add->prev = *end;
        (*end)->next = to_add;
        *end = to_add;
    }
}

void add_left(Nod** vf, Nod** end, int value)
{
    Nod* to_add = NULL;
    to_add = (Nod* ) malloc(sizeof(Nod));

    to_add->info = value;
    to_add->prev = NULL;
    to_add->next = *vf;
    (*vf)->prev = to_add;

    *vf = to_add;
}

Nod* find_value(Nod* vf, Nod* end, int value)
{
    Nod* temp = vf;
    while(temp)
    {
        if(temp->info == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void add_by_value(Nod** vf, Nod** end, int search, int data)
{
    Nod* temp;
    Nod* to_add = (Nod* ) malloc(sizeof(Nod));
    to_add->info = data;
    to_add->prev = NULL;
    to_add->next = NULL;

    if((*vf)->info == search)
    {
        (*vf)->next->prev = to_add;
        to_add->next = (*vf)->next;
        (*vf)->next = to_add;
        to_add->prev = *vf;
    }else if((*end)->info == search)
    {
        to_add->next = NULL;
        to_add->prev = *end;
        (*end)->next = to_add;
        *end = to_add;
        
    } else{
        temp = find_value(*vf, *end, search);
       
        if(temp != NULL)
        {
            Nod* curent = *vf;
            while(curent->next != temp)
            {
                curent = curent->next;
            }
            curent = curent->next;
           
            to_add->next = curent->next;
            to_add->prev = curent;
            curent->next->prev = to_add;
            curent->next = to_add;
        }
    }
}

void delete_node(Nod** vf, Nod** end, int value)
{
    if((*vf)->info == value)
    {
        (*vf)->next->prev = NULL;
        *vf = (*vf)->next;
    }else if((*end)->info == value)
    {
        (*end)->prev->next = NULL;
        *end = (*end)->prev;
    }else{
    Nod* temp;
    temp = find_value(*vf, *end, value);
    if(temp != NULL)
        {
            Nod* curent = *vf;
            while(curent->next != temp)
            {
                curent = curent->next;
            }
            curent->next->next->prev = curent;
            free(curent->next);
            curent->next = curent->next->next;
        }
    }
}

void print_doubly_list(Nod* vf, Nod* end)
{
    while(vf)
    {
        printf("%d ", vf->info);
        vf = vf->next;
    }
    printf("\n");
}

void print_rigthToLeft(Nod* vf, Nod* end)
{
    while(end)
    {
        printf("%d ", end->info);
        end = end->prev;
    }
    printf("\n");
}

int main()
{
    Nod* vf = NULL;
    Nod* end = NULL;
    int n, data;
    printf("enter n of elements: \n");
    scanf("%d", &n);
    printf("enter first element: \n");
    scanf("%d", &data);

    create_head(&vf, &end, data);
    create_add_right(&vf, &end, n);
    print_doubly_list(vf, end);
/*
    add_left(&vf, &end, 11);
    printf("\nDupa add_left:\n");
    print_doubly_list(vf, end);
    */
/*
    add_by_value(&vf, &end, 3, 100);
    print_doubly_list(vf, end);
*/
    delete_node(&vf, &end, 3);
    print_doubly_list(vf, end);
    print_rigthToLeft(vf, end);
    return 0;
}