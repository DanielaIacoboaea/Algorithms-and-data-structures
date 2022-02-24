/* graf neorientat memorat prin matricea de adiacenta
sa se afiseze toate nodurile care au gradul maxim
*/

#include <stdio.h>

void read_graph_matrix(int matrix[50][50], int n)
{
    int i, j, first_node, second_node;
    FILE *f;
    f = fopen("nodes.txt", "r");
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

int find_node_deg(int nod, int matrix[50][50], int n)
{
    int j, nodeDegree = 0;

    for(j = 1; j <= n; j++)
    {
        if (matrix[nod][j] == 1)
        {
            nodeDegree += 1;
        }
    }
    return nodeDegree;
}

int find_max_degree(int matrix[50][50], int all_degrees[50], int n)
{
    int i, j, indiv_deg, max_deg = 0;

    for (i = 1; i <= n; i++)
    {
        indiv_deg = find_node_deg(i, matrix, n);
        if (indiv_deg > max_deg)
        {
            max_deg = indiv_deg;
        }
    }
    return max_deg;
}

int main()
{
    int matrix[50][50];
    int n = 9;
    int i, j, max;
    int all_degrees[50];
    
    read_graph_matrix(matrix, n);
    print_graph_matrix(matrix, n);
    printf("\n\n");

    max = find_max_degree(matrix, all_degrees, n);
    printf("gradul maxim este: %d\n", max);
    for (i = 1; i <= n; i++)
    {
        if (max == find_node_deg(i, matrix, n))
        {
            printf("nodul %d are gradul maxim %d\n", i, max);
        }
    }
    return 0;
}