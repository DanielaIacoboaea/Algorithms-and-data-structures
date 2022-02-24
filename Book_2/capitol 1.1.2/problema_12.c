/* un cuvant de maxim 50 de caractere
se cere inserarea minisculei minime intre  2 litere alaturate identice 
la inserare nu se face distinctie intre majuscule si minuscule
daca nu exista minuscule, nu va suferi nicio modificare 
ex: "inNorat" minucula minima este "a" si se va afisa "inaNorat"
"boOlutton" (minuscula minima este b) si se va afisa "bobOlutbton"
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char minuscula(char x[50])
{
    int i;
    char min;
    if (x[0] >= 'a' && x[0] <='z')
    {
        min = x[0];
    }else
    {
        min = 'z';
    }
    for (i = 0; i < strlen(x); i++)
    {
        if (x[i] < min && (x[i] >= 'a' && x[i] <= 'z'))
        {
            min = x[i];
        }
    }
    return min;
}
int majuscule(char x[50])
{
    int i;
    for (i = 0; i < strlen(x); i++)
    {
        if (x[i] >= 'a' && x[i] <= 'z')
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char a[50], temp [50];
    char m;
    int i;
    printf("enter string:\n");
    fgets(a, sizeof(a), stdin);
    if (majuscule(a))
    {
        printf("Stringul contine numai majuscule, nu s-a efectuat nicio operatie\n");
    }else
    {
        m = minuscula(a);
        printf("Cea mai mica minuscula din sir este: %c\n", m);
    }
    for (i = 0; i < strlen(a); i++)
    {
        if (toupper(a[i]) == toupper(a[i+1]))
        {
            strcpy(temp, a+i+1);
            a[i+1] = m;
            strcpy(a+i+2, temp);
        }
    }
    printf("%s\n", a);
    return 0;
}
