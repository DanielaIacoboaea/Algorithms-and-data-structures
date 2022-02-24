#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char a[256], b[256];
    int i, j, k, l;
    printf("a: \n");
    scanf("%s", a);
    printf("b: \n");
    scanf("%s", b);

    bool a_idx[256], b_idx[256];
    for (i = 0; i < 127; i++)
    {
        a_idx[i] = 0;
    }
    for (i = 0; i < 127; i++)
    {
        b_idx[i] = 0;
    }
    for (i = 0; i < strlen(a); i++)
    {
        a_idx[(int)a[i]] = 1;
    }
    for (i = 0; i < strlen(b); i++)
    {
        b_idx[(int)b[i]] = 1;
    }
    printf("Intersectie a & b:\n");
    printf("{");
    for (i = 0; i < 127; i++)
    {
        if ((a_idx[i] == 1) && (b_idx[i] ==1))
        {
            printf("%c ", i);
        }
    }
    printf("}\n");

    printf("Reuniune a & b:\n");
    printf("{");
    for (i = 0; i < 127; i++)
    {
        if ((a_idx[i] == 1) || (b_idx[i] == 1))
        {
            printf("%c ", i);
        }
    }
    printf("}\n");
    printf("Elemente din a - b:\n");
    printf("{");
    for (i = 0; i < 127; i++)
    {
        if ((a_idx[i] == 1) && (b_idx[i] == 0))
        {
            printf("%c ", i);
        }
    }
    printf("}\n");
    return 0;
}
