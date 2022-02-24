#include <stdio.h>

int main()
{
    char a[50] = "Salut";
    char *p = a;
    char **pp = &p;
    
    printf("%s\n", a);
    printf("%c\n", a[3]);
    printf("%p\n", a);

    printf("%s\n", p);
    printf("%c\n", *(p+3));
    printf("%p\n", p);

    printf("%s\n", *pp);
    printf("%c\n", *(*pp+3));
    printf("%p\n", *pp);

    return 0;
}
