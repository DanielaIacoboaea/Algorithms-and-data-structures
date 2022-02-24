#include <stdio.h>
#include <stdlib.h>

void read_cost_matrix(double graph_matrix_cost[25][25], int n)
{
    FILE* f;
    f = fopen("prim_cost.txt", "r");

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
        graph_matrix_cost[v2][v1] = cost;
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

int main()
{
    int n = 5, i, j, k, line, column;
    double graph_matrix_cost[25][25];
    double inf = 30000, min;
    int vizitat[25];

    for (i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    vizitat[1] = 1;

    read_cost_matrix(graph_matrix_cost, n);
    print_cost_matrix(graph_matrix_cost, n);

    for (k = 1; k <= n-1; k++)
    {
        min = inf;
        printf("k: %d, min loop k: %.1lf\n", k, min);
        for (i = 1; i <= n; i++)
        {
            printf("i: %d min loop i: %.1lf\n", i, min);
            for (j = 1; j <= n; j++)
            {
                printf("j: %d min loop j: %.1lf\n", j, min);
                if (vizitat[i] == 1 && vizitat[j] == 0)
                {
                    if (min > graph_matrix_cost[i][j])
                    {
                        min = graph_matrix_cost[i][j];
                        line = i;
                        column = j;
                        printf("j: %d min loop j: %.1lf\n", j, min);
                    }
                }
            }
        }
        printf("%d - %d: %.1lf\n", line, column, min);
        vizitat[column] = 1;
    }
    return 0;
}
