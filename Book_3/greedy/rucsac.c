#include <stdio.h>

typedef struct rucsac{
    int castig, greutate, eficienta;

} rucsac;

void sorteaza(rucsac obiecte[15], int n)
{
    rucsac temp;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if(obiecte[j].eficienta > obiecte[j-1].eficienta)
            {
                temp = obiecte[j];
                obiecte[j] = obiecte[j-1];
                obiecte[j-1] = temp;
            }
        }
    }
}

int main()
{
    int n, i, castig_total = 0, ef;
    float g_rucsac = 0.0;
    rucsac obiecte[15];
    rucsac temp;

    printf("greutate rucsac:\n");
    scanf("%f", &g_rucsac);
    printf("numar obiecte n: \n");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("castig obiect %d:\n", i);
        scanf("%d", &obiecte[i].castig);
        printf("greutate obiect %d:\n", i);
        scanf("%d", &obiecte[i].greutate);
        ef = obiecte[i].castig/obiecte[i].greutate;
        obiecte[i].eficienta = ef;
    }

    sorteaza(obiecte, n);

    i = 0;
    while (g_rucsac > 0 && i < n)
    {
        if(g_rucsac > obiecte[i].greutate)
        {
            g_rucsac = g_rucsac - obiecte[i].greutate;
            printf("1 obiectul %d\n", i);
            castig_total = castig_total + obiecte[i].castig;
        }else
        {
            printf("%.2f din obiectul %d\n", g_rucsac/obiecte[i].greutate, i);
            castig_total = castig_total + obiecte[i].castig*g_rucsac/obiecte[i].greutate;
            g_rucsac = 0;
        }
        i++;
    }
    printf("\n castig total: %d\n", castig_total);
    return 0;
}