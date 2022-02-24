/* balaur; un balaur cu 6 capete; in prima zi FAT - FRUMOS taie un cap si cresc 6 in loc, a doua zi la fel.. etc 
in n+1 Fat Frumos s-a plictisit si a plecat acasa.
se citeste n; afiseaza cate capete avea balaurul dupa n zile;
ex: n =  3; - balaurul are 15 capete;
*/

#include <stdio.h>

int main()
{
    int n, c = 6, i;
    printf("n: ");
    scanf("%d", &n);
    for (i = 1 ; i < n; i++)
    {
        c = c - 1 + 6;
        printf("i: %d, c: %d\n", i, c);
    }
    printf("in ziua %d, balaurul are %d capete.\n", n, c);
    return 0;
}
