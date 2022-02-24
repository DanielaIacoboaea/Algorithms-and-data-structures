#include <stdio.h>
#include <stdlib.h>

const int x[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int y[8] = {2, 2, 1, -1, -2, -2, -1, 1};

int n, sol[1000][2], t[25][25];

void back(int k, int lin, int col)
{
    int linie, coloana, i;
    if (k == n*n)
    {
        printf("solutie\n");
        for(i = 1; i <= k-1; i++)
        {
            printf("%d, %d\n", sol[i][0], sol[i][1]);

        }
        printf("linie, coloana:\n");
        printf("%d, %d", lin, col);
        exit(0);
    }else{
        sol[k][0] = lin;
        sol[k][1] = col;
        for (i = 0; i <=7; i++)
        {
            linie = lin + x[i];
            coloana = col + y[i];
            if(linie <= n && linie >= 1 && coloana <= n && coloana >= 1 && t[linie][coloana] == 0)
            {
                t[linie][coloana] = 1;
                back(k+1, linie, coloana);
                t[linie][coloana] = 0;
            }
        }
    }
}
int main()
{
    printf("n:\n");
    scanf("%d", &n);
    back(1, 1, 1);
    return 0;
}