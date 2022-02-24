/* n = 3    se va afisa
07BA023     281
AABBAB      BBAB
A07BA023    283
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int s = 0, n, i, j, p = 0, pr, ok;
    char x[256];
    char a[11][256];
    printf("n:\n");
    scanf("%d", &n);
    ok = 1;
    i = 0;
    do
    {
        scanf("%s", x);
        for (j = 0; j < strlen(x); j++)
        {
            if (x[j] > x[p])
            {
                p = j;
            }
        }
        strcpy(x, x+p);
        p = 1;
        printf("a[i]: %s\n", a[i]);
        for (j = 0; j < i; j++)
        {
            printf("strcmp a[j], x: %d\n", strcmp(a[j], x));
            if (!strcmp(a[j], x))
            {
                p = 0;
            }
        }
        printf("p: %d\n", p);
        if (p == 0)
        {
            memset(a[i], 0, sizeof(a[i]));
        }else
        {
            if(ok)
            {
                pr = i;
                ok = 0;
                strcpy(a[i], x);
            }
        }
        printf("a[i] dupa if ok: %s\n", a[i]);
        for (i = 0; i < strlen(a[pr]); i++)
        {
            s+=a[pr][i];
        }
        for(i = 0; i <n; i++)
        {
            if(!strlen(a[i]) || i == pr)
            {
                printf("%d \n", s+i+1);
            }else
            {
                printf("%s\n", a[i]);
            }
        }
        printf("x: %s\n", x);
        i++;
    }while (i < n);
    return 0;
}
