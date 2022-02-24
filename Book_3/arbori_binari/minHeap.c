#include <stdio.h>

void read_tree(int arbore[25], int n)
{
    FILE* f;
    f = fopen("vector_minHeap.txt", "r");

    int x, i;

    while (!feof(f))
    {
        for (i = 1; i <= n; i++)
        {
            fscanf(f, "%d", &x);
            arbore[i] = x;
        }  
    }
}

void print_tree(int arbore[25], int n)
{
    int i;

    for (i = 1; i <= n; i++)
    {
        printf("%d ", arbore[i]);
    }
    printf("\n");
}

int find_minIndex(int i, int n, int arbore[25])
{
    if (2 * i + 1 <= n)
    {
        if (arbore[2 * i] < arbore[2 * i + 1])
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
        index = find_minIndex(i, n, arbore);
        if (arbore[i] > arbore[index])
        {
            aux = arbore[i];
            arbore[i] = arbore[index];
            arbore[index] = aux;
            order_minHeap(index, n, arbore);
        }
    }
}

int main()
{
    int i, n = 6;
    int arbore[25];

    read_tree(arbore, n);
    print_tree(arbore, n);

    order_minHeap(1, n, arbore);
    print_tree(arbore, n);

    return 0;
}