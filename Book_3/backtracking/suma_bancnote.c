#include <stdio.h>

int suma, s, n, i, sol[100], a[100];

void back(int k)
{
    int i, s = 0;
    if(s == suma)
    {
       // printf("aaaa\n");
        printf("solutie\n");
        for(i = 1; i<=k-1; i++)
        {
            if(sol[i])
            {
                printf("%d monede de %d ", sol[i], a[i]);
            }
        }
        printf("\n");
    }else{
        //printf("bbbb\n");
        sol[k] = -1;
       // printf("sol[k] inainte de while: %d\n", sol[k]);
        while(sol[k]*a[k]+s < suma && k < n+1)
        {
            sol[k]++;
            //printf("sol[k] din while: %d\n", sol[k]);
            s+= sol[k] * a[k];
            //printf("s+ %d\n", s);
            back(k+1);
            s-= sol[k] * a[k];
            //printf("s- %d\n", s);
        }
    }
}

int main()
{
    printf("suma:\n");
    scanf("%d", &suma);
    printf("n:\n");
    scanf("%d", &n);
    for(i = 1; i<=n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    back(1);

    return 0;
}