/*identificarea componentelor conexe pt graf orientat
si printarea varfurilor pentru fiecare componenta conexa in parte*/

#include <stdio.h>
#include <stdlib.h>

void read_digraph_matrix(int matrix[25][25], int nNodes)
{
    FILE* f;
    f = fopen("vf_conexe.txt", "r");

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

void dfs_after(int nod, int matrix[25][25], int after_node[25], int nNodes, int counter)
{
   // printf("dfs_after\n");
    int k;
    after_node[nod] = counter;

    for(k = 1; k <= nNodes; k++)
    {
        if (matrix[nod][k] == 1 && after_node[k] == 0)
        {
            dfs_after(k, matrix, after_node, nNodes, counter);
        }
    }
}

void dfs_before(int nod, int matrix[25][25], int before_node[25], int nNodes, int counter)
{
   // printf("dfs_before\n");
    int k;
    before_node[nod] = counter;

    for(k = 1; k <= nNodes; k++)
    {
        if (matrix[k][nod] == 1 && before_node[k] == 0)
        {
            dfs_before(k, matrix, before_node, nNodes, counter);
        }
    }
}

int main()
{
    int n = 7, i, j, count_conex = 1;
    int graph_matrix[25][25];
    int after_node[25], before_node[25];

    read_digraph_matrix(graph_matrix, n);
    print_digraph_matrix(graph_matrix, n);
    printf("\n");

    for (i = 1; i <= n; i++)
    {
       // printf("bbbb\n");
        after_node[i] = 0;
        before_node[i] = 0;
    }

    for (i = 1; i <= n; i++)
    {
       // printf("cccccccc\n");
        if (after_node[i] == 0)
        {
            after_node[i] = count_conex;

            dfs_after(i, graph_matrix, after_node, n, count_conex);
            dfs_before(i, graph_matrix, before_node, n, count_conex);

            for(j = 1; j <= n; j++)
            {
                if (after_node[j] != before_node[j])
                {
                    after_node[j] = 0;
                    before_node[j] = 0;
                }
            }
            count_conex += 1;
        }
    }

    for (i = 1; i < count_conex; i++)
    {
       // printf("aaaaaa\n");
        printf("componenta conexa nr %d\n", i);
        for (j = 1; j <= n; j++)
        {
            if (after_node[j] == i)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}
