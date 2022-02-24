/* 2 vectori a si b cu n elemente: 
toate elementele lor se pot grupa in n perechi de forma (a[i], b[j]) astfel incat suma a[i] + b[j] sa fie aceeasi pentru
orice pereche
scrieti un program care sa determine suma si elementele fiecarei perechi.
de ex: n = 4; a={4,2,1,5} si b={5,3,2,6} se va afisa
7
4 3
2 5
1 6
5 2
*/

#include <stdio.h>

int main()
{
    int a[50], b[50];
    int n, i, j, sum = 0;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
        sum = sum + a[i];
    }
    for (i = 0; i < n; i++)
    {
        printf("b[%d]: ", i);
        scanf("%d", &b[i]);
        sum = sum + b[i];
    }
    sum = sum/n;
    printf("sum: %d\n", sum);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i] + b[j] == sum)
            {
                printf("%d,%d\n", a[i], b[j]);
            }
        }
    }
    /*
    for (i = 0; i < n; i++)
    {
        printf("%d, %d\n", a[i], s-a[i]);
    }
    */
    return 0;
}
