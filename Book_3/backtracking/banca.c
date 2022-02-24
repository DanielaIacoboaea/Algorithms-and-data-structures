#include <stdio.h>
#include <string.h>


int valid(int k, int n, int sol[4], char* names[4])
{
    int i, ev = 1;

    for (i = 1; i<= k-1; i++)
    {
        k = sol[k];
        printf("k: %d\n", k);
        printf("%s, %s\n", names[k], names[i]);
        if(strcmp(names[k], names[i]) == 0)
        {
            ev = 0;
            printf("ev: %d\n", ev);
        }
    }
    return ev;
}

void back(int k, int n, int sol[4], char* names[4])
{
    int i;
    if(k == n+1)
    {
        printf("aaaaa\n");
        for(i = 1; i<= n; i++)
        {
            printf("%s ", names[i]);
        }
        printf("\n");
    }else{
        for(i = 1; i <= n; i++)
        {
            sol[k] = i;
            printf("sol[k]: %d\n", sol[k]);
            if(valid(k, n, sol, names))
            {
                back(k+1, n, sol, names);
            }
        }
    }
}

int main()
{
    char* names[] = {"Ioana", "Costel", "Mihaela"};

    int sol[4];

    back(1, 3, sol, names);
    return 0;
}