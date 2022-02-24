#include <stdio.h>

int binary_search_recursiv(int a[], int n, int x, int low, int high)
{
    int mid;
    mid = (low+high)/2;
    
    if(low > high)
    {
        return -1;
    }else{
        if(x == a[mid])
        {
            return mid;
        }else if(x < a[mid])
        {
            binary_search_recursiv(a, n, x, low, mid-1);
        }else{
            binary_search_recursiv(a, n, x, mid+1, high);
        }
    }
}

int main()
{
    int a[9] = {0, 1, 7, 15, 20, 30, 50, 52, 53};
    int x, index;
    printf("x: ");
    scanf("%d", &x);

    index = binary_search_recursiv(a, 9, x, 0, 8);
    printf("index: %d\n", index);
    if(index != -1)
    {
        printf("elementul %d se afla la index %d\n", x, index);
    }else
    {
        printf("elementul nu exista\n");
    }

    return 0;
}