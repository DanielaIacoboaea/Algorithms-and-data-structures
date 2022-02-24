#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* left;
    struct Nod* right;
}Nod;

Nod* add_newNode(int nr)
{
    Nod* temp;
    temp = (Nod*) malloc(sizeof(Nod));

    temp->info = nr;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void insert_node(Nod** root, int data)
{
    if(*root != NULL)
    {
        if ((*root)->info == data)
        {
            printf("nodul este deja inserat\n");
        }else if((*root)->info < data)
            {
                insert_node(&(*root)->right, data);
            }else{
                insert_node(&(*root)->left, data);
            }
    }else{
        *root = add_newNode(data);
    }
}

Nod* search_node(Nod* root, int data)
{
    if(root != NULL)
    {
        if(root->info == data)
        {
            return root;
        }else if (root->info < data){
            search_node(root->right, data);
        }else {
            search_node(root->left, data);
        }
    }else{
        return NULL;
    }
}

void print_nodes(Nod* root)
{
    if (root == NULL)
    {
        return;
    }
    print_nodes(root->left);
    printf("%d ", root->info);
    print_nodes(root->right);
}

void two_children_delete(Nod** root, Nod** f)
{
    Nod* temp;
    if ((*f)->right)
    {
        two_children_delete(&(*root), &(*f)->right);
    }else{
        (*root)->info = (*f)->info;
        temp = *f;
        *f = (*f)->left;
        free(temp);
    }
}

void delete_node(Nod** root, int data)
{
    Nod* temp;

    if (*root != NULL)
    {
        if((*root)->info == data)
        {
            if((*root)->left == NULL && (*root)->right == NULL)
            {
                free(*root);
                *root = NULL;
            }else if((*root)->left == NULL)
            {
                temp = (*root)->right;
                free(*root);
                *root = temp;
            }else if((*root)->right == NULL)
            {
                temp = (*root)->left;
                free(*root);
                *root = temp;
            }else{
                two_children_delete(&(*root), &(*root)->left);
            }
        }else if ((*root)->info < data)
        {
            delete_node(&(*root)->right, data);
        }else{
            delete_node(&(*root)->left, data);
        }

    }else{
        printf("empty tree\n");
    }
}

int main()
{
    Nod* root = NULL;
    int to_find, insert, to_delete;
    Nod* search;
    char optiune;

    insert_node(&root, 7);
    insert_node(&root, 4);
    insert_node(&root, 1);
    insert_node(&root, 3);
    insert_node(&root, 8);
    insert_node(&root, 9);

    print_nodes(root);
    printf("\n");

    do{
        printf("enter option:\n");
        scanf(" %c", &optiune);
        switch(optiune){

            case 'i':
                printf("enter value to insert:\n");
                scanf("%d", &insert);
                insert_node(&root, insert);
                print_nodes(root);
                printf("\n");
                break;

            case 'l':
                print_nodes(root);
                printf("\n");
                break;

            case 'c':
                printf("what value should we search for?\n");
                scanf("%d", &to_find);
                search = search_node(root, to_find);

                if (search)
                {
                    printf("valuarea %d este in arbore\n", to_find);
                }else{
                    printf("valuarea %d nu este in arbore\n", to_find);
                }
                break;

            case 's':
                printf("delete value:\n");
                scanf("%d", &to_delete);
                delete_node(&root, to_delete);
                print_nodes(root);
                printf("\n");
                break;

            default:
            {
                printf("invalid option!\n");
            }
        }

    }while (optiune != 't');
/*
    insert_node(&root, 10);
    print_nodes(root);
    printf("\n");

    printf("what value should we search for?\n");
    scanf("%d", &to_find);


    search = search_node(root, to_find);

    if (search)
    {
        printf("valuarea %d este in arbore\n", to_find);
    }else{
        printf("valuarea %d nu este in arbore\n", to_find);
    }

    delete_node(&root, 9);
    print_nodes(root);
    printf("\n");
*/

    return 0;
}