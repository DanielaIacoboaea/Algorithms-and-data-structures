/* de facut functie my_strcpy*/

#include <stdio.h>
#include <string.h>

int main()
{
    char a[20][20], x[20];
    unsigned int n, i, j;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf(" %c", &a[i][0]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%s", a[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (strcmp(&a[j][0], &a[i][0]) < 0)
            {
                strcpy(x, &a[j][0]);
                strcpy(&a[j][0], &a[i][0]);
                strcpy(&a[i][0], x);
            }
        }
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c", a[i][j]);
        }
    }
    return 0;
}
