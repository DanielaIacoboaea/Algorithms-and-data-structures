#include <stdio.h>

int vizitat(int solutie[15], int n, int numar)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        //printf("AAAAA\n");
        if(solutie[i] == numar)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int distante[15][15];
    int i, j, n, distanta_min = 0, start, solutie[15], min = 100, count;
    printf("numar orase: \n");
    scanf("%d", &n);

    printf("primul oras:\n");
    scanf("%d", &start);

    for(i = 1; i <= n; i++)
    {
        for(j = i; j <= n; j++)
        {
            if(i == j)
            {
                distante[i][j] = 0;
            }else
            {
                printf("distanta intre %d si %d\n", i, j);
                scanf("%d", &distante[i][j]);
                distante[j][i] = distante[i][j];
            }
        }
    }

    i = start;
    solutie[1] = start;
    count = 1;
    for(i = start; i<= n; i++)
    {
        printf("i:%d, j: %d\n", i, j);
        printf("distante[i][j] primul for: %d\n", distante[i][j]);
        //printf("aaaaa\n");
        min = 1000;
        for (j = 1; j <= n; j++)
        {
            printf("i:%d, j: %d\n", i, j);
            printf("distante[i][j] al doilea for: %d\n", distante[i][j]);
            //printf("bbbb\n");
            if(distante[i][j] != 0 && distante[i][j] < min && vizitat(solutie, count, j))
            {
                printf("i:%d, j: %d\n", i, j);
                printf("distante[i][j] al doilea for din if: %d\n", distante[i][j]);
               // printf("ccc\n");
                min = distante[i][j];
                count++;
                solutie[count] = j;
                distanta_min = distanta_min + distante[i][j];
                i = j;
            }
        }
    }
    printf("solutia pentru distanta min de %d este\n", distanta_min);
    for(i = 1; i <= count; i++)
    {
        printf("%d ", solutie[i]);
    }

    return 0;
}