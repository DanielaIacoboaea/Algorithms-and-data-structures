#include <stdio.h>

int n;

int Ok(char a[256], char b[256])
{
    int p;
    char c[256];
    strcpy(c,b);
    if (strlen(a) == 0)
    {
        return 1;
    }
    p = strchr(c, a[0]) - c;
    if (p < strlen(c))
    {
        strcpy (c+p, c+p+1);
        strcpy(a, a+1);
        return Ok(a,c);
    }
    else{
        return 0;
    }
}

void nr (int i, int *m, char y[256])
{
    char x[256];
    if (i == n)
    {
        printf("y: ");
        scanf("%s", y);
    }else
    {
        printf("x: ");
        scanf("%s", x);
        nr(i+1, m, y);
        if (Ok(x,y))
        {
            m++;
        }
    }
}

int main()
{
    int number = 0;
    printf("n: ");
    scanf("%d", &n)
    return 0;
}
