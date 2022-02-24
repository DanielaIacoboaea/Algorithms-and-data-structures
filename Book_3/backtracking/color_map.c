#include <stdio.h>
#include <stdlib.h>


int valid(int k, int n, int borders[6][6], int sol[10])
{
    int i, j, ev = 1, l;
    for(l = 1; l<= k-1; l++)
    {
        if(sol[k] == sol[l] && borders[k][l] == 1)
        {
            ev = 0;
        }
    }
    return ev;
}

void back(int k, int n, int borders[6][6], int sol[10])
{
    int i;
    if(k == n+1)
    {
        for(i = 1; i <=n; i++)
        {
            printf("%d ", sol[i]);
        }
        printf("\n");
        exit(0);
      
    }else{
        for(i = 1; i < 5; i++)
        {
            sol[k] = i;
            if(valid(k, n, borders, sol))
            {
                back(k+1, n, borders, sol);
            }
        }
    }
}

int main()
{
    int sol[10];
    int borders[6][6];
    int i, j, n;
    printf("enter n of countries: \n");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("border[%d][%d]: \n", i, j);
            scanf("%d", &borders[i][j]);
        }
    }

    back(1, n, borders, sol);

    return 0;
}