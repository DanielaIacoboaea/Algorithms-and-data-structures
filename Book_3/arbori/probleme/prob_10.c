#include <stdio.h>

void read_graph_matrix(int matrix[25][25], int nNodes)
{
    int i, j;
    int x, y, z;
    FILE* f;
    f = fopen("retea.txt", "r");

    for (i = 1; i <= nNodes; i++)
    {
        for (j = i; j <= nNodes; j++)
        {
            matrix[i][j] = 0;
            matrix[j][i] = 0;
        }
    }
    while (!feof(f))
    {
        fscanf(f, "%d %d %d", &x, &y, &z);
        matrix[x][y] = z;
        matrix[y][x] = z;
    }
    fclose(f);
}

void print_matrix(int matrix[25][25], int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void update_adjacent_nodes(int node, int matrix[25][25], int vizitat[25], int weight[25], int track[25], int nNodes)
{
    int j;
    int inf = 3000;

    for (j = 1; j <= nNodes; j++)
    {
        if (matrix[node][j] != 0 && matrix[node][j] < weight[j] && vizitat[j] == 0)
        {
            weight[j] = matrix[node][j];
            track[j] = node;
        }
    }
}

int min_weigth_node(int vizitat[25], int weight[25], int nNodes)
{
    int i, node;
    int min = 3000;
    for (i = 1; i <= nNodes; i++)
    {
        //printf("i: %d, weigth: %d\n", i, weight[i]);
        if (weight[i] < min && vizitat[i] == 0)
        {
            min = weight[i];
            node = i;
        }
    }
   // printf("node din functie: %d\n", node);
    return node;
}

void build_connection(int start, int matrix[25][25], int vizitat[25], int weight[25], int track[25], int nNodes)
{
    int i, min_node, j;

    for (i = 1; i <= nNodes-1; i++)
    {
        min_node = min_weigth_node(vizitat, weight, nNodes);
      //  printf("min_node: %d\n", min_node);
        vizitat[min_node] = 1;
       // printf("vizitat[%d]: %d\n", min_node, vizitat[min_node]);
        update_adjacent_nodes(min_node, matrix, vizitat, weight, track, nNodes);

    }
}

void print_connection(int track[25], int matrix[25][25], int nNodes, int weight[25])
{
    int i;
    for(i = 2; i <= nNodes; i++)
    {
        printf("%d -> %d - %d m\n", track[i], i, weight[i]);
    }
}

int main()
{
    int matrix[25][25];
    int n = 5, inf = 3000, i;
    int vizitat[25], track[25], weight[25];

    read_graph_matrix(matrix, n);
    print_matrix(matrix, n);
    printf("\n");

    track[1] = 0;

    for (i = 1; i <= n; i++)
    {
        weight[i] = inf;
        vizitat[i] = 0;
    }

    vizitat[1] = 1;
    weight[1] = 0;

    update_adjacent_nodes(1, matrix, vizitat, weight, track, n);

    build_connection(1, matrix, vizitat, weight, track, n);
    print_connection(track, matrix, n, weight);
    printf("\n");
    
    return 0;
}