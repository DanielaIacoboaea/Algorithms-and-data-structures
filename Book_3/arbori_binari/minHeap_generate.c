#include <stdio.h>

void read_binary_tree(int arbore[25], int n)
{
    FILE* f;
    f = fopen("vector_minHeap.txt", "r");

    int i, v;

    for (i = 1; i <= n; i++)
    {
        fscanf(f, "%d", &v);
        arbore[i] = v;
    }

    fclose(f);
}

void print_array(int arbore[25], int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%d ", arbore[i]);
    }
    printf("\n");
}

int find_smaller_index(int i, int n, int arbore[25])
{
    if (2 * i + 1 <= n)
    {
        if (arbore[2 * i] <= arbore[2 * i + 1])
        {
            return 2 * i;
        }else{
            return 2 * i + 1;
        }
    }else{
        return 2 * i;
    }
}

void order_minHeap(int i, int n, int arbore[25])
{
    int index, aux;
    
    if (i <= n/2)
    {
        index = find_smaller_index(i, n, arbore);
        if (arbore[i] > arbore[index])
        {
            aux = arbore[i];
            arbore[i] = arbore[index];
            arbore[index] = aux;
            order_minHeap(index, n, arbore);
        }
    }
}

void create_minHeap(int n, int arbore[25])
{
    int i;
    for (i = n/2; i >= 1; i--)
    {
        order_minHeap(i, n, arbore);
    }
}

int main()
{
    int i, n = 6;
    int arbore[25];

    read_binary_tree(arbore, n);
    print_array(arbore, n);

    create_minHeap(n, arbore);
    print_array(arbore, n);

    return 0;
}