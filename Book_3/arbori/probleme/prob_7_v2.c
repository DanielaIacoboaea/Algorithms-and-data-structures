#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int nr;
    struct Nod* left;
    struct Nod* right;
    struct Nod* middle;
} Nod;

void read_binaryTree(int left_array[25], int rigth_array[25], int middle_array[25], int n)
{
    FILE* f;
    f = fopen("descendente.txt", "r");

    int v_l, i, v_r, j, v_m, k;

    while (!feof(f))
    {
        for (i = 1; i <= n; i++)
        {
            fscanf(f, "%d", &v_l);
            left_array[i] = v_l;
        }
        for (j = 1; j <= n; j++)
        {
            fscanf(f,"%d", &v_r);
            rigth_array[j] = v_r;
        }
        for (k = 1; k <= n; k++)
        {
            fscanf(f,"%d", &v_m);
            middle_array[k] = v_m;
        }
    }
    fclose(f);
}

void print_array(int array[25], int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


Nod* create_tree(int nod, int left_array[25], int rigth_array[25], int middle_array[25])
{
    if (nod)
    {
        Nod* temp = (Nod*) malloc (sizeof(Nod));
        temp->nr = nod;
        temp->left = create_tree(left_array[nod], left_array, rigth_array, middle_array);
        temp->right = create_tree(rigth_array[nod], left_array, rigth_array, middle_array);
        temp->middle = create_tree(middle_array[nod], left_array, rigth_array, middle_array);
        return temp;
    }else{
        return 0;
    }
}

void preorder_search_VSD(Nod* vf)
{
    if (vf == NULL)
    {
        return;
    }
    printf("%d ", vf->nr);
    preorder_search_VSD(vf->left);
    preorder_search_VSD(vf->right);
    preorder_search_VSD(vf->middle);
}

void preorder_search_VSD_ascending(Nod* vf, int asc_links[50], int parent)
{
    if (vf == NULL)
    {
        return;
    }
    asc_links[vf->nr] = parent;

    preorder_search_VSD_ascending(vf->left, asc_links, vf->nr);
    preorder_search_VSD_ascending(vf->right, asc_links, vf->nr);
    preorder_search_VSD_ascending(vf->middle, asc_links, vf->nr);
}

int main()
{
    int n = 8, i;
    int left_array[25], rigth_array[25], middle_array[25];
    Nod* vf = NULL;
    int asc_links[50];

    read_binaryTree(left_array, rigth_array, middle_array, n);

    print_array(left_array, n);
    print_array(rigth_array, n);
    print_array(middle_array, n);

    vf = create_tree(1, left_array, rigth_array, middle_array);

    printf("preorder search list VSD\n");
    preorder_search_VSD(vf);
    printf("\n");

    asc_links[1] = 0;

    preorder_search_VSD_ascending(vf, asc_links, 0);
    for (i = 1; i <= n; i++)
    {
        printf("%d ", asc_links[i]);
    }
    printf("\n");
    return 0;
}