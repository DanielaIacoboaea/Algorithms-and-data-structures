#include <stdio.h>
#include <stdbool.h>

void read_graph_matrix(int matrix[50][50], int n)
{
    int i, j, first_node, second_node;
    FILE *f;
    f = fopen("noduri.txt", "r");
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

void df_search_bipartit(int nod, int v, int matrix[50][50], int vizitat[50], int multime[50], int* bi, int n)
{
    int k;
    multime[nod] = v;
    vizitat[nod] = 1;
    v = v * -1;

    for(k = 1; k <= n; k++)
    {
        if (matrix[nod][k] == 1)
        {
            if (vizitat[k] == 0)
            {
                df_search_bipartit(k, v, matrix, vizitat, multime, bi, n);
            }else if (multime[k] != v)
            {
                bi = 0;
            }
        }
    }

}

int main()
{
    int matrix[50][50];
    int n = 7, bipart = 1;
    int i, j;
    int multime[50], vizitat[50];

    for (i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }


    read_graph_matrix(matrix, n);
    print_graph_matrix(matrix, n);
    printf("\n\n");

    df_search_bipartit(1, 1, matrix, vizitat, multime, &bipart, n);

    if(bipart)
    {
        printf("Multuminea de noduri A:\n");
        for(j = 1; j <= n; j++)
        {
            if (multime[j] == 1)
            {
                printf("%d ", j);
            }
        }
        printf("\nMultuminea de noduri B:\n");
        for(j = 1; j <= n; j++)
        {
            if (multime[j] == -1)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}