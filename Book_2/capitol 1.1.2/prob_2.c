#include <stdio.h>
#include <string.h>

int main()
{
    char vers[256], s[256];
    int nr = 0, p, l;
    printf("Enter paragraph:\n");
    fgets(vers, sizeof(vers), stdin);
    printf("Enter syllable:\n");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    while (strstr(vers, s) != NULL)
    {
        printf("strstr(vers,s): %s\n", strstr(vers,s));
        p = strstr(vers, s) - vers;
        printf("ciudatenie: %s, %s", strstr(vers, s), vers);
        printf("p: %d\n", p);
        l = strlen(s);
        printf("l: %d\n", l);
        strcpy(vers+p, vers+p+1);
        printf("strcpy: %s\n", strcpy(vers+p, vers+p+1));
        nr++;
        printf("nr: ");
    }
    printf("%d\n", nr);
    return 0;
}
