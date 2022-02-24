#include <stdio.h>

void read_cost_matrix(double graph_matrix_cost[25][25], int n)
{
    FILE* f;
    f = fopen("rf_costuri.txt", "r");

    int v1, v2, i, j;
    double inf = 30000, cost;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
            {
                graph_matrix_cost[i][j] == 0;
            }else{
                graph_matrix_cost[i][j] = inf;
            }
        }
    }
    while(!feof(f))
    {
        fscanf(f, "%d %d %lf", &v1, &v2, &cost);
        graph_matrix_cost[v1][v2] = cost;
    }
    fclose(f);
}

void print_cost_matrix(double graph_matrix_cost[25][25], int n)
{
    int i, j;
    double inf = 30000;
    for (i = 1; i <=n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if(graph_matrix_cost[i][j] == inf)
            {
                printf("%1.lf ", graph_matrix_cost[i][j]);
            }else{
                printf("%1.lf     ", graph_matrix_cost[i][j]);
            }
        }
        printf("\n");
    }
}

void cost_drum(double graph_matrix_cost[25][25], int nNodes)
{
    int i, j, k;

    for (k = 1; k <= nNodes; k++)
    {
        for (i = 1; i <= nNodes; i++)
        {
            for (j = 1; j <= nNodes; j++)
            {
                if (graph_matrix_cost[i][j] > graph_matrix_cost[i][k] + graph_matrix_cost[k][j])
                {
                    graph_matrix_cost[i][j] = graph_matrix_cost[i][k] + graph_matrix_cost[k][j];
                }
            }
        }
    }
}

void drum(double graph_matrix_cost[25][25], int nNodes, int i, int j)
{
    int k = 1;
    int gasit = 0;
    while ((k <= nNodes) && !gasit)
    {
        printf("graph_matrix_cost[%d][%d]: %1.lf \n", i, j, graph_matrix_cost[i][j]);
        printf("graph_matrix_cost[%d][%d]: %.1lf + graph_matrix_cost[%d][%d]: %1.lf = %.1lf\n", i, k,  graph_matrix_cost[i][k], k, j, graph_matrix_cost[k][j], graph_matrix_cost[i][k] + graph_matrix_cost[k][j]);
        if (i != k && j != k && graph_matrix_cost[i][j] == graph_matrix_cost[i][k] + graph_matrix_cost[k][j])
        {
            drum(graph_matrix_cost, nNodes, i, k);
            drum(graph_matrix_cost, nNodes, k, j);
            gasit = 1;
        }
        k++;
    }
    if (!gasit)
    {
        printf("%d ", j);
    }
}

void print_drum(double graph_matrix_cost[25][25], int nNodes, int Nod_initial, int Nod_final)
{
    if (graph_matrix_cost[Nod_initial][Nod_final] < 30000)
    {
        printf("drumul de la %d la %d are costul %.1lf\n", Nod_initial, Nod_final, graph_matrix_cost[Nod_initial][Nod_final]);
        printf("%d ", Nod_initial);
        drum(graph_matrix_cost, nNodes, Nod_initial, Nod_final);

    }else{
        printf("nu exista drum de la %d la %d\n", Nod_initial, Nod_final);
    }
}

int main()
{
    int n = 5, i;
    double graph_matrix_cost[25][25];

    read_cost_matrix(graph_matrix_cost, n);
    print_cost_matrix(graph_matrix_cost, n);
    printf("\n");

    cost_drum(graph_matrix_cost, n);
    print_cost_matrix(graph_matrix_cost, n);
    printf("\n");

    print_drum(graph_matrix_cost, n, 2, 5);
    printf("\n");

    return 0;
}
