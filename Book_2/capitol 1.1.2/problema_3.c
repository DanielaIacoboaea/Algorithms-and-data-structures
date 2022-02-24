/* propozitie palindrom: "Ele fac cafele" (fara a se tine cont de minuscule, majuscule si separatori)
sa se verifice daca o prop citita de la tastatura este palindrom
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    char a[256];
    int i, j;
    unsigned int size;
    bool ok = 1;
    printf("Enter paragraph:\n");
    fgets(a, sizeof(a), stdin);
    a[strlen(a)-1] = '\0';
    printf("%s", a);
    size = strlen(a) - 1;
    for (i = 0; i != size; i++)
    {
        printf("i: %d, size: %u\n", i, size);
        printf("a[i]: %c\n", a[i]);
        if (a[i] == ' ')
        {
            i++;
        }
        printf("a[i]: %c\n", a[i]);
        printf("a[size]: %c\n", a[size]);
        if (a[size] == ' ')
        {
            size--;
        }
        printf("a[size]: %c\n", a[size]);
        if (toupper(a[i]) != toupper(a[size]))
        {
            ok = 0;
            printf("\nnu este palindrom\n");
            break;
        }
        size--;
    }
    if (ok)
    {
        printf("\nEste palindrom\n");
    }
    return 0;
}
