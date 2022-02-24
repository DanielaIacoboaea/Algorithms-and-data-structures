/*bfs grafuri orientate - matrice*/

#include <stdio.h>
#include <stdlib.h>

void read_digraph_matrix(int matrix[25][25], int nNodes)
{
    FILE* f;
    f = fopen("noduri_graf.txt", "r");

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

void breadth_first_matrix(int matrix[25][25], int n, int nod)
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
    int n = 6, i;
    int graph_matrix[25][25];

    read_digraph_matrix(graph_matrix, n);
    print_digraph_matrix(graph_matrix, n);
    printf("\n");

    breadth_first_matrix(graph_matrix, n, 4);

    return 0;
}
