#include <stdio.h>
#include <string.h>

int main()
{
    char a[10] = "Primavara";
    int i;
    for (i = 1; i <= 3; i++)
    {
        strcpy(a+1, a+2);
        printf("%s", a+1);
        printf("%s", a);
        printf("\n");
    }
    printf("%s", a);
    return 0;
}
