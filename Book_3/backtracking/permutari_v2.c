#include <stdio.h>
#include <stdlib.h>

int solutie(int k, int n)
{
    return (k == n+1);
}

void init(int k, int sol[10], int n)
{
    sol[k] = n+1;
}

int succesor(int k, int n, int sol[10])
{
    if(sol[k] > 1)
    {
        sol[k]--;
        return 1;
    }else{
        return 0;
    }
}

int valid(int k, int sol[10])
{
    int i;
    int ev = 1;
    for(i = 1; i<= k-1; i++)
    {
        if(sol[k] == sol[i])
        {
            ev = 0;
        }
    }
    return ev;
}

/*
int valid(int k, int sol[10])
{
    int i;
    int ev = 1;
    for(i = 1; i<= k-1; i++)
    {
        if(sol[k] == sol[i] || abs(sol[k] - sol[k-1]) == 1)
        {
            ev = 0;
        }
    }
    return ev;
}
*/
void print(int n, int sol[10])
{
    int i;
    for (i = 1; i<= n; i++)
    {
        printf("%d ", sol[i]);
    }
    printf("\n");
}

void back(int k, int n, int sol[10])
{
    if(solutie(k, n))
    {
        print(n, sol);
    }else
    {
        init(k, sol, n);
        while(succesor(k, n, sol))
        {
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