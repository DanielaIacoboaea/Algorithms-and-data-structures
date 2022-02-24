/*citirea, memorarea si afisarea grafurilor orientate*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* next;
} Nod;

typedef struct arc{
    int x;
    int y;
} arc;

void read_digraph_matrix(int matrix[25][25], int nNodes)
{
    FILE* f;
    f = fopen("noduri_graf.txt", "r");

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

void read_digraph_static(int matrix[25][25], int nNodes, int start[25], int track[2][25])
{
    FILE* f;
    f = fopen("noduri_graf.txt", "r");

    int v1, v2, i, j, k = 0;

    for(i = 1; i <= nNodes; i++)
    {
        start[i] = 0;
    }

    while(!feof(f))
    {
        fscanf(f, "%d %d", &v1, &v2);
        k++;
        track[0][k] = v2;
        track[1][k] = start[v1];
        start[v1] = k;
    }
    fclose(f);
}

void print_digraph_static(int matrix[25][25], int nNodes, int start[50], int track[2][25])
{
    int i, temp;
    
    for (i = 1; i <= nNodes; i++)
    {
        if (start[i] == 0)
        {
            printf("nodul %d nu are noduri adiacente spre exterior\n", i);
        }else
        {
            printf("nodurile adiacente spre exterior cu %d: \n", i);
            temp = start[i];
            while (temp)
            {
                printf("%d -> %d; ", i, track[0][temp]);
                temp = track[1][temp];
            }
            printf("\n");
        }
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

void read_digraph_list(Nod* arr[25], int nNodes)
{
    FILE* f;
    f = fopen("noduri_graf.txt", "r");

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

int read_digraph_struct(arc arr[25], int nNodes)
{
    FILE* f;
    f = fopen("noduri_graf.txt", "r");

    int i, v1, v2;
    i = 0;
    while (!feof(f))
    {
        i++;
        fscanf(f, "%d %d", &v1, &v2);
        arr[i].x = v1;
        arr[i].y = v2;
    }

    fclose(f);

    return i;
}

void print_digraph_struct(arc arr[25], int arcs)
{
    int i;
    for (i = 1; i <= arcs; i++)
    {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
}

void read_cost_matrix(double graph_matrix_cost[25][25], int n)
{
    FILE* f;
    f = fopen("noduri_cost.txt", "r");

    int v1, v2, i, j;
    double inf = 30000, cost;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
            {
                graph_matrix_cost[i][j] == 0;
            }else{
                graph_matrix_cost[i][j] = inf;
            }
        }
    }
    while(!feof(f))
    {
        fscanf(f, "%d %d %lf", &v1, &v2, &cost);
        graph_matrix_cost[v1][v2] = cost;
    }
    fclose(f);
}

void print_cost_matrix(double graph_matrix_cost[25][25], int n)
{
    int i, j;
    double inf = 30000;
    for (i = 1; i <=n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if(graph_matrix_cost[i][j] == inf)
            {
                printf("%1.lf ", graph_matrix_cost[i][j]);
            }else{
                printf("%1.lf     ", graph_matrix_cost[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int n = 5, i;
    int graph_matrix[25][25], track[2][25];
    double graph_matrix_cost[25][25];
    int start[25];
    Nod* arr_nodes[25];
    arc arr[25];
    int nArcs;

    for (i = 1; i <= n; i++)
    {
        arr_nodes[i] = NULL;
    }

    /*
    read_digraph_matrix(graph_matrix, n);
    print_digraph_matrix(graph_matrix, n);
    */
    /*
    read_digraph_static(graph_matrix, n, start, track);
    print_digraph_static(graph_matrix, n, start, track);
    */

    /*
    read_digraph_list(arr_nodes, n);
    print_digraph_list(arr_nodes, n);
    */
    
    /*
    nArcs = read_digraph_struct(arr, n);
    print_digraph_struct(arr, nArcs);
    */ 

    read_cost_matrix(graph_matrix_cost, n);
    print_cost_matrix(graph_matrix_cost, n);

    return 0;
}
