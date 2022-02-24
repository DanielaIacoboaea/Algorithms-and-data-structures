/* se considera un cuvant format din din litere mici si mari
sa se scrie un program care afiseaza cuvintele obtinute din cuvantul initial prin eliminarea succesiva 
a primului si ultimului caracter din sir
ex: "Deosebit" se va afisa:
eosebi
oseb
se
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char cuv[256];
    int i;
    printf("enter word:\n");
    fgets(cuv, sizeof(cuv), stdin);
    
    while (strlen(cuv) > 1)
    {
        strcpy(cuv, cuv+1);
        cuv[strlen(cuv) -1] = 0;
        printf("%s\n", cuv);
    }
    return 0;
}
