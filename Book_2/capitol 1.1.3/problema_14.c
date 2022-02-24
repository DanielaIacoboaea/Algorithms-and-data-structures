/* find replace
subsirul s1 se inlocuieste cu subsirul s2 
ex : are mere si pere; s1 = 're si s2 = 'rare se va afisa: arare merare si perare
*/

#include <stdio.h>
#include <string.h>


int main()
{
    char s[256], s1[256], s2[256], c[256] = "\0";
    int p;
    printf("enter string: \n");
    fgets(s, sizeof(s), stdin);
    printf("enter string to find: \n");
    fgets(s1, sizeof(s1), stdin);
    printf("enter replacement: \n");
    fgets(s2, sizeof(s2), stdin);
    s1[strlen(s1)-1] = '\0';
    s2[strlen(s2)-1] = '\0';

    while ((p = strstr(s, s1)-s) >= 0)
    {
        printf("p: %d\n", p);
        strncat(c, s, p-1);
        //printf("strncat c,s,p: %s\n", strncat(c, s, p));

        strcpy(s+p, s+p+strlen(s1)-1);
        //printf("strcpy s+p, s+p+strlens1: %s\n", strcpy(s+p, s+p+strlen(s1)-1));

        strcpy(s, s+p);
        //printf("strcpy s, s+p: %s\n", strcpy(s, s+p));

        strcat(c, s2);
        printf("%s", strcat(c, s2));
    }
    return 0;
}
