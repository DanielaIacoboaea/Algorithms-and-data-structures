/* se da matricea de adiacenta pt un graf orientat
prog va afisa listele de adiacenta
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* next;
} Nod;

void read_digraph_matrix(int matrix[25][25], int nNodes)
{
    FILE* f;
    f = fopen("grad.txt", "r");

    int v1, v2, i, j;

    for (i = 1; i <= nNodes; i++)
    {
        for (j = 1; j <= nNodes; j++)
        {
            matrix[i][j] = 0;
        }
    }

    while (!feof(f))
    {
        fscanf(f,"%d %d", &v1, &v2);
        matrix[v1][v2] = 1;
    }
    fclose(f);
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

Nod* find_end(Nod* curent)
{
    while(curent->next)
    {
        curent = curent->next;
    }
    return curent;
}

void create_list(int matrix[25][25], int nNodes, Nod* arr[25])
{
    int i, j;
    Nod* end;
    Nod* add_node;

    for(i = 1; i <=nNodes; i++)
    {
        for (j = 1; j <= nNodes; j++)
        {
            if(matrix[i][j] == 1)
            {
                if (arr[i] == NULL)
                {
                    add_node = (Nod*) malloc(sizeof(Nod));
                    add_node->info = j;
                    add_node->next = NULL;
                    arr[i] = add_node;
                }else{
                    end = find_end(arr[i]);
                    add_node = (Nod*) malloc(sizeof(Nod));
                    add_node->info = j;
                    end->next = add_node;
                }
            }
        }
    }
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

int main()
{
    int n = 5, i;
    int graph_matrix[25][25];
    Nod* arr_nodes[25];

    for (i = 1; i <= n; i++)
    {
        arr_nodes[i] = NULL;
    }

    read_digraph_matrix(graph_matrix, n);
    print_digraph_matrix(graph_matrix, n);
    printf("\n");

    create_list(graph_matrix, n, arr_nodes);
    print_digraph_list(arr_nodes, n);
    printf("\n");

    return 0;
}
