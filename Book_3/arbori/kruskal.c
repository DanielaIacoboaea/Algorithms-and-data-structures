#include <stdio.h>

int read_edges_cost(int matrix[3][50])
{
    FILE* f;
    f = fopen("kruskal_cost.txt", "r");
    int v1, v2, cost, k = 0;

    while (!feof(f))
    {
        fscanf(f, "%d %d %d", &v1, &v2, &cost);
        matrix[0][k] = v1;
        matrix[1][k] = v2;
        matrix[2][k] = cost;
        k++;
    }

    fclose(f);

    return k;
}

void sort_edgesCosts(int matrix[3][50], int nEdges)
{
    int aux, i, j;

    for (i = 0; i < nEdges - 1; i++)
    {
        for (j = i + 1; j < nEdges; j++)
        {
            if (matrix[2][i] > matrix[2][j])
            {
                aux = matrix[2][i];
                matrix[2][i] = matrix[2][j];
                matrix[2][j] = aux;

                aux = matrix[1][i];
                matrix[1][i] = matrix[1][j];
                matrix[1][j] = aux;

                aux = matrix[0][i];
                matrix[0][i] = matrix[0][j];
                matrix[0][j] = aux;
            }
        }
    }
}

void print_matrix(int matrix[3][50], int nEdges)
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < nEdges; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int find_root(int nod, int track[50])
{
    while (track[nod])
    {
        printf("root\n");
        nod = track[nod];
    }
    return nod;
}

int main()
{
    int n = 5, i, nEdges, j, k = 1, muchii;
    int matrix[3][50];
    int track[50], height[50];
    printf("aaaaaa\n");
    
    for (i = 1; i <= n; i++)
    {
        track[i] = 0;
        height[i] = 0;
    }
    

    nEdges = read_edges_cost(matrix);
    printf("bbbbbbb\n");

    printf("inainte de sortare\n");
    print_matrix(matrix, nEdges);

    sort_edgesCosts(matrix, nEdges);
    printf("ccccccccc\n");

    printf("\n dupa sortare\n");
    print_matrix(matrix, nEdges);
    printf("dddddddd\n");

    muchii = 0;
    
    do
    {
        printf("k: %d\n", k);
        while (find_root(matrix[0][k], track) == find_root(matrix[1][k], track))
        {
            k++;
        }

        muchii++;
        printf("muchii: %d \n", muchii);

        printf("muchie: %d - %d, cost %d\n", matrix[0][k], matrix[1][k], matrix[1][k]);
        if (height[matrix[0][k]] == height[matrix[1][k]])
        {
            track[matrix[0][k]] = matrix[1][k];
            height[matrix[1][k]]++;
        }else
        {
            if (height[matrix[0][k]] < height[matrix[1][k]])
            {
                track[matrix[0][k]] = matrix[1][k];
            }else{
                track[matrix[1][k]] = matrix[0][k];
            }
        }
        k++;
    } while (muchii < n-1);
    

    return 0;
}