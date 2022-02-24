/* graf orientat
sa se verifice daca este bipartit, in caz afirmativ, 
sa se afiseze cele 2 multimi in care pot fi impartite varfurile
*/

#include <stdio.h>

void read_digraph_matrix(int matrix[25][25], int nNodes)
{
    FILE* f;
    f = fopen("nod_bipartit.txt", "r");

    int v1, v2, i, j;

    for (i = 1; i <= nNodes; i++)
    {
        for (j = 1; j <= nNodes; j++)
        {
            matrix[i][j] = 0;
        }
    }

    while (!feof(f))
    {
        fscanf(f,"%d %d", &v1, &v2);
        matrix[v1][v2] = 1;
    }
    fclose(f);
}

void print_digraph_matrix(int matrix[25][25], int nNodes)
{
    int i, j;

    for(i = 1; i <= nNodes; i++)
    {
        for(j = 1; j <= nNodes; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int check_links(int matrix[25][25], int multime[25], int n, int nod, int nr_count)
{
    for (int i = 1; i <= n; i++)
    {
        if(multime[i] == nr_count && (matrix[nod][i] == 1 || matrix[i][nod] == 1))
        {
            return 0;
        }
    }
    return 1;
}

int chech_graph_bipartit(int matrix[25][25], int vizitat[25], int multime[25], int n, int nod, int tail[25])
{
    int ok = 1;
    int i, count_1 = 1;
    int st_coada = 1, end_coada = 1;

    vizitat[nod] = 1;
    tail[st_coada] = nod;
    multime[nod] = count_1;

    while(st_coada <= end_coada)
    {
       // printf("ok: %d\n", ok);
        //printf("st coada: %d\n", st_coada);
        i = 1;
        while (i <= n)
        {
           // printf("i: %d\n", i);
            if((matrix[tail[st_coada]][i] == 1 && vizitat[i] == 0) || (matrix[i][tail[st_coada]] == 1 && vizitat[i] == 0))
            {
                end_coada++;
                tail[end_coada] = i;
                vizitat[i] = 1;
               // printf("multime[%d]: %d\n", i, multime[i]);
                //printf("multime[%d]: %d\n", i, multime[i]);
                if(multime[i] == 0)
                {
                    if (check_links(matrix, multime, n, i, count_1 * (-1)))
                    {
                        multime[i] = count_1 * (-1);
                        // printf("multime[%d] din if: %d\n", i, multime[i]);
                    }else{
                        return 0;
                    }
                }
            }
            i++;
        }
        st_coada++;
        count_1 = multime[tail[st_coada]];
    }
    return 1;
}

int main()
{
    int n = 5, i, check;
    int graph_matrix[25][25];
    int multime[25], vizitat[25], tail[25];

    for(i = 1; i <= n; i++)
    {
        multime[i] = 0;
        vizitat[i] = 0;
    }

    read_digraph_matrix(graph_matrix, n);
    print_digraph_matrix(graph_matrix, n);

    check = chech_graph_bipartit(graph_matrix, vizitat, multime, n, 2, tail);

    if(check)
    {
        printf("graful este bipartit\n");
        printf("multimea 1 este formata din varfurile:\n");
        for(i = 1; i <= n; i++)
        {
            if(multime[i] == 1)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
        printf("multimea 2 este formata din varfurile:\n");
        for(i = 1; i <= n; i++)
        {
            if(multime[i] == -1)
            {
                printf("%d ", i);
            }
        }
        printf("\n");

    }else{
        printf("graful nu este bipartit\n");
    }

    return 0;
}
