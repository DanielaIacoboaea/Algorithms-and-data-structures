#include <stdio.h>

void read_graph_matrix(int matrix[50][50], int n)
{
    int i, j, first_node, second_node;
    FILE *f;
    f = fopen("mem_arbore.txt", "r");
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

void bfs_height_graph(int matrix[50][50], int node, int nNodes, int height[50])
{
    int st_tail = 1, end_tail = 1, k;
    int tail[50], vizitat[50];

    for(k = 1; k <= nNodes; k++)
    {
        vizitat[k] = 0;
    }

    vizitat[node] = 1;
    tail[st_tail] = node;
    height[st_tail] = 0;

    while (st_tail <= end_tail)
    {
        k = 1;

        while (k <= nNodes)
        {
            if(matrix[tail[st_tail]][k] == 1 && vizitat[k] == 0)
            {
                vizitat[k] = 1;
                end_tail++;
                tail[end_tail] = k;
                height[tail[end_tail]] = height[tail[st_tail]] + 1;
                printf("height[tail[%d]]: %d\n", end_tail, height[tail[end_tail]]);
            }
            k++;
        }
        st_tail++;
    }
}

int main()
{
    int a[50][50];
    int n = 5, i, max_height = 0;
    int height[50];

    read_graph_matrix(a, n);
    print_graph_matrix(a, n);
    printf("\n");
    
    bfs_height_graph(a, 3, n, height);
    
    for (i = 1; i <= n; i++)
    {
        printf("nodul %d se afla la nivelul %d\n", i, height[i]);
        if (height[i] > max_height)
        {
            max_height = height[i];
        }
    }
    
    printf("inaltimea arborelui este: %d\n", max_height);

    return 0;
}