/* se citeste de la tastatura un text codificat dupa regula urmatoare 
in fata fiecarui caracter apare numarul de aparitii
sa se decodifice textul
ex: "1c101p3i" se va afisa: textul "copiii"
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char code[25];
    printf("code: \n");
    fgets(code, sizeof(code), stdin);
    int i, j = 0, loop = 0;
    for (i = 0; i < strlen(code); i++)
    {
       if (code[i] >= '0' && code[i] <= '9')
        {
            loop = code[i] - '0';
            for (j = 0; j < loop; j++)
            {
                printf("%c", code[i+1]);
            }
        }
    }
    return 0;
}
