/* 2 grafuri (G1 si G2)
sa se verifice daca G2 este subgraf pt G1
*/

#include <stdio.h>

void read_digraph_matrix(int matrix[25][25], int nNodes, FILE* f)
{
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

int chechIf_subgraf(int matrix_1[25][25], int matrix_2[25][25], int nNodes)
{
    int i, j;

    for (i = 1; i <= nNodes; i++)
    {
        for (j = 1; j <= nNodes; j++)
        {
            if (matrix_2[i][j] == 1 && matrix_1[i][j] != 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n = 6, i;
    int graph_matrix_g1[25][25];
    int graph_matrix_g2[25][25];

    FILE* g1;
    g1 = fopen("subgraf_g1.txt", "r");

    FILE* g2;
    g2 = fopen("subgraf_g2.txt", "r");

    read_digraph_matrix(graph_matrix_g1, n, g1);
    print_digraph_matrix(graph_matrix_g1, n);
    printf("\n");

    read_digraph_matrix(graph_matrix_g2, n, g2);
    print_digraph_matrix(graph_matrix_g2, n);
    printf("\n");

    fclose(g1);
    fclose(g2);

    if (chechIf_subgraf(graph_matrix_g1, graph_matrix_g2, n))
    {
        printf("graful g2 este subgraf al grafului g1\n");
    }else
    {
        printf("graful g2 nu este subgraf al grafului g1\n");
    }

    return 0;
}
