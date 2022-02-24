#include <stdio.h>
#include <string.h>

int main()
{
    char a[256] = "abcPertP^&P";
    int n, i; 
    n = strlen(a);
    a[strcspn(a, "P")] = '\n';
    a[strcspn(a, "P")] = '\n';
    a[strcspn(a, "P")] = '\n';
    printf("%s", a);
    return 0;
}

