#include <stdio.h>
#include <string.h>

char a[100], b[100], sol[100][300], op;
int m, n, i, j, min, k, cost[100][100];

void next(int i, int j, char op)
{
    int l = 0;
    int c = 0;
    min = 1000;
    if (i > 0 && j > 0 && min >= cost[i-1][j-1])
    {
        l = i - 1;
        c = j - 1;
        op = 'm';
    }
    if (i > 0 && cost[i - 1][j] < min)
    {
        min = cost[i - 1][j];
        l = i - 1;
        c = j;
        op = 's';
    }
    if (j > 0 && cost[i][j-1] < min)
    {
        min = cost[i][j-1];
        l = i;
        c = j - 1;
        op = 'a';
    }
    if (cost[i][j] == min )
    {
        op= 'v';
        i = l;
        j = c;
    }
}

int main()
{
    int t;
    printf("a:\n");
    scanf("%s", a);
    printf("b:\n");
    scanf("%s", b);
    m = strlen(a)+1;
    n = strlen(b)+1;
    printf("m = %d, n = %d\n", m, n);

    for (i = 0; i <= m; i++)
    {
        cost[i][0] = i;
    }

    for (j = 0; j <= n; j++)
    {
        cost[0][j] = j;
    }

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
            {
                cost[i][j] = cost[i-1][j-1];
            }else
            {
                min = cost[i-1][j-1];
                if (min > cost[i-1][j])
                {
                    min = cost[i-1][j];
                }
                if (min > cost[i][j-1])
                {
                    min = cost[i][j-1];
                }
                cost[i][j] = 1 + min;
            }
        }
    }
    printf("distanta este %d\n", cost[m][n]);
    i = m; 
    j = n;
    while (i+j)
    {
        next(i, j, op);
        if (op!= 'v')
        {
            int x = 0;
            k++;
            sol[k][x++] = op;
            sol[k][x++] = ' ';
            for (t = 1; t <=j; t++)
            {
                sol[k][x++] = b[t];
            }
            for (t = i+1; t <=m; t++)
            {
                sol[k][x++] = a[t];
            }
        }
    }
    for (k = cost[m][n]; k >= 1; k--)
    {
        printf("%s ", sol[k]);
    }
    printf("%s ", b);
    return 0;
}