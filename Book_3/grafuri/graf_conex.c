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

void check_if_conex(int matrix[50][50], int vizitat[50], int nod, int n)
{
    int k;

    vizitat[nod] = 1;

    for (k = 1; k <= n; k++)
    {
        if(matrix[nod][k] == 1 && vizitat[k] == 0)
        {
            check_if_conex(matrix, vizitat, k, n);
        }
    }
}

int main()
{
    int matrix[50][50];
    int n = 5;
    int i;
    int vizitat[50];
    bool ok = 1;

    for(i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }
    
    read_graph_matrix(matrix, n);
    print_graph_matrix(matrix, n);
    printf("\n\n");

    check_if_conex(matrix, vizitat, 1, n);

    i = 1;
    while(i <= n)
    {
        if(vizitat[i] == 0)
        {
            ok = 0;
            break;
        }
        i++;
    }
    if(ok)
    {
        printf("graful este conex\n");
    }else{
        printf("graful nu este conex\n");
    }

    return 0;
}