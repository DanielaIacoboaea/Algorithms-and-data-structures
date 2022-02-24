#include <stdio.h>
#include <stdlib.h>

int valid(int k, int sol[10])
{
    int i;
    int ev = 1;
    for(i = 1; i<= k-1; i++)
    {
        if((sol[k] == sol[i]) || (abs(sol[k] - sol[i]) == abs(k-i)))
        {
            ev = 0;
        }
    }
    return ev;
}

void back(int k, int n, int sol[10])
{
    int i;

    if(k == n+1)
    {
        for (i = 1; i<= n; i++)
        {
            printf("%d ", sol[i]);
        }
        printf("\n");  
        exit(0);
    }else
    {
        for(i = 1; i<= n; i++)
        {
            sol[k] = i;
            if(valid(k, sol))
            {
                back(k+1, n, sol);
            }
        }
    }
}

int main()
{
    int n;
    int sol[10];
    printf("n: \n");
    scanf("%d", &n);

    back(1, n, sol);
    return 0;
}