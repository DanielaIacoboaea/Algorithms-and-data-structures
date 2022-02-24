#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    char info;
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

void add_node(Nod** vf, char data)
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
        printf("%c ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Nod* vf = NULL;

    char x;
    int enter = 1, result;
    
    do
    {
        printf("enter value: \n");
        scanf(" %c", &x);
        add_node(&vf, x);
        printf("enter another value? yes: 1, no: 0\n");
        scanf("%d", &enter);

    } while (enter);

    print_list(vf);
