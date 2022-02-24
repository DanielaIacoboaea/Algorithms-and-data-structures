/* 
n intervale         afisati cate intervale pot fi eliminate (sunt continute in celelalte intervale)
n = 5               3 
0 10
2 9
3 8
1 15
6 11
*/

#include <stdio.h>

typedef struct interval{
    int a, b;

} interval;

void sort_struct(interval values[50], int n)
{
    struct interval aux;
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = n - 2; j > i; j--)
        {
            if (values[j].a < values[j-1].a)
            {
                aux = values[j];
                values[j] = values[j-1];
                values[j-1] = aux;
            }
        }
    }
}

int main()
{
    FILE *f; 
    interval x[50];
    int i, j, n, count = 0, a_temp, b_temp, sum = 0, k, l = 0;
    f = fopen("interval.in", "r");
    printf("n: ");
    scanf("%d", &n);
    while (!feof(f))
    {
        fscanf(f, "%d %d", &x[count].a, &x[count].b);
        count++;
    }
    sort_struct(x, count);
    for (i = 0; i < count-1; i++)
    {
        printf("%d %d\n", x[i].a, x[i].b);
    }
    printf("\n");
    //a_temp = x[0].a;
    //b_temp = x[0].b;
    for (i = 1; i < n; i++)
    {
        a_temp = x[l].a;
        b_temp = x[l].b;
        //printf("i: %d\n", i);
        if (x[i].a >= a_temp && x[i].a <= b_temp && x[i].b <= b_temp)
        {
            //printf("%d %d\n", x[i].a, x[i].b);
            sum++;
            printf("sum din if: %d\n", sum);
            for (j = i; j < n; j++)
            {
                printf("j: %d\n", j);
                for (k = j+1; k < n; k++)
                {
                    x[j].a = x[k].a;
                    x[j].b = x[k].b;
                    printf("x[j], x[j]: %d %d\n", x[j].a, x[j].b);
                    n--;
                }
            }
            i--;
        }
        l++;
    }
    printf("sum: %d\n", sum);
    fclose(f);
    return 0;
}
