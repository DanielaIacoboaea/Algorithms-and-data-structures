#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int nr;
    struct Nod* left;
    struct Nod* right;
} Nod;

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


Nod* create_tree(int nod, int left_array[25], int rigth_array[25])
{
    if (nod)
    {
        Nod* temp = (Nod*) malloc (sizeof(Nod));
        temp->nr = nod;
        temp->left = create_tree(left_array[nod], left_array, rigth_array);
        temp->right = create_tree(rigth_array[nod], left_array, rigth_array);
        return temp;
    }else{
        return 0;
    }
}

/*
Nod* add_node(int info)
{
  //  printf("aaaaaa\n");
    Nod* newNode;
    newNode = (Nod* ) malloc (sizeof(Nod));
    newNode->nr = info;
    newNode->left = NULL;
    newNode->right= NULL;

    return newNode;
}



Nod* find_end_right(Nod* curent)
{
    while(curent->right)
    {
        curent = curent->right;
    }
    return curent;
}

Nod* find_end_left(Nod* curent)
{
    while(curent->left)
    {
        curent = curent->left;
    }
    return curent;
}

Nod* create_tree_left(int left_array[25], int rigth_array[25], int n)
{
   // printf("bbbbbb\n");
    int i;
    Nod* end = NULL;
    Nod* vf = end;

    for (i = 1; i <=n; i++)
    {
        end = add_node(left_array[i]);
        end = end->left;
    }
    return vf;
}

void create_tree_right(Nod** vf, int left_array[25], int rigth_array[25], int n)
{
   // printf("bbbbbb\n");
    int i;
    Nod* end = NULL;

    for (i = 1; i <=n; i++)
    {
        end = add_node(rigth_array[i]);
        (*vf)->right = end->right;
    }
}

/*
Nod* create_linkedTree(Nod* vf, int left_array[25], int rigth_array[25], int start, int n)
{
    int i;
    Nod* temp = (Nod*) malloc (sizeof(Nod));

    Nod* newNode_right;
    Nod* newNode_left;

    Nod* end_right = (Nod*) malloc (sizeof(Nod));
    Nod* end_left = (Nod*) malloc (sizeof(Nod));

    temp->nr = start;
    temp->left = end_left;
    temp->right = end_right;

    for (i = 1; i <= n; i++)
    {
        printf("i: %d\n", i);
        newNode_left = (Nod* ) malloc (sizeof(Nod));
        newNode_left->nr = left_array[i];
        printf("newNode_left->nr: %d\n", newNode_left->nr);
        newNode_left->left = NULL;
        newNode_left->right= NULL;

        newNode_right = (Nod* ) malloc (sizeof(Nod));
        newNode_right->nr = rigth_array[i];
        printf("newNode_right->nr: %d\n", newNode_right->nr);
        newNode_right->left = NULL;
        newNode_right->right= NULL;

        end_left = newNode_left;
        end_right = newNode_right;
    }
    return temp;
}
*/


void inorder_search_SVD(Nod* vf)
{
  //  printf("ccccccc\n");
    if (vf == NULL)
    {
        return;
    }

    inorder_search_SVD(vf->left);
    printf("%d ",vf->nr);
    inorder_search_SVD(vf->right);
    
    /*
    Nod* temp_vf_left = vf->left;
    Nod* temp_vf_right = vf->right;

   // printf("inorder bbbbbbb\n");
    printf("vf->nr: %d\n", vf->nr);
    if (vf->nr)
    {
        printf("vf->left->next: %d",temp_vf_left->nr);
        inorder_search_SVD(temp_vf_left);
        printf("%d ",vf->nr);
        inorder_search_SVD(temp_vf_right);
       // printf("vf->right->next: %d", vf->right->nr);
    }
    */
}

void preorder_search_VSD(Nod* vf)
{
  //  printf("dddddd\n");
  //  printf("preorder ccccccc\n");
    if (vf == NULL)
    {
        return;
    }
    printf("%d ", vf->nr);
    preorder_search_VSD(vf->left);
    preorder_search_VSD(vf->right);
}

void postorder_search_SDV(Nod* vf)
{
   // printf("eeee\n");
   // printf("postorder dddddd\n");
    if(vf == NULL)
    {
        return;
    }
    postorder_search_SDV(vf->left);
    postorder_search_SDV(vf->right);
    printf("%d ", vf->nr);
}

int main()
{
    int n = 6;
    int left_array[25], rigth_array[25];
    Nod* vf = NULL;
    read_binaryTree(left_array, rigth_array, n);

    print_array(left_array, n);
    print_array(rigth_array, n);

   // vf = create_tree(left_array, rigth_array, n);
   // printf("vf->right->nr: %d\n", vf->right->nr);
  //  printf("vf->left->nr: %d\n", vf->left->nr);
    //vf = create_tree_left(left_array, rigth_array, n);
   // vf = create_tree_right(left_array, rigth_array, n);

    vf = create_tree(1, left_array, rigth_array);


    printf("inorder search list SVD:\n");
    inorder_search_SVD(vf);
    printf("\n");

    printf("preorder search list SVD:\n");
    preorder_search_VSD(vf);
    printf("\n");

    printf("postorder search list SDV:\n");
    postorder_search_SDV(vf);
    printf("\n");

    return 0;
}