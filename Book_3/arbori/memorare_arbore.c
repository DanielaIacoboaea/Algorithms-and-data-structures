
#include <stdio.h>

void read_graph_matrix(int matrix[50][50], int n)
{
    int i, j, first_node, second_node;
    FILE *f;
    f = fopen("mem_arbore.txt", "r");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    while(!feof(f))
    {
        fscanf(f, "%d %d", &first_node, &second_node);
        matrix[first_node][second_node] = 1;
        matrix[second_node][first_node] = 1;
    }
    fclose(f);
}

void print_graph_matrix(int matrix[50][50], int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void read_graph_ascending(int matrix[50][50], int vizitat[50], int track[50], int nNodes, int start_node)
{
    int k;
    vizitat[start_node] = 1;

    for (k = 1; k <= nNodes; k++)
    {
        if (matrix[start_node][k] == 1 && vizitat[k] == 0)
        {
            track[k] = start_node;
            //printf("track[%d]: %d\n", k, track[k]);
            read_graph_ascending(matrix, vizitat, track, nNodes, k);
        }
    }
}

int main()
{
    int a[50][50];
    int n = 5, i;
    int vizitat[50], track[50];

    for (i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    read_graph_matrix(a, n);
    print_graph_matrix(a, n);
    printf("\n");
    
    read_graph_ascending(a, vizitat, track, n, 1);

    for (i = 1; i <= n; i++)
    {
        printf("t[%d]: %d \n", i, track[i]);
    }

    return 0;
}