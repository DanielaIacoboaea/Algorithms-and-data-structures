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

void drum(int nod, int track[25])
{
    if (track[nod])
    {
        drum(track[nod], track);
        printf("%d ", nod);
    }
}

int main()
{
    int n = 5, i, j, x, poz, min;
    double graph_matrix_cost[25][25];
    double cost_x[25];
    int selectat[25];
    int track[25];
    double infi = 30000;

    printf("enter x:\n");
    scanf("%d", &x);

    read_cost_matrix(graph_matrix_cost, n);
    print_cost_matrix(graph_matrix_cost, n);
    printf("\n");

    for (i = 1; i <= n; i++)
    {
        if (i == x)
        {
            selectat[i] = 1;
        }else{
            selectat[i] = 0;
        }
        cost_x[i] = graph_matrix_cost[x][i];

        if(i == x || graph_matrix_cost[x][i] == infi)
        {
            track[i] = 0;
        }else{
            track[i] = x;
        }
    }

    for (i = 1; i <= n-1; i++)
    {
        min = infi;
        for (j = 1; j <= n; j++)
        {
            if (selectat[j] == 0)
            {
                if (cost_x[j] < min)
                {
                    min = cost_x[j];
                    poz = j;
                }
            }
        }
        selectat[poz] = 1;
        for (j = 1; j <= n; j++)
        {
            if (selectat[j] == 0)
            {
                if (cost_x[j] > cost_x[poz] + graph_matrix_cost[poz][j])
                {
                    cost_x[j] = cost_x[poz] + graph_matrix_cost[poz][j];
                    track[j] = poz;
                }
            }
        }
    }
    printf("cost catre fiecare varf din graf: \n");
    for (i = 1; i <= n; i++)
    {
        printf("%.1lf ", cost_x[i]);
    }
    printf("\n");

    for (i = 1; i <= n; i++)
    {
        if (i != x)
        {
            if (track[i])
            {
                printf("distanta de la %d la %d este: %.1lf\n", x, i, cost_x[i]);
                printf("%d ", x);
                drum(i, track);
                printf("\n");
            }else{
                printf("nu exista drum de la %d la %d\n", x, i);
            }
        }
    }

    return 0;
}
