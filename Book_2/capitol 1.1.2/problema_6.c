/* se considere 2 cuveinte formate din litere mici si mare ale alfabetului englez
verificati daca ele sunt anagrame
ex: :are si era
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char a[20], b[20];
    char *p = b;
    int i, j; 
    printf("Enter a: \n");
    fgets(a, sizeof(a), stdin);
    printf("Enter b: \n");
    fgets(b, sizeof(b), stdin);
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
            printf("Numerele nu sunt anagrame\n");
            break;
        }
    }
    if (*p == '\0')
    {
        printf("Numerele sunt anagrame\n");
    }
    return 0;
}
