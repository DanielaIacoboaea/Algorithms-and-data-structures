#include <stdio.h>

int n, sol[10], i;

void back(int k, int n, char* elevi[6])
{
    if (k == n+1)
    {
        for(i = 1; i<=n; i++)
        {
            if(sol[i] == 1)
            {
                printf("%s ", elevi[i]);
            }
        }
        printf("\n");
    }else{
        sol[k] = -1;
        while(sol[k] < 1)
        {
            sol[k]++;
            back(k+1, n, elevi);
        }
    }
}

int main()
{
    char* elevi[6] = {"Maria", "Ioana", "Andrei", "Vlad", "Casandra", "Bella"};
    back(1, 6, elevi);
    return 0;
}