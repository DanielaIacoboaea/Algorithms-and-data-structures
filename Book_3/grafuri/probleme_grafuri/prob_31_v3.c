/* matrice de adiacenta
sa se afiseze toate ciclurile de lungime k
un ciclu se va afisa o singura data
*/

#include <stdio.h>
#include <string.h>

typedef struct parcurs{
    int nod_crt;
    int graf_crt[50][50];
    int drum_length;

} parcurs;

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

void breadth_first_matrix(int matrix[50][50], int n, int nod, int dim)
{
    parcurs coada[50];
    int vizitat[50], drum_arr[50];
    int i, start_coada, end_coada, j, nod_intermediar, count = 0, drum = 1;

    start_coada = 1;
    end_coada = 1;

    for (i = 1; i <= n; i++)
    {
        vizitat[i] = 0;
    }

    coada[start_coada].nod_crt = nod;
    vizitat[nod] = 1;
    drum_arr[count] = nod;
    coada[start_coada].drum_length = drum;
    memcpy(coada[start_coada].graf_crt, matrix, sizeof (coada[start_coada].graf_crt));
  
    while (start_coada <= end_coada)
    {
        i = 1;
        nod_intermediar = coada[start_coada].nod_crt;
        while (i <= n)
        {
            if (coada[start_coada].graf_crt[nod_intermediar][i] == 1)
            {
                if(vizitat[i] == 0)
                {
                    end_coada++;
                    coada[end_coada].nod_crt = i;
                    vizitat[i] = 1;
                    coada[end_coada].drum_length = drum;
                    memcpy(coada[end_coada].graf_crt, coada[start_coada].graf_crt, sizeof (coada[end_coada].graf_crt));
                    coada[end_coada].graf_crt[i][nod_intermediar] = 0;
                }
                /*else
                {
                    if (i == nod && drum == dim)
                    {
                        printf("i din else if : %d si nod din else if %d\n", i, nod);
                        printf("ciclu gasit pentru nodul %d\n", nod);
                        for (int l = 0; l < drum; l++)
                        {
                            printf("%d ", drum_arr[l]);
                        }
                        printf("%d \n", nod);
                        coada[end_coada].graf_crt[i][nod_intermediar] = 0;
                    }
                }
                */
            }
            i++;
        }
        start_coada++;
        count++;
        drum_arr[count] = coada[start_coada].nod_crt;
        drum++;
        coada[start_coada].drum_length = drum;
        
        if (drum == dim && matrix[coada[drum-1].nod_crt][nod] == 1)
        {
            int exista = 1;
            for (int g = 0; g <= drum; g++)
            {
                if(matrix[drum_arr[g]][drum_arr[g+1]] == 0)
                {
                    exista = 0;
                    break;
                }
            }
            if (exista)
            {
                printf("ciclu gasit pentru nodul %d\n", nod);
                for (int l = 0; l < drum; l++)
                {
                    printf("%d ", drum_arr[l]);
                }
                printf("%d \n", nod);
            }
        }
    }
}

int main()
{
    int a[50][50];
    int n = 6;
    int i, k;

    printf("enter length: \n");
    scanf("%d", &k);
    
    read_graph_matrix(a, n);
    print_graph_matrix(a, n);
    printf("\n");
    
    for (i = 1; i <= n; i++)
    {
        breadth_first_matrix(a, n, i, k);
        printf("\n");
    }
    
    return 0;
}