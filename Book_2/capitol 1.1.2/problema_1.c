/* se considera un text in care singurul separator este spatiul
stiind ca intre oricare 2 cuvinte pot exista mai multi separatori, sa se det numarul de cuvinte din text
ex: "Am venit  repede" se va afisa 3;
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char s[256];
    int nr, i;
    printf("Enter paragraph:\n");
    fgets(s, sizeof(s), stdin);
    printf("%s\n", s);
    strcat(s, " ");
    nr = 0;
    for (i = 0; i+1 < strlen(s); i++)
    {
        if(s[i] != ' ' && s[i+1] == ' ')
        {
            nr++;
        }
    }
    printf("numarul de cuvinte: %d \n", nr);
    return 0;
}
