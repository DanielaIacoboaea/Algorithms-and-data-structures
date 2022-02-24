#include <stdio.h>
#include <string.h>

int main()
{
    char x[15] = "dimineata", y[15] = "min";
    char *p;
    int z;
    //x = "dimineata";
    //y = "min";
    strcat(y,x+strlen(x) - 1);
    z = strlen(x);
    printf("z: %d\n", z);
    printf("y: %s\n", y);
    p = strstr(y,x);
    printf("p: %s\n", p);
    if (p != NULL)
    {
        printf("%ld\n", p-y);
    }else
    {
        printf("0\n");
    }
    return 0;
}
