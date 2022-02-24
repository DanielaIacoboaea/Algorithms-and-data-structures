#include <stdio.h>

const int x[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int y[8] = {2, 2, 1, -1, -2, -2, -1, 1};

int t[50][50], mutari, i, j, n;

int numar(int l, int c)
{
    int nr = 0, i;
    for (i = 0; i <= 7; i++)
    {
        if (l + x[i] >= 1 && l + x[i] <= n && c + y[i] >= 1 && c+y[i] <= n && t[l+x[i]][c+y[i]]==0)
        {
            nr++;
        }
    }

    return nr;
}

void mut(int l, int c)
{
    int i, min, v, linie, coloana, gasit;
    t[l][c] = mutari+1;
    gasit = 0;
    min = 9;
    for (i = 0; i <= 7; i++)
    {
        if (l+x[i] >= 1 && l+x[i] <= n && c+y[i] >= 1 && c+y[i] <= n && t[l+x[i]][c+y[i]]==0)
        {
            v = numar(l+x[i], c+y[i]);
            if(v<min)
            {
                min = v;
                linie = l + x[i];
                coloana = c + y[i];
                gasit = 1;
            }
        }
    }
    if(gasit)
    {
        mutari++;
        mut(linie, coloana);
    }
}

int main()
{
    printf("n: \n");
    scanf("%d", &n);
    t[1][1] = 1;
    if(mutari == n *n -1)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                printf("%d ", t[i][j]);
            }
        }
        printf("\n");
    }else
    {
        printf("tentativ esuata\n");
    }

    return 0;
}