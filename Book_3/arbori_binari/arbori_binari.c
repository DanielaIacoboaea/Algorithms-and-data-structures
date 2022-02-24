#include <stdio.h>

void read_binaryTree(int left_array[25], int rigth_array[25], int n)
{
    FILE* f;
    f = fopen("arbori.txt", "r");

    int v_l, i, v_r, j;

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

void inorder_search_SVD(int nod, int left_array[25], int rigth_array[25])
{
    if (nod == 0)
    {
        return;
    }else{
        inorder_search_SVD(left_array[nod], left_array, rigth_array);
        printf("%d ", nod);
        inorder_search_SVD(rigth_array[nod], left_array, rigth_array);
    }
}

void preorder_search_VSD(int nod, int left_array[25], int rigth_array[25])
{
    if (nod == 0)
    {
        return;
    }else{
        printf("%d ", nod);
        preorder_search_VSD(left_array[nod], left_array, rigth_array);
        preorder_search_VSD(rigth_array[nod], left_array, rigth_array);
    }
}

void postorder_search_SDV(int nod, int left_array[25], int rigth_array[25])
{
    if(nod == 0)
    {
        return;
    }else{
        postorder_search_SDV(left_array[nod], left_array, rigth_array);
        postorder_search_SDV(rigth_array[nod], left_array, rigth_array);
        printf("%d ", nod);
    }

}

int main()
{
    int n = 6;
    int left_array[25], rigth_array[25];
    read_binaryTree(left_array, rigth_array, n);

    print_array(left_array, n);
    print_array(rigth_array, n);

    printf("inorder search SVD:\n");
    inorder_search_SVD(1, left_array, rigth_array);
    printf("\n");

    printf("preorder search SVD:\n");
    preorder_search_VSD(1, left_array, rigth_array);
    printf("\n");

    printf("postorder search SDV:\n");
    postorder_search_SDV(1, left_array, rigth_array);
    printf("\n");



    return 0;
}