//counting sort

#include <stdio.h>

int main()
{
    int arr[100], count[100], sort[100];
    int i, n, j;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < 10; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", count[i]);
    }
    for (i = 1; i < n; i++)
    {
        count[i] = count[i - 1] + count[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == count[j])
            {
                sort[i] = arr[j];
                count[j]--;
            }
        }
    }
    printf("array sortat sort[i]: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", count[i]);
    }
    return 0;
}
