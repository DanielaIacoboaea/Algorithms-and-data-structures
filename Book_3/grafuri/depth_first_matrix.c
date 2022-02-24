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

void depth_first_matrix(int a[50][50], int n, int nod, int vizitat[50])
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
    int a[50][50];
    int n = 7;
    int i;
    int vizitat[50];

    for(i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }
    
    read_graph_matrix(a, n);
    print_graph_matrix(a, n);
    printf("\n\n");

    depth_first_matrix(a, n, 1, vizitat);
    return 0;
}