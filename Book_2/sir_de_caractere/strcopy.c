#include <stdio.h>
#include <string.h>

int main()
{
    char s[15] = "Ana are mere";
    int i, l;
    l = strlen(s);
    //printf("l: %d\n", l);
    strcpy(s, s+1);
    strcpy(s+strlen(s) - 1, s+strlen(s));
    l = strlen(s);
    printf("l: %d\n", l);
    printf("%s\n", s);
    return 0;
}
