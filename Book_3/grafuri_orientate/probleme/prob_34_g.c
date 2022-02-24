/* n orase legate prin strazi cu sens unic 
un turist pleaca cu masina din orasul k dat
se cunosc distantele dintre orase
a) lista oraselor in care turistul poate ajunge - DONE
b) lista oraselor in care turistul poate ajunge, dar se poate si intoarce (fara sa se repete) 
c) drumul cu distanta minima intre k si celelalte orase
d) orasul cel mai apropiat de orasul k
e) orasele de la k care se pot vizita si pt care drumul pana la ele trece exact prin 3 orase (in afara de ele) + lungime drum
f) crescator - al 4 - lea oras de la k - distanta
g) drumurile minime intre oricare perechi de orase (trec doar prin a, b, c)
*/

#include <stdio.h>

void read_cost_matrix(double graph_matrix_cost[25][25], int n)
{
    FILE* f;
    f = fopen("turist.txt", "r");

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

void min_cost_all_paths(double graph_matrix_cost[25][25], int nNodes)
{
    int k, i, j;

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

void print_path(double graph_matrix_cost[25][25], int nNodes, int i, int j)
{
    int k = 1;
    int gasit = 0;
    while ((k <= nNodes) && !gasit)
    {
        if (i != k && j != k && graph_matrix_cost[i][j] == graph_matrix_cost[i][k] + graph_matrix_cost[k][j])
        {
            print_path(graph_matrix_cost, nNodes, i, k);
            print_path(graph_matrix_cost, nNodes, k, j);
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
        print_path(graph_matrix_cost, nNodes, Nod_initial, Nod_final);

    }else{
        printf("nu exista drum de la %d la %d\n", Nod_initial, Nod_final);
    }
}

int main()
{
    int n = 6, i, turist, k, end;
    double graph_matrix_cost[25][25];
    int vizitat[25];
    double infi = 30000;

    printf("enter starting town: \n");
    scanf("%d", &turist);

    printf("enter ending town: \n");
    scanf("%d", &end);

    read_cost_matrix(graph_matrix_cost, n);
    print_cost_matrix(graph_matrix_cost, n);
    printf("\n");
    
    min_cost_all_paths(graph_matrix_cost, n);
    print_cost_matrix(graph_matrix_cost, n);
    printf("\n");

    print_drum(graph_matrix_cost, n, turist, end);
    printf("\n");

    
    return 0;
}
