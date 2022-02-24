#include <stdio.h>

int binary_search(int a[], int n, int x)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if (x == a[mid])
        {
            return mid;
        }else if(x < a[mid])
        {
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

int main()
{
    int a[9] = {0, 1, 7, 15, 20, 30, 50, 52, 53};
    int x, index;
    printf("x: ");
    scanf("%d", &x);

    index = binary_search(a, 9, x);
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