#include <stdio.h>

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

int df_search_cicle(int matrix[50][50], int vizitat[50], int n, int nod)
{
    int exista = 0;
    int k;

    vizitat[nod] = 1;

    for (k = 1; k <= n; k++)
    {
        if(matrix[nod][k] == 1)
        {
            matrix[k][nod] == 0;
            if (vizitat[k] == 0)
            {
                df_search_cicle(matrix, vizitat, n, k);
            }else
            {
                exista = 1;
            }
        }
    }

    return exista;
}

int main()
{
    int matrix[50][50];
    int n = 5;
    int i, gasit;
    int vizitat[50];

    for(i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }
    
    read_graph_matrix(matrix, n);
    print_graph_matrix(matrix, n);
    printf("\n\n");

    if(gasit = df_search_cicle(matrix, vizitat, n, 1))
    {
        printf("ciclu gasit\n");
    }else{
        printf("ciclu nu exista\n");
    }
    return 0;
}