#include <stdio.h>

int main()
{
    int castig[50][50], alege[50][50], gr[100], c[100];
    int i, j, n, g, obiect;

    printf("G:\n");
    scanf("%d", &g);
    printf("n: \n");
    scanf("%d", &n);

    for(i = 1; i<=n; i++)
    {
        printf("Gr[%d]: \n", i);
        scanf("%d", &gr[i]);
        printf("C[%d]: \n", i);
        scanf("%d", &c[i]);
    }

    for(i = 1; i <= n; i++)
    {
        for (j = 1; j <= g; j++)
        {
            if (gr[i] <= j)
            {
                if (c[i] + castig[i-1][j-gr[i]] > castig[i - 1][j])
                {
                    castig[i][j] = c[i] + castig[i-1][j-gr[i]];
                    alege[i][j] = i;
                }else{
                    castig[i][j] = castig[i-1][j];
                    alege[i][j] = alege[i-1][j];
                }
            }else{
                castig[i][j] = castig[i-1][j];
                alege[i][j] = alege[i-1][j];
            }
        }
    }

    i = n;
    j = g;

    printf("castig total: %d\n", castig[i][j]);
    while(alege[i][j])
    {
        obiect = alege[i][j];
        printf("produsul %d greutate %d castig %d\n", alege[i][j], gr[alege[i][j]], c[alege[i][j]]);
        while (obiect == alege[i][j])
        {
            j-=alege[i][j];
            i--;
        }
    }
    return 0;
}