/* se citeste de la tastatura un vers al unei poezii si o silaba
sa se realizeze un program care det numarul de aparitii al silabei respective in text
ex: pt versul "Un curcubeu multicolor" si silaba "cu" se va afisa 2;
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int nr = 0, i, p, l;
    char v[256], s[256];
    char *res;
    printf("Enter paragraph:\n");
    fgets(v, sizeof(v), stdin);
    printf("Enter syllable:\n");
    fgets(s, sizeof(s), stdin);
    printf("%s", v);
    s[strcspn(s, "\n")] = '\0';
    res = strstr(v, s);
    while (res != NULL)
    {
        nr++;
    }
    res = strstr(v, s);
    printf("%s", res);
    /*if(res != NULL)
    {
        nr++;
    }*/
    /*while (strstr(v, s) != NULL)
    {
        p = strchr(v, s) - v;
        l = strlen(s);
        strcpy(v+p, v+p+l);
        nr++;
    }*/
    printf("nr: %d\n", nr);
    return 0;
}
