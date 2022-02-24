#include <stdio.h>
#include <string.h>

int main()
{
    char a[15] = "Am trei peri";
    char b[15] = "Am doi2 peri"; 
    char c[15] = "Am trei gugustiuci";
    int i;
    printf("%s", a);
    printf("\n");
    for (i = 0; i < strlen(a); i++)
    {
        a[i] = b[i];
    }
    printf("%s", a);
    return 0;
}
