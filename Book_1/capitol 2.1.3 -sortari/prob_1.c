// selection sort

#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    //one by one move boundry of unsorted array
    for (i = 0; i < n-1; i++)
    {
        //find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
                //swap the found min element with the first element
                swap(&arr[min_idx], &arr[i]);
            }
        }
    }
}

void print_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    print_array(arr, n);
    return 0;
}
