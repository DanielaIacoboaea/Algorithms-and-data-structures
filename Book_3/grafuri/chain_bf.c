#include <stdio.h>

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

void print_link(int nod, int link[50])
{
    if(nod != 0)
    {
        print_link(link[nod], link);
        printf("%d \n", nod);
    }

}

void bf_searchLink(int a[50][50], int vizitat[50], int coada[50], int link[50], int n, int nod)
{
    int i, start_coada, end_coada;

    start_coada = 1;
    end_coada = 1;

    coada[start_coada] = nod;
    vizitat[nod] = 1;

    while(start_coada <= end_coada)
    {
        i = 1;
        while (i <= n)
        {
            if (a[coada[start_coada]][i] == 1 && vizitat[i] == 0)
            {
                end_coada++;
                coada[end_coada] = i;
                vizitat[i] = 1;
                link[i] = coada[start_coada];
            }
            i++;
        }
        start_coada++;
    }
}

int main()
{
    int matrix[50][50];
    int n = 6;
    int i, a, b;
    int vizitat[50], link[50], coada[50];

    printf("a,b:\n");
    scanf("%d,%d", &a, &b);

    for(i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }
    
    read_graph_matrix(matrix, n);
    print_graph_matrix(matrix, n);
    printf("\n\n");

    bf_searchLink(matrix, vizitat, coada, link, n, a);

    if(link[b] != 0)
    {
        print_link(b, link);
    }else{
        printf("nu exista\n");
    }
    
    return 0;
}