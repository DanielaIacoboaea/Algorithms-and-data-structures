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

void dfs_townsNear_turist(int town, double digraph_matrix[25][25], int nNodes, int vizitat[25])
{
    int k;
    printf("%d ", town);

    vizitat[town] = 1;

    for (k = 1; k <= nNodes; k++)
    {
        if ((digraph_matrix[town][k] != 0 && digraph_matrix[town][k] != 30000) && vizitat[k] == 0)
        {
            dfs_townsNear_turist(k, digraph_matrix, nNodes, vizitat);
        }
    }
    printf("\n");
}

void print_path_reverse(int b, int track[25])
{
    printf("b: %d\n", b);
    if (b != 0)
    {
        print_path_reverse(track[b], track);
        printf("%d ", b);
    }
}

int dfs_townReturn_turist(int town, double digraph_matrix[25][25], int nNodes, int vizitat[25], int track[25], int* b, int* gasit)
{
    int k;

    vizitat[town] = 1;

    for (k = 1; k <= nNodes; k++)
    {
        if (digraph_matrix[town][k] != 0 && digraph_matrix[town][k] != 30000)
        {
            printf("am intrat in if: vizitat[%d]: %d\n", k, vizitat[k]);
            printf("town: %d\n", town);
            if (vizitat[k] == 0)
            {
                printf("am intrat in if din if\n");
                track[k] = town;
                printf("track[%d]: %d\n", k, track[k]);
                dfs_townReturn_turist(k, digraph_matrix, nNodes, vizitat, track, b, gasit);
            }else{
                *b = track[k];
                printf("b din else: %d\n", *b);
                *gasit = 1;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n = 5, i, turist, b, exista;
    double graph_matrix_cost[25][25];
    int vizitat[25], track[25];


    for (i = 1; i <=n; i++)
    {
        vizitat[i] = 0;
        track[i] = 0;
    }

    printf("enter starting town: \n");
    scanf("%d", &turist);

    read_cost_matrix(graph_matrix_cost, n);
    print_cost_matrix(graph_matrix_cost, n);
    printf("\n");
    
    /*
    dfs_townsNear_turist(turist, graph_matrix_cost, n, vizitat);
    */

    /*
    dfs_townReturn_turist(turist, graph_matrix_cost, n, vizitat, track, &b, &exista);

    if (exista)
    {
        printf("se poate reveni in orasul %d\n", turist);
        printf("b in if reverse: %d\n", b);
        print_path_reverse(b, track);
        printf("%d\n", turist);
    }else{
        printf("nu se poate reveni in orasul %d\n", turist);
    }

    for(i = 1; i <= n; i++)
    {
        printf("track[%d]: %d\n", i, track[i]);
    }
    */

    return 0;
}
