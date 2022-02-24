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

typedef struct tail{
    int town;
    int path_length;
    double path_cost;

} tail;

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

void bfs_threeLength_path(double graph_matrix_cost[25][25], tail bfs_paths[25], int vizitat[25], int node, int nNodes)
{
    //printf("bbbbbb\n");

    int k, st_tail = 1, end_tail = 1, i, j, count = 0;
    double infi = 30000;

    for (i = 1; i <= nNodes; i++)
    {
        vizitat[i] = 0;
    }

    bfs_paths[st_tail].town = node;
    bfs_paths[st_tail].path_length = count;
    bfs_paths[st_tail].path_cost = graph_matrix_cost[node][node];
    vizitat[node] = 1;

    count += 1;

    while (st_tail <= end_tail)
    {
       // printf("cccccccc\n");
        //count++;
        k = 1;
        while (k <= nNodes)
        {
            //printf("dddddddd\n");
            if (graph_matrix_cost[bfs_paths[st_tail].town][k] != infi && graph_matrix_cost[bfs_paths[st_tail].town][k] != 0)
            {
                if (vizitat[k] == 0)
                {
                    end_tail++;
                    bfs_paths[end_tail].town = k;
                    bfs_paths[end_tail].path_length = count;
                    bfs_paths[end_tail].path_cost = bfs_paths[st_tail].path_cost + graph_matrix_cost[bfs_paths[st_tail].town][k];
                    vizitat[k] = 1;
                }
            }
            k++;
        }
        st_tail++;
        count = bfs_paths[st_tail].path_length + 1;
        //count++;
       // printf("bfs_paths[end_tail].town: %d\n", bfs_paths[st_tail].town);
       // printf("count: %d\n", count);
    }
}

int main()
{
    int n = 6, i, turist, l, ok = 0;
    double graph_matrix_cost[25][25];
    int vizitat[25];
    tail bfs_paths[25];

    printf("enter starting town: \n");
    scanf("%d", &turist);
    printf("enter lenght: \n");
    scanf("%d", &l);

    read_cost_matrix(graph_matrix_cost, n);
    print_cost_matrix(graph_matrix_cost, n);
    printf("\n");
    
    bfs_threeLength_path(graph_matrix_cost, bfs_paths, vizitat, turist, n);

    for(i = 1; i <= n; i++)
    {
       // printf("aaaaa\n");
        printf("oras: %d, lungime drum: %d, cost drum: %.lf\n", bfs_paths[i].town, bfs_paths[i].path_length, bfs_paths[i].path_cost);
    }

    for(i = 1; i <= n; i++)
    {
        if (bfs_paths[i].path_length == l)
        {
            printf("orasul %d se afla la distanta de %d orase de %d\n",  bfs_paths[i].town, l, turist);
            ok = 1;
        }
    }

    if(ok == 0)
    {
        printf("nu exista\n");
    }

    return 0;
}
