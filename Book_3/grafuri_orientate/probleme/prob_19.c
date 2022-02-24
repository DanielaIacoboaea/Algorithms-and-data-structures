/* sa se afiseze daca exista o "vedeta" - pers cunoscuta de toate celelalte, 
dar care nu cunoaste pe nimeni din grup
*/

#include <stdio.h>

typedef struct degree_graph{
    int in_deg;
    int ex_deg;
} degree_graph;

void read_digraph_matrix(int matrix[25][25], int nNodes)
{
    FILE* f;
    f = fopen("pers_vedeta.txt", "r");

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

int find_degreeExtern(int matrix[25][25], int nNodes, int node)
{
    int j, count_extern = 0;
    for (j = 1; j <= nNodes; j++)
    {
        if (matrix[node][j] == 1)
        {
            count_extern++;
        }
    }
    return count_extern;
}

int find_degreeIntern(int matrix[25][25], int nNodes, int node)
{
    int i, count_intern = 0;
    for (i = 1; i <=nNodes; i++)
    {
        if(matrix[i][node] == 1)
        {
            count_intern++;
        }
    }
    return count_intern;
}

int main()
{
    int n = 5, i, max = 0, persoana;
    int graph_matrix[25][25];
    degree_graph degrees[25];

    read_digraph_matrix(graph_matrix, n);
    print_digraph_matrix(graph_matrix, n);
    printf("\n");

    for (i = 1; i <= n; i++)
    {
        degrees[i].in_deg = find_degreeIntern(graph_matrix, n, i);
        degrees[i].ex_deg = find_degreeExtern(graph_matrix, n, i);
        printf("nod: %d, grad extern: %d, grad intern: %d\n", i, degrees[i].ex_deg, degrees[i].in_deg);

        if (degrees[i].in_deg > max)
        {
            max = degrees[i].in_deg;
            persoana = i;
        }
    }

    if(degrees[persoana].ex_deg == 0)
    {
        printf("persoana 'vedeta' care este cunoscuta de tot grupul dar nu cunoaste pe nimeni este %d\n", persoana);
    }else
    {
        printf("nu exista o 'vedeta'\n");
    }

    return 0;
}