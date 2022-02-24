#include <stdio.h>

void sorteaza(int s[2][15], int o[15], int n)
{
    int gata, i, temp;

    do{
        gata = 1;
        for(i = 0; i < n; i++)
        {
            if(s[1][o[i]] > s[1][o[i+1]])
            {
                temp = o[i];
                o[i] = o[i+1];
                o[i+1] = temp;
                gata = 0;
            }
        }
    }while (!gata);
}


int main()
{
    int n, h1, h2, m1, m2, i, ora;
    int o[15];
    int s[2][15];

    printf("n: \n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
       o[i] = i;
    }

    for(i = 0; i < n; i++)
    {
        printf("h1,m1 pentru %d\n", i);
        scanf("%d,%d", &h1, &m1);
        s[0][i] =  h1*60 + m1;
        printf("s[0][i]: %d\n", s[0][i]);
        printf("h2,m2 pentru %d\n", i);
        scanf("%d,%d", &h2, &m2);
        s[1][i] = h2*60 + m2;
        printf("s[1][i]: %d\n", s[1][i]);
    }

    sorteaza(s, o, n);

    ora = s[1][o[0]];

    printf("spectacol nr %d ", o[0]);

    for (i = 1; i <= n; i++)
    {
        if (s[0][o[i]] >= ora)
        {
            printf("spectacol nr %d ", o[i]);
            ora = s[1][o[i]];
        }
    }
    
    return 0;
}