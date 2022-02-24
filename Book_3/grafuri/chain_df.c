/*fiind dat un graf si doua noduri ale sale (a, b) sa se verifice daca intre cele 
doua noduri exista un lant sau nu, si sa se afiseze lantul*/

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

void reverse(int nod, int link[50])
{
   // printf("aaaaaaaaa\n");
    if (nod != 0)
    {
        reverse(link[nod], link);
        printf("%d \n", nod);
    }
}

void check_ifChain(int nod, int matrix[50][50], int link[50], int n, int visited[50])
{
   // printf("bbbbbbbbb\n");
    int k, i;
    
    visited[nod] = 1;
   // printf("visited[nod]: %d\n", visited[nod]);

    for(k = 1; k <= n; k++)
    {
       // printf("k: %d\n", k);
        if(matrix[nod][k] == 1 && visited[k] == 0)
        {
            link[k] = nod;
           // printf("link[k]: %d\n", link[k]);
            check_ifChain(k, matrix, link, n, visited);
        }
    }
}

int main()
{
    int matrix[50][50];
    int n = 6, a, b, i;
    int link[50];
    int visited[50];

    printf("enter a,b:\n");
    scanf("%d,%d", &a, &b);

    link[a] = 0;

    for(i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    read_graph_matrix(matrix, n);
    print_graph_matrix(matrix, n);
    printf("\n\n");

    check_ifChain(a, matrix, link, n, visited);

   // printf("ccccccc\n");

    if (link[b] != 0)
    {
        reverse(b, link);
    }else
    {
        printf("nu exista\n");
    }
    
    return 0;
}