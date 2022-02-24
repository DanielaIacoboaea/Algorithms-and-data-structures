#include <stdio.h>

int main()
{
    int nr[100], sume[100], sume1[100], alege[100];
    int n, i, j, S, Suma;

    printf("n:\n");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        printf("nr[%d]: ", i);
        scanf("%d", &nr[i]);
        S+= nr[i];
    }

    for(i = 1; i <= n; i++)
    {
        sume1[nr[i]] = 1;
        for (j = 1; j <= S; j++)
        {
            if(sume[j] == 1)
            {
                sume1[j+nr[i]] == 1;
            }
        }
        for (j = 1; j <= S; j++)
        {
            if(sume1[j] == 1 && sume[j] == 0)
            {
                sume[j] = 1;
                alege[j] = nr[i];
                sume1[j] = 0;
            }
        }
    }
    printf("suma: \n");
    scanf("%d", &Suma);

    if(Suma <= S)
    {
        if(alege[Suma])
        {
            while (Suma)
            {
                printf("%d ", alege[Suma]);
                Suma-= alege[Suma];
            }
        }
    }else{
        printf("suma nu se poate forma\n");
    }

    return 0;
}