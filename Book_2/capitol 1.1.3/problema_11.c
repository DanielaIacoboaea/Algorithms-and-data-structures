/* numarul de aparitii <= 20
ex: 1G11o1L se va afisa GoooooooooooL;
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
       if ((code[i] >= '0' && code[i] <= '9') && ((code[i+1] >='a' && code[i+1] <= 'z') || (code[i+1] >='A' && code[i+1] <= 'Z')))
        {
            loop = code[i] - '0';
            for (j = 0; j < loop; j++)
            {
                printf("%c", code[i+1]);
            }
        }else if ((code[i] >= '0' && code[i] <= '9') && (code[i+1] >= '0' && code[i+1] <= '9'))
        {
            loop = (code[i] - '0') * 10 + (code[i+1] - '0');
            for (j = 0; j < loop; j++)
            {
                printf("%c", code[i+2]);
            }
        }
    }
    return 0;
}

