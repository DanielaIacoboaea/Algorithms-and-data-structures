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

int count_lenght(int vizitat[50], int n)
{
    int j = 1, count = 0;

    while (j <= n)
    {
        if(vizitat[j] == 1)
        {
            count++;
        }
        j++;
    }

   return count-1;
}

int df_checkIfCiclu(int nod, int matrix[50][50], int n, int vizitat[50], int lenght)
{
    int i, j, exista = 0, count = 0;
    printf("nod: %d\n", nod);
    vizitat[nod] = 1;
    printf("vizitat[%d]: %d\n", nod, vizitat[nod]);
   // printf("nod: %d\n", nod);
    //printf("exista: %d\n", exista);
    for(i = 1; i<= n; i++)
    {
        printf("i for: %d\n", i);
        if(matrix[nod][i] == 1)
        {
            printf("matrix[nod][i]: %d\n", matrix[nod][i]);
            matrix[i][nod] == 0;
            if (vizitat[i] == 0)
            {
                printf("vizitat[%d]: %d\n", i, vizitat[i]);
                df_checkIfCiclu(i, matrix, n, vizitat, lenght);
            }else{
                for (j = 1; j <= n; j++)
                {
                    if (vizitat[j] == 1)
                    {
                        count += 1;
                    }
                }
                printf("count: %d, lenght: %d\n", count, lenght);
                if(count == lenght)
                {
                    printf("ciclu de lungime %d pentru nodul %d:\n", lenght, nod);
                    for (j = 1; j <= n; j++)
                    {
                        if (vizitat[j] == 1)
                        {
                            printf("%d ", j);
                        }
                    }
                    printf("\n");
                    exista = 1;
                }else{
                    exista = 0;
                }
                printf("exista din else: %d\n", exista);
            }
        }
    }

    return exista;
}

void reset_vizitat(int vizitat[50], int n)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }
}

int main()
{
    int matrix[50][50];
    int n = 7;
    int i, k, gasit, dim;
    int vizitat[50];

    for(i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    printf("enter k: \n");
    scanf("%d", &k);
    
    read_graph_matrix(matrix, n);
    print_graph_matrix(matrix, n);
    printf("\n\n");

  /*  int gasit = df_checkIfCiclu(1, matrix, n, vizitat);
    if(gasit)
    {
        printf("exista\n");
    }else{
        printf("nu exista\n");
    }
  */

    for(i = 1; i <= n; i++)
    {
       // printf("forforforfor\n");
        gasit = df_checkIfCiclu(i, matrix, n, vizitat, k);
        dim = count_lenght(vizitat, n);

        printf("gasit: %d si dim: %d pentru nodul %d\n", gasit, dim, i);

        if(gasit == 1)
        {
           // printf("exista: %d\n", df_checkIfCiclu(i, matrix, n, vizitat));
           // printf("count_lenght: %d\n", count_lenght(vizitat, n));
           // printf("ciclu gasit pentru nodul %d\n", i);
        }
        reset_vizitat(vizitat, n);
    }

    return 0;
}