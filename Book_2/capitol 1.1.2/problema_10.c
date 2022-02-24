/* se considera un sir de n cuvinte
identificati multimea cu numar maxim de cuvinte care sunt anagrame intre ele doua cate doua 
se va afisa cardinalul multimii si un cuvant al acesteia, considerat reprezentantul ei
ex: n = 6 si cuvintele "arc", "rac", "voi", "car", "armata", "tamara" se va afisa multimea arc 3
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int anagrams(char a[50], char b[50])
{
    int i, j; 
    char *p = b;
    for (i = 0; i < strlen(a); i++)
    {
        a[i] = toupper(a[i]);
    }
    for (j = 0; j < strlen(b); j++)
    {
        b[j] = toupper(b[j]);
    }
    while (*p != '\0')
    {
        if(strchr(a, *p) != NULL)
        {
            p++;
        }else
        {
            return 0;
        }
    }
    if (*p == '\0')
    {
        return 1;
    }
    return 0;
}

int main()
{
    char a[100][25], x[25], y[25];
    char cuv[25], temp[20];
    int i, j, nr, max = 0, n;
    printf("n: \n");
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        fgets(temp, sizeof(temp), stdin);
        strcpy(a[i], temp);
    }
    /*for (i = 0; i <= n; i++)
    {
        printf("%s", a[i]);
    } */

    for (i = 0; i <= n - 1; i++)
    {
        for (nr = 1, j = i+1; j <= n; j++)
        {
            strcpy(x, a[i]);
            strcpy(y, a[j]);
            if (anagrams(x, y))
            {
                nr++;
            }
        }
        if (max < nr)
        {
            max = nr;
            strcpy(cuv, a[i]);
        }
    }
    printf("%s %d\n", cuv, max);

    return 0;
}
