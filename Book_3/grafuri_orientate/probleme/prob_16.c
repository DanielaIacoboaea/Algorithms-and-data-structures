/* se da matricea de adiacenta 
se cere sa se listeze toate circuitele de lungime 3
*/
/*citirea, memorarea si afisarea grafurilor orientate*/

#include <stdio.h>
#include <stdlib.h>

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

int dfs_path(int matrix[25][25], int vizitat[25], int track[25], int nNodes, int start_node)
{
    int k, exista = 0;

    vizitat[start_node] = 1;

    for (k = 1; k <= nNodes; k++)
    {
        if(matrix[start_node][k] == 1)
        {
            if (vizitat[k] == 0)
            {
                track[k] = start_node;
                dfs_path(matrix, vizitat, track, nNodes, k);
            }else{
                exista = 1;
            }
        }
    }
    return exista;
}

void print_path(int track[25], int end_node)
{
    if (track[end_node] != 0)
    {
        print_path(track, track[end_node]);
        printf("%d ", track[end_node]);
    }
}

void reset_vizitat(int vizitat[25], int n)
{
    for(int i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }
}

int main()
{
    int n = 5, i, j;
    int graph_matrix[25][25];
    int vizitat[25], track[25];

    for(i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }
   
    read_digraph_matrix(graph_matrix, n);
    print_digraph_matrix(graph_matrix, n);
    printf("\n");

    for (i = 1; i <= n; i++)
    {
        if(dfs_path(graph_matrix, vizitat, track, n, i))
        {
            printf("circuit exista din nodul %d\n", i);
            //print_path(track, i);
        }else{
            printf("circuit nu exista din nodul %d\n", i);
        }
        reset_vizitat(vizitat, n);
    }
    return 0;
}
