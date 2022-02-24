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

int checkIf_nodeAppears(Nod* nod_curent, Nod* vf)
{
    Nod* temp = vf;
    while(temp)
    {
        if(temp->info != nod_curent->info)
            {
                temp = temp->next;
            }else{
                return 1;
            }
    }
    return 0;
}

int distinct_char(Nod* vf)
{
    Nod* to_check = (Nod*) malloc(sizeof(Nod)); 
    to_check->info = vf->info;
    to_check->next = NULL;

    Nod* cursor = vf->next;

    while(cursor)
    {
        if(checkIf_nodeAppears(to_check, cursor))
        {
            return 0;
        }else{

            to_check->info = cursor->info;
            cursor = cursor->next;
        }
    }
    return 1;
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
    result = distinct_char(vf);
    if(result)
    {
        printf("caracterele sunt distincte\n");
    }else
    {
        printf("caracterele nu sunt distincte\n");
    }

    return 0;
}