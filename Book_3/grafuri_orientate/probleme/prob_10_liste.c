/*citirea, memorarea si afisarea grafurilor orientate*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* next;
} Nod;

typedef struct degree_graph{
    int in_deg;
    int ex_deg;
} degree_graph;

Nod* find_end(Nod* curent)
{
    while(curent->next)
    {
        curent = curent->next;
    }
    return curent;
}

void read_digraph_list(Nod* arr[25], int nNodes)
{
    FILE* f;
    f = fopen("grad.txt", "r");

    int v1, v2;
    Nod* end;
    Nod* add_new;

    while(!feof(f))
    {
        fscanf(f, "%d %d", &v1, &v2);

        if (arr[v1] == NULL)
        {
            add_new = (Nod*) malloc(sizeof(Nod));
            add_new->info = v2;
            add_new->next = NULL;
            arr[v1] = add_new;
        }else{
            end = find_end(arr[v1]);
            add_new = (Nod*) malloc(sizeof(Nod));
            add_new->info = v2;
            add_new->next = NULL;
            end->next = add_new;
        }
    }
    fclose(f);
}

void print_digraph_list(Nod* arr[25], int nNodes)
{
    int i;
    Nod* curent;

    for (i = 1; i <= nNodes; i++)
    {
        curent = arr[i];
        if (curent == NULL)
        {
            printf("nodul %d nu are noduri adiacente spre exterior\n", i);
        }else{
            printf("nodurile adiacente cu %d spre exterior sunt: \n", i);
            while (curent)
            {
                printf("%d -> %d; ", i, curent->info);
                curent = curent->next;
            }
        }
        printf("\n");
    }
}

int find_degExtern(Nod* arr[25], int nNodes, int node)
{
    int count_deg_extern = 0;
    Nod* temp = arr[node];

    while(temp)
    {
        count_deg_extern++;
        temp = temp->next;
    }
    return count_deg_extern;
}

int find_degIntern(Nod* arr[25], int nNodes, int node)
{
    int i, count_deg_intern = 0;
    Nod* temp;

    for (i = 1; i <= nNodes; i++)
    {
        if(i != node)
        {
            temp = arr[i];
            while(temp)
            {
                if (temp->info == node)
                {
                    count_deg_intern++;
                }
                temp = temp->next;
            }
        }
    }
    return count_deg_intern;
}

int main()
{
    int n = 5, i;
    Nod* arr_nodes[25];
    degree_graph degrees[25];

    for (i = 1; i <= n; i++)
    {
        arr_nodes[i] = NULL;
    }

    read_digraph_list(arr_nodes, n);
    print_digraph_list(arr_nodes, n);
    printf("\n");
    
    for (i = 1; i <= n; i++)
    {
        degrees[i].in_deg = find_degIntern(arr_nodes, n, i);
        degrees[i].ex_deg = find_degExtern(arr_nodes, n, i);
        printf("nod: %d, grad extern: %d, grad intern: %d\n", i, degrees[i].ex_deg, degrees[i].in_deg);
    }
    return 0;
}
