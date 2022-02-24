#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Nod {
    int info;
    struct Nod* next;
} Nod;

Nod* find_end(Nod* nod_curent) {
    while(nod_curent->next) {
        nod_curent = nod_curent->next;
    }
    return nod_curent;
}

void my_add(Nod** vf, int info) {
    Nod* end;

    if(*vf == NULL) {
        *vf = (Nod*) malloc(sizeof(Nod));
        end = *vf;
    }
    else {
        end = find_end(*vf);
        end->next = (Nod*) malloc(sizeof(Nod));
        end = end->next;
    }

    end->info = info;
    end->next = NULL;
}

void test_my_add()
{
    Nod* test = (Nod* ) malloc (sizeof(Nod));
    test = NULL;

    my_add(&test, 4);
    my_add(&test, 2);
    my_add(&test, 10);

    printf("test-info: %d \n", test->info);
    printf("test-next->info: %d \n", test->next->info);
    printf("test-next->next-> info: %d \n", test->next->next->info);
    
    assert(test->info == 4);
    assert(test->next != NULL);
    assert(test->next->info == 2);
    assert(test->next-> next!= NULL);
    assert(test->next->next->info == 10);
    assert(test->next->next->next == NULL);

}

void my_add_front(Nod** vf, int info)
{
    Nod* temp;
    temp = (Nod* ) malloc(sizeof(Nod));

    temp->info = info;
    if(*vf == NULL)
    {
        temp->next = NULL;
    }else{
        temp->next = *vf;
    }

    *vf = temp;

}


int delete_by_value(Nod** vf, int x)
{
    int index = 0;
    Nod* cursor = *vf;

    if((*vf)->info == x)
    {
        *vf = (*vf)->next;
        return index;
    }

    while(cursor && cursor->next != NULL)
    {
        index++;

        if(cursor->next->info == x)
        {
            if(cursor->next->next == NULL)
            {
                cursor->next = NULL;
                return index;

            }else{
                cursor->next = cursor->next->next;
                return index;
            }
        }
        cursor = cursor->next;
    }
    return -1;
}

int insert_after(Nod** vf, int after, int value)
{
    int index = 0;
    Nod* temp = *vf;
    Nod* new_node;

    while(temp)
    {
        index++;
        if(temp->info == after)
        {
            if(temp->next == NULL)
            {
                new_node = (Nod* ) malloc(sizeof(Nod));
                new_node->info = value;
                new_node->next = NULL;
                temp->next = new_node;
                return index;
            }else{
                new_node = (Nod* ) malloc(sizeof(Nod));
                new_node->info = value;
                new_node->next = temp->next;
                temp->next = new_node;
                return index;
            }
        }
        temp = temp->next;
    }
    return -1;
}

int list_length(Nod** vf)
{
    int length = 0;
    Nod* curent = *vf;
    while(curent)
    {
        length++;
        curent = curent->next;
    }
    return length;

}

int* list_to_array(Nod** vf)
{
    Nod* curent = *vf;
    int* arr = malloc(list_length(vf) * sizeof(int));
    int i;

    for(i = 0; i < list_length(vf); i++)
    {
        arr[i] = curent->info;
        curent = curent->next;
    }
    return arr;
}

void delete_all_by_value(Nod** vf, int x)
{
    Nod* cursor = *vf;
    
    while((*vf)->info == x)
    {
        if((*vf)->next == NULL)
        {
            *vf = NULL;
            return;
        }else{
            *vf = (*vf)->next;
        }
    }

    while(cursor && cursor->next != NULL)
    {
        if(cursor->next->info == x)
        {
            if(cursor->next->next == NULL)
            {
                cursor->next = NULL;

            }else{
                cursor->next = cursor->next->next;
            }
        }
        cursor = cursor->next;
    }

}

void my_print(Nod* nod_curent) {
    while(nod_curent) {
        printf("%d\n", nod_curent->info);
        nod_curent = nod_curent->next;
    }
}

int main() {
    Nod* vf = NULL;
    int index;
    int n;
    int *p;

    my_add_front(&vf, 3);
    my_add_front(&vf, 2);
    my_add_front(&vf, 1);
    my_add_front(&vf, 1);
    my_add_front(&vf, 3);

    my_print(vf);

    test_my_add();

/*
    index = delete_by_value(&vf, 8);
    printf("index: %d\n", index);
    my_print(vf);
*/
/*
    index = insert_after(&vf, 11, 10);
    printf("index: %d\n", index);
    my_print(vf);
*/
/*
    n = list_length(&vf);
    printf("length %d\n", n);
*/
/*
    p = list_to_array(&vf);
    printf("list-to-array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p+i));
    }
*/
/*
    printf("\n");

    delete_all_by_value(&vf, 3);
    if(vf)
    {
        my_print(vf);

    }else{

        printf("NULL\n");
    }
*/
}