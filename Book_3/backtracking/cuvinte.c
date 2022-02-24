#include <stdio.h>

void init(int k, char sol[5], char vowels[5], char second_letter[4], char third_letter[5])
{
    if(k == 1)
    {
        sol[k] = vowels[1];
    }else if(k == 2)
    {
        sol[k] = second_letter[1];
    }else if(k == 3)
    {
        sol[k] = third_letter[1];
    }else if(k == 4)
    {
        sol[k] = vowels[1];
    }
}

int succesor(int k, int n, char sol[5], )
{
    if(sol[k] < n)
    {
        sol[k]++;
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

void back(int k, int n, int sol[10])
{
    int i;
    if(k == n+1)
    {
        for(i = 1; i<=n; i++)
        {
            printf("%c ", sol[i]);
        }
        printf("\n");
    }else
    {
        init(k, sol);
        while(succesor(k, n, sol))
        {
            if(valid(k, sol))
            {
                back(k+1, n, sol);
            }
        }
    }
}


void back(int k, int n, char sol[4], char vowels[5], char second_letter[4], char third_letter[5])
{
    int i;
    if(k == n+1)
    {
        for(i = 1; i<=n; i++)
        {
            printf("%c ", sol[i]);
        }
        printf("\n");
    }else
    {
        init(k, sol);

    }


    {
        for(i = 1; i<=n; i++)
        {
            for(j = 1; j <= 5; j++)
            {
                sol[k] = vowels[j];
                for(l = 1; l<= 4; l++)
                {
                    sol[k+1] = second_letter[l];
                    for(m = 1; m<= 5; m++)
                    {
                        sol[k+2] = third_letter(m);
                        back(k+1, n, sol, vowels, second_letter, third_letter);
                    }
                }

            }
        }
    }
}


int main()
{
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char sol[4];
    char second_letter[] = {'P', 'R', 'S', 'T'};
    char third_letter[] = {'B', 'M', 'R', 'T', 'V'};

    return 0;
}