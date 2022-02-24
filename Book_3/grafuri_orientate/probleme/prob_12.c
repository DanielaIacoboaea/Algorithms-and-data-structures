/* graf orientat;
o succesiune de varfuri, sa se decida daca este lant
matrice de adiacenta + liste de adiacenta
*/

#include <stdio.h>

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

void dfs_path(int matrix[25][25], int vizitat[25], int track[25], int nNodes, int start_node)
{
    int k;
    vizitat[start_node] = 1;
    for (k = 1; k <= nNodes; k++)
    {
        if((matrix[start_node][k] == 1 && vizitat[k] == 0) || (matrix[k][start_node] == 1 && vizitat[k] == 0))
        {
            track[k] = start_node;
            dfs_path(matrix, vizitat, track, nNodes, k);
        }
    }
}

void print_path(int track[25], int end_node)
{
    if (track[end_node] != 0)
    {
        print_path(track, track[end_node]);
        printf("%d ", track[end_node]);
    }
}

int main()
{
    int n = 5, i, x, y;
    int graph_matrix[25][25];
    printf("enter x,y: \n");
    scanf("%d,%d", &x, &y);
    int vizitat[25], track[25];

    track[x] = 0;

    read_digraph_matrix(graph_matrix, n);
    print_digraph_matrix(graph_matrix, n);
    printf("\n");

    for (i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    dfs_path(graph_matrix, vizitat, track, n, x);

    if (track[y] == 0)
    {
        printf("nu exista lant de la %d la %d\n", x, y);
    }else{

        printf("lantul de la %d la %d trece prin nodurile: \n", x, y);
        print_path(track, y);
        printf("%d ", y);
        printf("\n");
    }
    return 0;
}
