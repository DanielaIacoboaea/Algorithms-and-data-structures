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

int succesor(int k, int vizitat[50], int n)
{
   // printf("succesor \n");
    if (vizitat[k]++ < n)
    {
        return 1;
    }else{
        return 0;
    }
}

int valid(int k, int vizitat[50], int n, int matrix[50][50])
{
    //printf("valid\n");
    if(matrix[vizitat[k-1]][vizitat[k]] == 0)
    {
        return 0;
    }else{
        for (int i = 1; i <= k - 1; i++)
        {
            if (vizitat[i] == vizitat[k])
            {
                return 0;
            }
        }
    }
    if (k == n && matrix[1][vizitat[k]] == 0)
    {
        return 0;
    }
    return 1;
}

void print(int n, int vizitat[50], int matrix[50][50])
{
   // printf("print\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", vizitat[i]);
    }
    printf("%d ", vizitat[1]);
    printf("\n");
}

void back(int k, int vizitat[50], int n, int matrix[50][50])
{
    //printf("back\n");
    //printf("k: %d\n", k);
    if (k == n)
    {
        print(n, vizitat, matrix);
    }else{
        vizitat[k] = 1;
        while (succesor(k, vizitat, n))
        {
            if (valid(k, vizitat, n, matrix))
            {
                back(k+1, vizitat, n, matrix);
            }
        }
    }
}

int main()
{
    int matrix[50][50];
    int n = 9;
    int i;
    int vizitat[50];

    for(i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }
    
    
    read_graph_matrix(matrix, n);
    print_graph_matrix(matrix, n);
    printf("\n\n");

    vizitat[1] = 1;
    vizitat[2] = 1;

    back(2, vizitat, n, matrix);
   // printf("aaaaaa\n");

    return 0;
}