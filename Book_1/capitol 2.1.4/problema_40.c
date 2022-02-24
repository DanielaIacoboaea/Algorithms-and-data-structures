/* fie un tablou unidimensional cu n elemente valori naturale
sa se det o submultime de elemente din tabloul citit pt care suma elementelor este divizibila cu n
ex: n = 7 si a = (3, 6, 4, 2, 11, 5, 11) se va afisa 6, 4, 2, 11, 5
*/

# include <stdio.h>

int main()
{
    int n, i, sum;
    int a[50];
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    return 0;
}
