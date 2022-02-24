/* date.in
4 12 3
23128 4 12 1969
21398 23 1 1970
12301 21 4 1970
54312 11 3 1970
se va afisa
12301 21 4
23128 4 12
*/

#include <stdio.h>

typedef struct elev{
    int nr_matricol, zi, luna, an;
}elev;

int main()
{
    FILE *f;
    f = fopen("date.txt", "r");
    int count = 0, n, zi_curenta, luna_curenta, j, i;
    elev s[50], aux;
    printf("n, zi_curenta, luna_curenta\n");
    scanf("%d,%d,%d", &n, &zi_curenta, &luna_curenta);
    while (!feof(f))
    {
        fscanf(f, "%d %d %d %d", &s[count].nr_matricol, &s[count].zi, &s[count].luna, &s[count].an);
        count++;
    }
    for (i = 0; i < count; i++)
    {
        for (j = n-1; j > i; j--)
        {
            if (s[j].luna < s[j-1].luna)
            {
                aux = s[j];
                s[j] = s[j-1];
                s[j-1] = aux;
            }
        }
    }
    for (i = 0; i < count-1; i++)
    {
        if (s[i].luna > luna_curenta)
        {
            printf("%d %d %d\n", s[i].nr_matricol, s[i].zi, s[i].luna);
        }else if (s[i].luna == luna_curenta && s[i].zi >= zi_curenta)
        {
            printf("%d %d %d\n", s[i].nr_matricol, s[i].zi, s[i].luna);
        }
    }
    fclose(f);
    return 0;
}
