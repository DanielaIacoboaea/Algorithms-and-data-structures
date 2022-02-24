#include <stdio.h>
#include <string.h>

int n;

char *V(char s[256])
{
    char t[256] = {0};
    if (strlen(s) == 0)
    {
        return s;
    }else
    {
        strcpy(t, V(s+1));
        t[strlen(t)] = s[0];
        return t;
    }
}

void M(int i)
{
    char s[256];
    if (i <= n)
    {
        printf("s: ");
        scanf("%s", s);
        M(i+1);
        printf("%s ", V(s));
    }
}

int main()
{
    printf("n: ");
    scanf("%d", &n);
    return 0;
}
