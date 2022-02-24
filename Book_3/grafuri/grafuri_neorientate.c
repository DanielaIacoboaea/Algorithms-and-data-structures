#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* next;

} Nod;

typedef struct edge{
    int x, y;
} edge;

void read_graph_matrix(int matrix[50][50], int n)
{
    int i, j, first_node, second_node;
    FILE *f;
    f = fopen("noduri.txt", "r");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    while(!feof(f))
    {
        fscanf(f, "%d %d", &first_node, &second_node);
        matrix[first_node][second_node] = 1;
        matrix[second_node][first_node] = 1;
    }
    fclose(f);
}

void print_graph_matrix(int matrix[50][50], int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

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

Nod* find_end(Nod* vf)
{
    while(vf->next)
    {
        vf = vf->next;
    }
    return vf;
}

void read_graph_list(Nod* arr[15], int n)
{
    int x, y;
    FILE* f;
    f = fopen("noduri.txt", "r");
    Nod* add_new;
    Nod* end;

    while(!feof(f))
    {
        fscanf(f, "%d %d", &x, &y);
        if(arr[x] == NULL)
        {
            add_new = (Nod*) malloc(sizeof(Nod));
            add_new->info = y;
            add_new->next = NULL;
            arr[x] = add_new;
        }else{
            end = find_end(arr[x]);
            add_new = (Nod*) malloc(sizeof(Nod));
            add_new->info = y;
            add_new->next = NULL;
            end->next = add_new;
        }

        if(arr[y] == NULL)
        {
            add_new = (Nod*) malloc(sizeof(Nod));
            add_new->info = x;
            add_new->next = NULL;
            arr[y] = add_new;
        }else{
            end = find_end(arr[y]);
            add_new = (Nod*) malloc(sizeof(Nod));
            add_new->info = x;
            add_new->next = NULL;
            end->next = add_new;
        }
    }
    fclose(f);
}

void print_graph_list(Nod* arr[15], int n)
{
    Nod* vf_temp;
    int i;
    for(i = 1; i <= n; i++)
    {
        printf("Nodurile adiacente cu %d: \n", i);
        vf_temp = arr[i];
        if(vf_temp == NULL)
        {
            printf("nu are noduri adiacente\n");
        }
        while(vf_temp)
        {
            printf("%d ", vf_temp->info);
            vf_temp = vf_temp->next;
        }
        printf("\n");
    }
}

int read_graph_edge(edge v[50])
{
    FILE* f;
    f = fopen("noduri.txt", "r");

    int i, node_one, node_two;

    i = 0;
    while(!feof(f))
    {
        i++;
        fscanf(f, "%d %d", &node_one, &node_two);
        v[i].x = node_one;
        v[i].y = node_two;
    }
    return i;
}

void print_graph_edge(edge v[50], int m)
{
    int i;
    printf("muchiile grafului sunt:\n");

    for(i = 1; i <= m; i++)
    {
        printf("%d %d\n", v[i].x, v[i].y);
    }
}

int main()
{
    int a[50][50], t[2][50];
    int n = 6;
    int i, muchii;
    int start[50];
    Nod* arr[15];

    for (i = 1; i <= n; i++)
    {
        arr[i] = NULL;
    }

    edge v[50];

    /*
    read_graph_matrix(a, n);
    print_graph_matrix(a, n);
    */

    /*
    read_graph_static(t, n, start);
    print_graph_static(t, n, start);
    */

    /*
    read_graph_list(arr, n);
    print_graph_list(arr, n);
    */

    muchii = read_graph_edge(v);
    print_graph_edge(v, muchii);

    
    return 0;
}