/* se dau listele de adiacenta pt un graf orientat
prog va afisa matricea de adiacenta
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
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

void create_matrix(int matrix[25][25], int nNodes, Nod* arr[25])
{
    int i, j;
    Nod* temp;
    for (i = 1; i <= nNodes; i++)
    {
        for (j = 1; j <= nNodes; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (i = 1; i <= nNodes; i++)
    {
        temp = arr[i];
        while(temp)
        {
            matrix[i][temp->info] = 1;
            temp = temp->next;
        }
    }
}

void print_digraph_matrix(int matrix[25][25], int nNodes)
{
    int i, j;

    for(i = 1; i <= nNodes; i++)
    {
        for(j = 1; j <= nNodes; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 5, i;
    Nod* arr_nodes[25];
    int graph_matrix[25][25];

    for (i = 1; i <= n; i++)
    {
        arr_nodes[i] = NULL;
    }

    read_digraph_list(arr_nodes, n);
    print_digraph_list(arr_nodes, n);
    printf("\n");

    create_matrix(graph_matrix, n, arr_nodes);
    print_digraph_matrix(graph_matrix, n);

    return 0;
}
