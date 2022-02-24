/* se considera n intervale inchise [a, b]
sa se det reuniunea lor
*/

#include <stdio.h>

int main()
{
    int n, a, b, i, max = 0, min, x, y, j;
    int left[100], right[100];
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a, b: ");
        scanf("%d,%d", &left[i], &right[i]);
    }
    for (i = 0; i + 1 < n; i++)
    {
        for (j = i+ 1; j < n; j++)
        {
            if(left[i] > left[j])
            {
                x = left[i];
                left[i] = left[j];
                left[j] = x;
                y = right[i];
                right[i] = right[j];
                right[j] = y;
            }
        }
    }
    x = left[0];
    y = right[0];
    for (i = 1; i < n; i++)
    {
        if (left[i] > y)
        {
            printf("x: %d, y: %d\n", x, y);
            x = left[i];
            y = right[i];
        }else if (right[i] > y)
        {
            y = right[i];
            printf("x: %d, y: %d\n", x, y);
        }
    }

    /*
    min = right[0];
    for (i = 0; i < n; i++)
    {
        if (right[i] < min)
        {
            min = right[i];
        }
    }

    for (i = 0; i < n; i++)
    {
        if (left[i] > max && left[i] < min)
        {
            max = left[i];
        }
    }
    printf("intervalul comun este [%d,%d]\n", max, min);
    */

    return 0;
}
