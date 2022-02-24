
#include <stdio.h>

void read_graph_matrix(int matrix[50][50], int n)
{
    int i, j, first_node, second_node;
    FILE *f;
    f = fopen("arb_noduri.txt", "r");
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

void dfs_arbore_partial(int matrix[50][50], int nNodes, int nod_start, int vizitat[50])
{
    int k;
    vizitat[nod_start] = 1;

    for (k = 1; k <= nNodes; k++)
    {
        if (matrix[nod_start][k] == 1 && vizitat[k] == 0)
        {
            printf("%d ", k);
            dfs_arbore_partial(matrix, nNodes, k, vizitat);
        }
    }

}

int main()
{
    int a[50][50];
    int n = 5, i;
    int vizitat[50];

    for (i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    read_graph_matrix(a, n);
    print_graph_matrix(a, n);
    printf("\n");

    dfs_arbore_partial(a, n, 1, vizitat);
    printf("\n");
    
    return 0;
}