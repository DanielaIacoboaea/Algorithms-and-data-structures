/* se da un graf si o succesiune de noduri ale lui
program care decide daca succesiunea data este sau nu un lant
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* next;

} Nod;

Nod* find_end(Nod* vf)
{
    while(vf->next)
    {
        vf = vf->next;
    }
    return vf;
}

void read_graph_list(Nod* arr[15], int n)
{
    int x, y;
    FILE* f;
    f = fopen("nod.txt", "r");
    Nod* add_new;
    Nod* end;

    while(!feof(f))
    {
        fscanf(f, "%d %d", &x, &y);
        if(arr[x] == NULL)
        {
            add_new = (Nod*) malloc(sizeof(Nod));
            add_new->info = y;
            add_new->next = NULL;
            arr[x] = add_new;
        }else{
            end = find_end(arr[x]);
            add_new = (Nod*) malloc(sizeof(Nod));
            add_new->info = y;
            add_new->next = NULL;
            end->next = add_new;
        }

        if(arr[y] == NULL)
        {
            add_new = (Nod*) malloc(sizeof(Nod));
            add_new->info = x;
            add_new->next = NULL;
            arr[y] = add_new;
        }else{
            end = find_end(arr[y]);
            add_new = (Nod*) malloc(sizeof(Nod));
            add_new->info = x;
            add_new->next = NULL;
            end->next = add_new;
        }
    }
    fclose(f);
}

void print_graph_list(Nod* arr[15], int n)
{
    Nod* vf_temp;
    int i;
    for(i = 1; i <= n; i++)
    {
        printf("Nodurile adiacente cu %d: \n", i);
        vf_temp = arr[i];
        if(vf_temp->info == 0)
        {
            printf("nu are noduri adiacente\n");
        }else{

            while(vf_temp)
            {
                printf("%d ", vf_temp->info);
                vf_temp = vf_temp->next;
            }
            printf("\n");
        }
    }
}

int read_succesiune(int succesiune[15])
{
    FILE* g;
    g = fopen("succesiune.txt", "r");

    int count = 0, nod;

    while(!feof(g))
    {
        count++;
        fscanf(g, "%d", &nod);
        succesiune[count] = nod;
    }
    fclose(g);
    return count;
}

int search_node(Nod* vf, int x)
{
    while(vf)
    {
       // printf("vf info: %d\n", vf->info);
        if (vf->info == x)
        {
           // printf("if vf->info == x: %d si %d\n", vf->info, x);
            return 1;
        }
        vf = vf->next;
    }
    return 0;
}

int bf_searchSuccesiune(Nod* arr[15], int succesiune[15], int m)
{
    int j = 1;
    Nod* vf_temp;
   // printf("primul succesiune de j: %d\n", succesiune[j]);
    vf_temp = arr[succesiune[j]];

    while(j < m)
    {
        //printf("j: %d\n", j);
        if(search_node(vf_temp, succesiune[j+1]))
        {
           // printf("ififififififif\n");
            vf_temp = arr[succesiune[j+1]];
          //  printf("succesiune[j+1]: %d\n", succesiune[j+1]);
            j++;
        }else{
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n = 7, m;
    int i;
    Nod* arr[15];
    int succesiune[15];

    for (i = 1; i <= n; i++)
    {
        arr[i] = NULL;
    }

    read_graph_list(arr, n);
    print_graph_list(arr, n);

    m = read_succesiune(succesiune);
    printf("succesiune noduri de gasit:\n");
    for(i = 1; i <= m; i++)
    {
        printf("%d ", succesiune[i]);
    }
    printf("\n");

    if(bf_searchSuccesiune(arr, succesiune, m))
    {
        printf("lantul de la %d la %d exista\n", succesiune[1], succesiune[m]);
    }else{
        printf("lantul de la %d la %d nu exista\n", succesiune[1], succesiune[m]);
    }
    return 0;
}