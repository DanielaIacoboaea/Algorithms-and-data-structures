#include <stdio.h>

int n, sol[10], i;

void back(int k)
{
    if (k == n+1)
    {
        for(i = 1; i<=n; i++)
        {
            if(sol[i] == 1)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }else{
        sol[k] = -1;
        while(sol[k] < 1)
        {
            sol[k]++;
            back(k+1);
        }
    }
}

int main()
{
    printf("n: ");
    scanf("%d", &n);
    back(1);
    return 0;
}