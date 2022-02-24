/* matrice de adiacenta
sa se afiseze toate ciclurile de lungime k
un ciclu se va afisa o singura data
*/

#include <stdio.h>

void read_graph_matrix(int matrix[50][50], int n)
{
    int i, j, first_node, second_node;
    FILE *f;
    f = fopen("nodes.txt", "r");
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

int nextLayer_find_nodeHead(int matrix[50][50], int n, int nod_curent, int nod_head)
{
    int j;
    for (j = 1; j <= n; j++)
    {
        if ((matrix[nod_curent][j] == 1) && (j == nod_head))
        {
            printf("(matrix[nod_curent][j]: %d j: %d nod_head: %d\n", matrix[nod_curent][j], j, nod_head);
            return 1;
        }
    }
    return 0;
}


void breadth_first_matrix(int matrix[50][50], int n, int nod, int lenght, int ciclu[15])
{
    int coada[50], vizitat[50];
    int i, start_coada, end_coada, j, count = 1;

    start_coada = 1;
    end_coada = 1;
    ciclu[count] = nod;

    for (i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    coada[start_coada] = nod;
    vizitat[nod] = 1;
    
    while (start_coada <= end_coada)
    {
        i = 1;
        while (i <= n)
        {
            if (matrix[coada[start_coada]][i] == 1 && vizitat[i] == 0)
            {
                matrix[i][coada[start_coada]] = 0;
                end_coada++;
                coada[end_coada] = i;
                vizitat[i] = 1;
            }

            i++;
        }
        printf("%d \n", coada[start_coada]);
        start_coada++;
        printf("coada[start_coada] dupa incremen: %d\n", coada[start_coada]);

        if(nextLayer_find_nodeHead(matrix, n, coada[start_coada], nod))
        {
            printf("if start_coada: %d, length: %d, coada[start_coada]: %d, nod: %d\n", start_coada, coada[start_coada], lenght, nod);
            printf("ciclu de lungime %d gasit pentru nodul %d\n", start_coada, nod);
            break;
        }
    }
}

int main()
{
    int a[50][50];
    int n = 7;
    int i, k;
    
    printf("enter k:\n");
    scanf("%d", &k);
    
    read_graph_matrix(a, n);
    print_graph_matrix(a, n);
    printf("\n");
    
    for (i = 1; i <= n; i++)
    {
        printf("parcurgere din nodul %d\n", i);
        breadth_first_matrix(a, n, i, k);
        printf("\n");
    }
    return 0;
}