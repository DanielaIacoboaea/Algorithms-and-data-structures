/* 2 cuvinte de la tastatura doar din litere minuscule 
-intersectia
-reuniunea
-elementele din primul cuvant care nu apar in al doilea

ex: "mamaie" si "macara" se va afisa:
{m,a}
{m,a,i,e,r,c}
{i,e}
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char a[256], b[256], common[256] = "\0", reunion[256] = "\0", solo[256] = "\0";
    int i, j;
    char ch;
    printf("enter a: \n");
    scanf("%s", a);
    printf("enter b: \n");
    scanf("%s", b);

    j = 0;
    for (i = 0; i < strlen(a); i++)
    {
        ch = a[i];
        if (strchr(b, ch) != NULL)
        {
            if (strchr(common, ch) == NULL)
            {
                common[j] = ch;
                j++;
            }
        }
    }
    printf("{");
    for (i = 0; i < strlen(common); i++)
    {
        printf("%c,", common[i]);
    }
    printf("}\n");
    j = 0;
    for (i = 0; i <strlen(a); i++)
    {
        ch = a[i];
        if (strchr(reunion, ch) == NULL)
        {
            reunion[j] = ch;
            j++;
        }
    }

    for (i = 0; i <strlen(b); i++)
    {
        ch = b[i];
        if (strchr(reunion, ch) == NULL)
        {
            reunion[j] = ch;
            j++;
        }
    }
    
    printf("{");
    for (j = 0; j < strlen(reunion); j++)
    {
        printf("%c,", reunion[j]);
    }
    printf("}\n");

    j = 0;
    for (i = 0; i <strlen(a); i++)
    {
        ch = a[i];
        if (strchr(b, ch) == NULL)
        {
            solo[j] = ch;
            j++;
        }
    }
    
    printf("{");
    for (j = 0; j < strlen(solo); j++)
    {
        printf("%c,", solo[j]);
    }
    printf("}\n");

    return 0;
}
