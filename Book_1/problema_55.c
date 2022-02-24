/* afisati toate nr naturale nenule de la 1 la n^2 in ordine crescatoare
cate n pe rand (separate prin cate un spatiu) ex: n = 4 se va afisa:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/ 

#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, last_num;
    printf("n: ");
    scanf("%d", &n);
    last_num = pow(n, 2);
    int j = 0;

    for (i = 1; i <= last_num; i++)
    {
        printf("%d ", i);
        j++;
        if (j == n)
        {
            printf("\n");
            j = 0;
        }
    }
    return 0;
}
