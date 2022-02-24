#include <stdio.h>

int n, sol[10], a[10], i;

void back(int k)
{
    if(k == n+1)
    {
        for(i = 1; i<= n; i++)
        {
            printf("%d ", sol[i]);
        }
        printf("\n");
    }else{
        sol[k] = 0;
        while(sol[k] < a[k])
        {
            sol[k]++;
            back(k+1);
        }
    }
}

int main()
{
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