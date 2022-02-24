#include <stdio.h>

void read_graph_matrix(int matrix[50][50], int n)
{
    int i, j, first_node, second_node;
    FILE *f;
    f = fopen("arb_cicluri.txt", "r");
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

void ciclu(int k, int matrix[50][50], int nNodes, int vizitat[50], int track[50], int st)
{
    printf("%d ", st);
    while (k != st)
    {
        printf("%d ", k);
        k = track[k];
    }
    printf("%d ", st);
    printf("\n");
}

void dfs_ciclu_elementar(int node, int matrix[50][50], int nNodes, int vizitat[50], int track[50], int* st, int* gasit)
{
    int k;
    vizitat[node] = 1;

    for (k = 1; k <= nNodes; k++)
    {
        if (matrix[node][k] == 1)
        {
            matrix[k][node] = 0;
            if (vizitat[k] == 0)
            {
                track[k] = node;
                vizitat[k] = 1;
                dfs_ciclu_elementar(k, matrix, nNodes, vizitat, track, st, gasit);
            }else{
                *gasit = 1;
                *st = k;
                ciclu(node, matrix, nNodes, vizitat, track, *st);
            }
        }
    }
}

int main()
{
    int a[50][50];
    int n = 5, i, start, exista;
    int vizitat[50], track[25];

    for (i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    read_graph_matrix(a, n);
    print_graph_matrix(a, n);
    printf("\n");
    
    dfs_ciclu_elementar(5, a, n, vizitat, track, &start, &exista);
    if(!exista)
    {
        printf("graful nu contine cicluri\n");
    }
    return 0;
}