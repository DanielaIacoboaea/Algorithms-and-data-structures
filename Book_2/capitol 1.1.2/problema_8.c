/* se citeste de la tastatura un sir de caractere 
identificati in cadrul acestuia o secventa de lungime maxima care poate fi convertita catre o variabila de tip intreg
ex: "25AB32042Xs23" se va afisa 32042
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char a[50];
    int lung = 0, max = 0, poz, i;
    printf("a: \n");
    fgets(a, sizeof(a), stdin);
    //strcat(a, " ");

    for (i = 0; i < strlen(a); i++)
    {
        if(a[i] >= '0' && a[i] <= '9')
        {
            lung++;
        }else if (max < lung)
            {
                max = lung;
                poz = i - lung;
                lung = 0;
            }
    }
    for (i = poz; i <poz+max; i++)
    {
        printf("%c", a[i]);
    }
    printf("\n");
    /*
    while (a[i] != '\0')
    {
        count = 1;
        if (a[i] >= '0' && a[i] <= '9')
        {
            for (j = i+1; j < strlen(a); j++)
            {
                if(a[j] >= '0' && a[j] <= '9')
                {
                    count++;
                }else
                {
                    break;
                }
            }
        if (count > length_max)
        {
            length_max = count;
            printf("length_max %d\n", length_max);
            s = i; 
            printf("s: %d\n", s);
            f = i+length_max;
            printf("f: %d\n", s);
        }
        }
        i++;
    }
    for (i = s; i < j; i++)
    {
        printf("%c", a[i]);
    }
    printf("\n"); */
    return 0;
}
