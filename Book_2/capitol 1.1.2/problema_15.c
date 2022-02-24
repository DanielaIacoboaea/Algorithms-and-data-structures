/* se citeste de la tastatura un sir de maximum 255 litere mici ale alfabetului englez
sa se realizeze un program care identifica cea mai lunga secventa de caractere care se repeta de minim 2 ori in cadrul sirului 
ex: "masectrsecacrrr" se va afisa "sec"
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char s[256], r[256], x[256], y[256];
    int i, max = 0, l;
    printf("enter string:\n");
    fgets(s, sizeof(s), stdin);
    for (i = 0; i +1 <strlen(s); i++)
    {
        l = 0;
        memset(x, 0, sizeof(x));
        do
        {
            strncat(x, s+i+1, 1);
            l++;
            strcpy(y,s);
            strcpy(y+i, y+i+strlen(x));

        }while (i+1 < strlen(s) && strstr(y,x));
        if (max < strlen(x) - 1)
        {
            max = strlen(x) - 1;
            strncpy(r, x, max);
        }
    }
    printf("%s", r);
    
    return 0;
}
