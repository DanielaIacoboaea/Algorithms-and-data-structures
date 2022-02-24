/* vers dintr-o poezie
sa se identifice cate cuvinte sunt (separate prin " ", "," ".";"")
strtok;
ex "Vremea trece...vremea vine," se va afisa 4
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char a[256];
    char *p;
    int nr;
    printf("vers: \n");
    fgets(a, sizeof(a), stdin);
    nr = 0;
    p = strtok(a, " ,.;");
    printf("p inainte de while: %s\n", p);
    while (p != NULL)
    {
        nr++;
        printf("nr while: %d\n", nr);
        p = strtok(NULL, " ,.;");
        printf("p din while: %s\n", p);
    }
    printf("nr final: %d\n", nr);
    return 0;
}
