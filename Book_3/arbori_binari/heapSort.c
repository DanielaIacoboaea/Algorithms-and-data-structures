#include <stdio.h>

void read_unsorted_array(int arbore[25], int n)
{
    FILE* f;
    f = fopen("vector_minHeap.txt", "r");

    int i, x;

    for (i = 1; i <= n; i++)
    {
        fscanf(f, "%d", &x);
        arbore[i] = x;
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

int find_minIndex(int i, int n, int arbore[25])
{
    if (2 * i + 1 <= n)
    {
        if (arbore[2 *i] <= arbore[2*i+1])
        {
            return 2*i;
        }else{
            return 2 * i + 1;
        }
    }else{
        return 2 * i;
    }
}

void minHeap_order(int i, int n, int arbore[25])
{
    int index, aux;
    if (i <= n/2)
    {
        index = find_minIndex(i, n, arbore);
        {
            if (arbore[i] > arbore[index])
            {
                aux = arbore[i];
                arbore[i] = arbore[index];
                arbore[index] = aux;
                minHeap_order(index, n, arbore);
            }
        }
    }
}

void minHeap(int n, int arbore[25])
{
    int i;

    for (i = n/2; i >= 1; i--)
    {
        minHeap_order(i, n, arbore);
    }
}

void heapSort(int n, int arbore[25])
{
    int i, aux;
    minHeap(n, arbore);

    for (i = n; i >= 1; i--)
    {
        aux = arbore[i];
        arbore[i] = arbore[1];
        arbore[1]= aux;
        minHeap_order(1, i-1, arbore);
    }
}

int main()
{
    int n = 6, i;
    int arbore[25];

    read_unsorted_array(arbore, n);
    print_array(arbore, n);

    heapSort(n, arbore);
    print_array(arbore, n);

    return 0;
}