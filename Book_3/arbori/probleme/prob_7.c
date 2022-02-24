#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* left;
    struct Nod* right;
    struct Nod* middle;
} Nod;

Nod* add_node(int data)
{
    printf("ccccccccc\n");
    Nod* temp = (Nod*) malloc(sizeof(Nod));

    temp->info = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->middle = NULL;

    return temp;
}

void search_empty_child(Nod** parent, int data)
{
    printf("bbbbbbbbbb\n");
    if((*parent)->left == NULL)
    {
        (*parent)->left = add_node(data);
        return;

    }else if ((*parent)->middle == NULL)
    {
        (*parent)->middle = add_node(data);
        return;
        
    }else if ((*parent)->right == NULL)
    {
        (*parent)->right = add_node(data);
        return;
    }
}

void search_parent(Nod** root, int data, int to_add)
{
    printf("DDDDDDDDDDDDD\n");
    printf("root->info search parent: %d\n", (*root)->info);
    if(*root == NULL)
    {
        return;
    }else{

        if ((*root)->info == data)
        {
            printf("if root->info == data: %d, data: %d\n", (*root)->info, data);
            search_empty_child(&(*root), to_add);
            return;
        }else{
            search_parent(&(*root)->left, data, to_add);
            printf("search parent left: data: %d, to_add: %d\n", data, to_add);
            search_parent(&(*root)->right, data, to_add);
            printf("search parent right: data: %d, to_add: %d\n", data, to_add);
            search_parent(&(*root)->middle, data, to_add);
            printf("search parent middle: data: %d, to_add: %d\n", data, to_add);
        }
    }

}

void build_tree(Nod** vf)
{
    printf("aaaaaa\n");
    FILE* f;
    f = fopen("ref_descentente.txt", "r");
    int x, y;

    while(!feof(f))
    {
        fscanf(f, "%d %d", &x, &y);
        printf("x: %d , y: %d\n", x, y);
        if (*vf == NULL)
        {
            *vf = add_node(x);
            search_empty_child(&(*vf), y);
        }else{
            printf("else search parent x: %d\n", x);
            search_parent(&(*vf), x, y);
            printf("else returns after searching parent\n");
        }
    }
    fclose(f);
}

void print_preorder_tree(Nod* root)
{
    printf("dddddddddd\n");
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->info);
    print_preorder_tree(root->left);
    print_preorder_tree(root->middle);
    print_preorder_tree(root->right);
}

int main()
{
    Nod* vf = NULL;
    int n = 8, i;
    int asc_links[50];

    build_tree(&vf);
    print_preorder_tree(vf);

    return 0;
}