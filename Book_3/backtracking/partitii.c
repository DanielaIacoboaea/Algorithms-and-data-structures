#include <stdio.h>

int sol[100], n, i, s=0;

void back(int k)
{
    //printf("k: %d, s=%d\n", k, s);
    if(s==n)
    {
        for(i=1; i<=k-1; i++)
        {
            printf("%d ", sol[i]);
        }
        printf("\n");
    }else{
        sol[k] = 0;
        while(sol[k]+s<n)
        {
            sol[k]++;
            s+=sol[k];
            //printf("k inainte de back(k+1): %d, s inainte de back(k+1): %d\n", k, s);
            back(k+1);
            //printf("k dupa back(k+1): %d, s dupa back(k+1): %d\n", k, s);
            s-=sol[k];
            //printf("s dupa s-sol[k]: %d\n", s);
        }
    }
}

int main()
{
    printf("n:\n");
    scanf("%d", &n);
    back(1);
    return 0;
}