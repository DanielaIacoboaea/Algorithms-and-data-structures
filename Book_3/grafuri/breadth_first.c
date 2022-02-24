#include <stdio.h>
#include <stdlib.h>

void read_graph_static(int t[2][50], int n, int start[50])
{
    int first_node, second_node, i;
    int k = 0;
    FILE *f;
    f = fopen("noduri.txt", "r");

    for(i = 1; i <= n; i++)
    {
        start[i] = 0;
    }

    while(!feof(f))
    {
        fscanf(f, "%d %d", &first_node, &second_node);
        k++;
        t[0][k] = second_node;
        t[1][k] = start[first_node];
        start[first_node] = k;

        k++;
        t[0][k] = first_node;
        t[1][k] = start[second_node];
        start[second_node] = k;
    }

    fclose(f);
}

void print_graph_static(int t[2][50], int n, int start[50])
{
    int next, i;
    for (i = 1; i <= n; i++)
    {
        printf("noduri adiacente cu %d: \n", i);
        next = start[i];
        while(next)
        {
            printf("%d ", t[0][next]);
            next = t[1][next];
        }
        printf("\n");
    }
}

void breadth_first_search(int t[2][50], int n, int start[50], int nod)
{
    int start_coada, end_coada, i, p;
    int coada[50], vizitat[50];
    
    start_coada = 1;
    end_coada = 1;

    for (i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    coada[start_coada] = nod;
    vizitat[nod] = 1;

    while(start_coada <= end_coada)
    {
        p = start[coada[start_coada]];
        while(p)
        {
            if (vizitat[t[0][p]] == 0)
            {
                end_coada++;
                coada[end_coada] = t[0][p];
                vizitat[t[0][p]] = 1;
            }
            p = t[1][p];
        }
        printf("%d \n", coada[start_coada]);
        start_coada++;
    }
}

int main()
{
    int t[2][50];
    int n = 7;
    int start[50];

    read_graph_static(t, n, start);
    breadth_first_search(t, n, start, 6);
    /*
    print_graph_static(t, n, start);
    */

}