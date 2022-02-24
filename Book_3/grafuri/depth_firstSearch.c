#include <stdio.h>

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

void depth_search_list(int t[2][50], int start[50], int n, int nod, int vizitat[50])
{
    int next, i;

    printf("%d \n", nod);
    
    next = start[nod];
   // printf("start[nod]: %d\n", start[nod]);
   // printf("next inainte while: %d\n", next);
    vizitat[nod] = 1;
   // printf("vizitat[nod] inainte while: %d\n", vizitat[nod]);

    while(next)
    {
       // printf("next while: %d\n", next);
        if(vizitat[t[0][next]] == 0)
        {
            //printf("if vizitat: %d\n", vizitat[t[0][next]]);
            depth_search_list(t, start, n, t[0][next], vizitat);
        }
        next = t[1][next];
    }
}

int main()
{
    int t[2][50];
    int n = 7;
    int i;
    int start[50], vizitat[50];

    for(i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    read_graph_static(t, n, start);
    depth_search_list(t, start, n, 6, vizitat);

    /*print_graph_static(t, n, start); */

    return 0;
}