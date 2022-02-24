/* cautare si afisare lant*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* next;
} Nod;

Nod* find_end(Nod* curent)
{
    while(curent->next)
    {
        curent = curent->next;
    }
    return curent;
}

void read_digraph_list(Nod* arr[25], int nNodes)
{
    FILE* f;
    f = fopen("grad.txt", "r");

    int v1, v2;
    Nod* end;
    Nod* add_new;

    while(!feof(f))
    {
        fscanf(f, "%d %d", &v1, &v2);

        if (arr[v1] == NULL)
        {
            add_new = (Nod*) malloc(sizeof(Nod));
            add_new->info = v2;
            add_new->next = NULL;
            arr[v1] = add_new;
        }else{
            end = find_end(arr[v1]);
            add_new = (Nod*) malloc(sizeof(Nod));
            add_new->info = v2;
            add_new->next = NULL;
            end->next = add_new;
        }
    }
    fclose(f);
}

void print_digraph_list(Nod* arr[25], int nNodes)
{
    int i;
    Nod* curent;

    for (i = 1; i <= nNodes; i++)
    {
        curent = arr[i];
        if (curent == NULL)
        {
            printf("nodul %d nu are noduri adiacente spre exterior\n", i);
        }else{
            printf("nodurile adiacente cu %d spre exterior sunt: \n", i);
            while (curent)
            {
                printf("%d -> %d; ", i, curent->info);
                curent = curent->next;
            }
        }
        printf("\n");
    }
}

void print_path(int track[25], int end_node)
{
  //  printf("bbbbbbbbb\n");
    if (track[end_node] != 0)
    {
        print_path(track, track[end_node]);
        printf("%d ", track[end_node]);
    }
}

void dfs_paths(Nod* arr_nodes[25], int nNodes, int start_node, int vizitat[25], int track[25])
{
   // printf("aaaaaaaa\n");
    int k;
    Nod* temp;
    
    vizitat[start_node] = 1;

    temp = arr_nodes[start_node];
    while(temp)
    {
        if (vizitat[temp->info] == 0)
        {
            track[temp->info] = start_node;
            dfs_paths(arr_nodes, nNodes, temp->info, vizitat, track);
        }
        temp = temp->next;
    }
}

int main()
{
    int n = 5, i, x, y;
    Nod* arr_nodes[25];
    int vizitat[25], track[25];

    for (i = 1; i <= n; i++)
    {
        arr_nodes[i] = NULL;
    }

    printf("enter x,y: \n");
    scanf("%d,%d", &x, &y);

    for (i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    track[x] = 0;

    read_digraph_list(arr_nodes, n);
    print_digraph_list(arr_nodes, n);
    printf("\n");
    
    dfs_paths(arr_nodes, n, x, vizitat, track);

    if (track[y] == 0)
    {
        printf("nu exista lant de la %d la %d\n", x, y);
    }else{

        printf("lantul de la %d la %d trece prin nodurile: \n", x, y);
        print_path(track, y);
        printf("%d ", y);
        printf("\n");
    }
    return 0;
}
