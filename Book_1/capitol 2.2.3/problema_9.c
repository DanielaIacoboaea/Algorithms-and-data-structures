/* la un concurs de patinaj ce contine m probe, participa n sportivi identificati prin numere de la 1 la n (n, m < 100)
sa se afiseze nr de ordine ale sportivilor ce au obtinut cele mai mari 3 punctaje totale
punctajele introduse de la tastatura in ordinea numerelor de concurs. nota maxima a unei probe este 10
ex: n = 5, m = 3 si punctajele 
5 2 3
5 5 5
1 0 1
7 8 9
4 4 2
se va afisa
premiul 1: 4;
premiul 2: 2;
premiul 3: 1, 5;
*/

#include <stdio.h>

typedef struct playerPoints
{
    int line;
    int sum;
} playerPoints;

int main()
{
    int i, j, n, m, sum, up_to;
    int a[15][15];
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    playerPoints players[15];
    playerPoints aux;
    for (i = 1; i <= n; i++)
    {
        sum = 0;
        for (j = 1; j <= m; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
            sum = sum + a[i][j];
        }
        players[i].line = i;
        players[i].sum = sum;
    }
    for (i = 1; i <= n; i++)
    {
        printf("jucatorul %d are un total de %d puncte\n", players[i].line, players[i].sum);
    }
    for (i = 1; i <= n; i++)
    {
        for (j = n; j > i; j--)
        {
            if (players[j].sum > players[j-1].sum)
            {
                aux = players[j];
                players[j] = players[j-1];
                players[j-1] = aux;
                /*
                aux = players[j].sum;
                players[j].sum = players[j-1].sum;
                players[j-1].sum = aux;
                
                aux = players[j].line;
                players[j].line = players[j-1].line;
                players[j-1].line = aux;
                */
            }
        }
    }
    up_to = 3;
    for (i = 1; i <= up_to; i++)
    {
        if (players[i].sum == players[i+1].sum)
        {
            printf("Premiul %d: jucatorii %d si %d cu %d puncte\n", i, players[i].line, players[i+1].line, players[i].sum);
            up_to++;
            i++;
        }else
        {
            printf("Premiul %d: jucatorul %d cu %d puncte\n", i, players[i].line, players[i].sum);
        }
    }
    return 0;
}
