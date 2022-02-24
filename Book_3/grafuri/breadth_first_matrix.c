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

void breadth_first_matrix(int matrix[50][50], int n, int nod)
{
    int coada[50], vizitat[50];
    int i, start_coada, end_coada, j;

    start_coada = 1;
    end_coada = 1;

    for (i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    coada[start_coada] = nod;
    vizitat[nod] = 1;
    
    while (start_coada <= end_coada)
    {
        i = 1;
        while (i <= n)
        {
            if (matrix[coada[start_coada]][i] == 1 && vizitat[i] == 0)
            {
                end_coada++;
                coada[end_coada] = i;
                vizitat[i] = 1;
            }
            i++;
        }
        printf("%d \n", coada[start_coada]);
        start_coada++;
    }
}

int main()
{
    int a[50][50];
    int n = 7;
    int i;
    
    read_graph_matrix(a, n);
    breadth_first_matrix(a, n, 3);
    
    return 0;
}