/* un graf neorientat este arbore daca este conex si nu are niciun ciclu*/

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

void dfs_ifArbore(int matrix[50][50], int nNodes, int vizitat[50], int nod, int* gasit)
{
    int k;
    vizitat[nod] = 1;

    for (k = 1; k <= nNodes; k++)
    {
        if (matrix[nod][k] == 1)
        {
            matrix[k][nod] = 0;
            if (vizitat[k] == 0)
            {
                dfs_ifArbore(matrix, nNodes, vizitat, k, gasit);
            }else
            {
                *gasit = 1;
            }
        }
    }
}

int main()
{
    int a[50][50];
    int n = 5, i, exista, sum = 0;
    int vizitat[50];

    for (i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    read_graph_matrix(a, n);
    print_graph_matrix(a, n);
    printf("\n");
    
    dfs_ifArbore(a, n, vizitat, 1, &exista);

    for (i = 1; i <= n; i++)
    {
        sum = sum + vizitat[i];
    }

    if (sum != n)
    {
        printf("graful nu este conex\n");
    }else{
        if (exista)
        {
            printf("graful are cel putin un ciclu\n");
        }else{
            printf("graful este conex si nu are niciun ciclu, deci este arbore\n");
        }
    }
    return 0;
}