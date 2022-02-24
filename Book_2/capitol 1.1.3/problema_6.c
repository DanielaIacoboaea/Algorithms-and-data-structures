/* se considera un sir de n cuvinte
sa se det cuvantul de lungime maxima care se poate forma prin concatenarea a doua dintre cuvintele citite
ex: pt n = 5: "mama", "arc", "conduce", "paine", "vine", se va afisa
"conducepaine" sau "paineconduce";
*/

#include <stdio.h>
#include <string.h>

int str_length(char x[256], char y[256])
{
    int sum;
    sum = strlen(x) + strlen(y);
    return sum;
}

int main()
{
    int n, max = 0, l, i, j;
    char a[256][256];
    char word[257], final[256];
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            strcpy(word, a[i]);
            printf("word_strcpy: %s\n", word);
            strcat(word, a[j]);
            printf("word_strcat: %s\n", word);
            l = strlen(word);
            if (l > max)
            {
                max = l;
                strcpy(final, word);
                printf("final if: %s\n", final);
            }
        }
    }
    printf("max: %d\n", max);
    printf("%s\n", final);
    return 0;
}
