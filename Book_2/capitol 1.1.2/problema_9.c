/* find & replace asupra unui text
2 subsiruri ex: "ca" si "ta"
sirul "care caracatita" devine "tare taratatita"
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char a[256];
    char find[20];
    char replace[20];
    char final[256];
    int u = 0, i, p;
    char *pt;
    
    printf("enter string: \n");
    fgets(a, sizeof(a), stdin);
    printf("enter char to find: \n");
    fgets(find, sizeof(find), stdin);
    printf("enter char to replace with: \n");
    fgets(replace, sizeof(replace), stdin);
    
    do
    {
        pt = strstr(a, find);
        if (!pt)
        {
            for (i = u; i < strlen(a); i++)
            {
                strncat(final, a+i, 1);
                break;
            }
        }
        p = pt - a;
        for (i = u; i < p; i++)
        {
            final[i] = a[i];
        }
        for (i = p; i <p+strlen(replace); i++)
        {
            a[i] = '!';
        }
        for (i = p; i < p+strlen(replace); i++)
        {
            strncat(final, replace+i-p, 1);
        }
        u = p + strlen(find);
    }while (1);
    printf("%s\n", final);
    return 0;
}
