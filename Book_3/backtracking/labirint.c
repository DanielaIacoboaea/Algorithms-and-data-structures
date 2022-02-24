#include<stdio.h>

int m, n, lin, col, l[10][10], sol[100][2], i, j;

int vizitat(int k, int lin, int col)
{
    int v=0;
    for(i = 1; i<=k; i++)
    {
        if(sol[i][0] == lin && sol[i][1] == col)
        {
            v = 1;
        }
    }
    return v;
}

void tipar(int k, int lin, int col)
{
    printf("solutie\n");
    for(i=1; i<=k-1; i++)
    {
        printf("%d,%d  ", sol[i][0], sol[i][1]);
    }
    if(lin == 0)
    {
        printf("iesire N\n");
    }else if(lin == m+1)
    {
        printf("iesire S\n");
    }else if (col==0)
    {
        printf("iesire V\n");
    }else{
        printf("iesire E\n");
    }
}

void back(int k, int lin, int col)
{
    int i;
    if(lin == 0 || lin == m+1 || col == 0 || col == n+1)
    {
        tipar(k, lin, col);
    }else{
        sol[k][0] = lin;
        sol[k][1] = col;
        for(i = 1; i<=4; i++)
        {
            switch(i)
            {
                case 1:
                {
                    if(l[lin][col] & 8 && !vizitat(k, lin-1, col))
                    {
                        back(k+1, lin-1, col);
                    }
                    break;
                }
                case 2:
                {
                    if(l[lin][col] & 4 && !vizitat(k, lin, col+1))
                    {
                        back(k+1, lin, col+1);
                    }
                    break;
                }
                case 3:
                {
                    if(l[lin][col] & 2 && !vizitat(k, lin+1, col))
                    {
                        back(k+1, lin+1, col);
                    }
                    break;
                }
                case 4:
                {
                    if(l[lin][col] & 1 && !vizitat(k, lin, col-1))
                    {
                        back(k+1, lin, col-1);
                    }
                    break;
                }
            }
        }
    }
}

int main()
{
    printf("m,n:\n");
    scanf("%d,%d", &m,&n);
    for(i = 1; i<=m; i++)
    {
        for(j = 1; j<=n; j++)
        {
            printf("l[%d][%d]: \n", i, j);
            scanf("%d", &l[i][j]);
        }
    }
    printf("linie, coloana:\n");
    scanf("%d,%d", &lin, &col);

    back(1, lin, col);
    return 0;
}