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

void ciclu(int indice, int matrix[50][50], int n, int* sfarsit, int eulerian[50])
{
    printf("bbbbbbbbb\n");
    int j, k;
    for (k = 1; k <= n; k++)
    {
        if(matrix[eulerian[indice]][k] == 1)
        {
            matrix[eulerian[indice]][k] == 0;
            matrix[k][eulerian[indice]] == 0;
            sfarsit++;
            for (j = *sfarsit; j > indice; j--)
            {
                printf("cccccccc\n");
                eulerian[j] = eulerian[j-1];
            }
            eulerian[++indice] = k;
            ciclu(indice, matrix, n, sfarsit, eulerian);
        }
    }
}

int main()
{
    int matrix[50][50];
    int n = 7;
    int i, sfarsit = 1;
    int vizitat[50], eulerian[50];

    for(i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    eulerian[1] = 1;
    
    read_graph_matrix(matrix, n);
    print_graph_matrix(matrix, n);
    printf("\n\n");

    for (i = 1; eulerian[i]; i++)
    {
        ciclu(i, matrix, n, &sfarsit, eulerian);
        printf("aaaaaaaa\n");
    }
    for (i = 1; i <= sfarsit; i++)
    {
        printf("%d ", eulerian[i]);
    }
}