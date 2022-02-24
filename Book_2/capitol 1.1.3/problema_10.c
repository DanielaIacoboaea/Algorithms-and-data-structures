/* 2 cuvinte cu litere mici
ultima silaba a unui cuvant este subsirul care incepe cu ultima lui vocala
verificati daca aceste cuvinte rimeaza (daca au ultima silaba identica)
daca un cuvant nu contine vocale, atunci ultima lui silaba este intregul cuvant
ex: armat si verificat se va afisa cuvantul "Rimeaza"
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int vowel(char x)
{
    int i; 
    char a[256] = {'a','e','i','o','u'};
    for (i = 0; i < strlen(a); i++)
    {
        if (x == a[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char a[256], b[256], vow_a[256], vow_b[256];
    int i, j;
    bool ok_a = 1;
    bool ok_b = 1;
    printf("a:\n");
    fgets(a, sizeof(a), stdin);
    printf("b:\n");
    fgets(b, sizeof(b), stdin);
    for (i = strlen(a) - 1; i >= 0; i--)
    {
        if (vowel(a[i]))
        {
            strcpy(vow_a, a+i);
            ok_a = 0;
            break;
        }
    }
    if (ok_a)
    {
        strcpy(vow_a, a);
    }
    for (j = strlen(b) - 1; j >= 0; j--)
    {
        if (vowel(b[j]))
        {
            strcpy(vow_b, b+j);
            ok_b = 0;
            break;
        }
    }
    if (ok_b)
    {
        strcpy(vow_b, b);
    }
    printf("vow_a: %s\n", vow_a);
    printf("vow_b: %s\n", vow_b);
    if (strcmp(vow_a, vow_b) == 0)
    {
        printf("Rimeaza!\n");
    }else
    {
        printf("Nu rimeaza!\n");
    }
    return 0;
}
