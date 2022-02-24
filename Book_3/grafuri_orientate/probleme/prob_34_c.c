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
    int n = 6, i, j, min, turist, poz, close_to;
    double graph_matrix_cost[25][25];
    int selectat[25], track[25];
    double road_cost[25];
    double infi = 30000;

    printf("enter starting town: \n");
    scanf("%d", &turist);

    read_cost_matrix(graph_matrix_cost, n);
    print_cost_matrix(graph_matrix_cost, n);
    printf("\n");

    for (i = 1; i <=n; i++)
    {
        if (i == turist)
        {
            selectat[i] = 1;
        }else{
            selectat[i] = 0;
        }

        road_cost[i] = graph_matrix_cost[turist][i];
        if (i == turist || graph_matrix_cost[turist][i] == infi)
        {
            track[i] = 0;
        }else{
            track[i] = turist;
        }
    }

    for (i = 1; i <= n-1; i++)
    {
        min = infi;
        for (j = 1; j <= n; j++)
        {
            if (selectat[j] == 0)
            {
                if (road_cost[j] < min)
                {
                    min = road_cost[j];
                    poz = j;
                }
            }
        }
        selectat[poz] = 1;
        for (j = 1; j <= n; j++)
        {
            if (selectat[j] == 0)
            {
                if (road_cost[j] > road_cost[poz] + graph_matrix_cost[poz][j])
                {
                    road_cost[j] = road_cost[poz] + graph_matrix_cost[poz][j];
                    track[j] = poz;
                }
            }
        }
    }

    printf("drumul cu distanta minima intre %d si celelalte orase:\n", turist);

    for (i = 1; i <= n; i++)
    {
        printf(" %.1lf ", road_cost[i]);
    }
    printf("\n");

    for (i = 1; i <= n; i++)
    {
        if (i != turist)
        {
            if (track[i])
            {
                printf("distanta de la %d la %d este: %.1lf\n", turist, i, road_cost[i]);
                printf("%d ", turist);
                drum(i, track);
                printf("\n");
            }else{
                printf("nu exista drum de la %d la %d\n", turist, i);
            }
        }
    }

    min = infi;
    for (i = 1; i <= n; i++)
    {
        if (i != turist)
        {
            if (road_cost[i] < min)
            {
                min = road_cost[i];
                close_to = i;
            }
        }
    }
    printf("orasul cel mai apropiat de %d este %d\n", turist, close_to);
    int numara = 0;

    for (i = 1; i <=n; i++)
    {
        if (i == turist)
        {
            selectat[i] = 1;
        }else{
            selectat[i] = 0;
        }
    }

    for (i = 1; i <= n-1; i++)
    {
        //printf("i: %d\n", i);
        min = infi;
        for (j = 1; j <= n; j++)
        {
            //printf("j: %d\n", j);
            if (selectat[j] == 0)
            {
                //selectat[j] = 1;
                if (road_cost[j] < min)
                {
                    min = road_cost[j];
                }
            }
        }
        selectat[i] = 1;
        numara++;
        if (numara == 3)
        {
            printf("al 4-lea oras de la %d este %d\n", turist, i);
        }
    }
   
    return 0;
}
