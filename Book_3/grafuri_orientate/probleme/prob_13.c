/*se da un graf prin lista muchiilor
programul va decide daca graful este neorientat*/

#include <stdio.h>
#include <stdbool.h>

typedef struct arc{
    int x;
    int y;
} arc;

int read_digraph_struct(arc arr[25])
{
    FILE* f;
    f = fopen("muchii.txt", "r");

    int i, v1, v2;
    i = 0;
    while (!feof(f))
    {
        i++;
        fscanf(f, "%d %d", &v1, &v2);
        arr[i].x = v1;
        arr[i].y = v2;
    }

    fclose(f);

    return i;
}

void print_digraph_struct(arc arr[25], int arcs)
{
    int i;
    for (i = 1; i <= arcs; i++)
    {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
}

int checkIf_twoSide_path(arc arr[25], int nNodes, int second, int first)
{
    int j;

    for (j = 1; j <= nNodes; j++)
    {
       // printf("j: %d\n", j);
        if(arr[j].x == second && arr[j].y == first)
        {
           // printf("arr[j].x: %d , arr[j].y: %d\n", arr[j].x, arr[j].y);
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n = 7, i, first_node, second_node;
    arc arr[25];
    int nArcs;
    int verificat[25];
    bool neorientat = 1;

    nArcs = read_digraph_struct(arr);
    print_digraph_struct(arr, nArcs);
    printf("\n");

    for (i = 1; i <= n; i++)
    {
        verificat[i] = 0;
    }

    for(i = 1; i <=nArcs; i++)
    {
        first_node = arr[i].x;
        second_node = arr[i].y;
        if (checkIf_twoSide_path(arr, nArcs, second_node, first_node))
        {
            verificat[first_node] = 1;
           // printf("if verificat[%d]: %d\n", first_node, verificat[first_node]);
        }else{
            verificat[first_node] = -1;
           // printf("else verificat[%d]: %d\n", first_node, verificat[first_node]);
        }
    }
    
    for(i = 1; i <= n; i++)
    {
       // printf("verificat[%d]: %d\n", i, verificat[i]);
        if(verificat[i] < 0)
        {
            printf("graful este orientat\n");
            neorientat = 0;
        }
    }

    if(neorientat)
    {
        printf("graful este neorientat\n");
    }

    return 0;
}
