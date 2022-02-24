/* text in care spatiul este singurul separator
realizati un program care afiseaza numerele ce apar despartite prin cate un spatiu
de ex: Ana are 7 mere si 223 de pere se va afisa 7 223
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char a[256];
    char *p;
    printf("enter string:\n");
    fgets(a, sizeof(a), stdin);
    p = strtok(a, " ");
    while (p != NULL)
    {
        p = strtok(NULL, " ");
        if (p != NULL)
        {
            if (isdigit(p[0]))
            {
                printf("%s ", p);
            }
        }
    }
    return 0;
}
