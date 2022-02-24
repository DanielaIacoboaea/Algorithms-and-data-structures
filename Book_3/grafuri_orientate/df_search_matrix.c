/*dfs grafuri orientate - matrice*/

#include <stdio.h>
#include <stdlib.h>

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

void depth_first_matrix(int a[25][25], int n, int nod, int vizitat[50])
{
    int k;

    printf("%d \n", nod);
    vizitat[nod] = 1;

    for(k = 1; k <= n; k++)
    {
        if(a[nod][k] == 1 && vizitat[k] == 0)
        {
            depth_first_matrix(a, n, k, vizitat);
        }
    }
}

int main()
{
    int n = 6, i;
    int graph_matrix[25][25];

    int vizitat[50];

    for(i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    read_digraph_matrix(graph_matrix, n);
    print_digraph_matrix(graph_matrix, n);
    printf("\n");

    depth_first_matrix(graph_matrix, n, 1, vizitat);

    return 0;
}
