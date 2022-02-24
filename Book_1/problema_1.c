/* pomi - sir n < 100.000; copilul se ascunde din min in min. daca nr div cu 6 sau are ultima cifra 7 se schimba sensul de deplasare; daca depaseste n = 10 -> stop; k = 20 - printeaza pomul la 20 ex: n =  10; k= 20; pom 4;

min | pom
1   | 1
2   | 2
3   | 3
4   | 4
5   | 5
6   | 6
7   | 5
8   | 6
9   | 7
10  | 8
11  | 9
12  | 10
13  | 9
14  | 8
15  | 7
16  | 6
17  | 5
18  | 6
19  | 5
20  | 4
*/

#include <stdio.h>

int main()
{
    int n, k, min, tree = 1, i, poz = 0, sens = 1;
    printf("n: ");
    scanf("%d", &n);
    printf("k: ");
    scanf("%d", &k);
    
    for (i = 1; i <= k && poz <= n; i++)
    {
        printf("min: %d\n", i);
        poz = poz + sens;
        printf("tree: %d\n", poz);
        if ((i % 6 == 0) || (i % 10 == 7))
        {
            sens = sens * (-1);

            printf("tree din if: %d\n", sens);
        }
    }
    printf(" tree no: %d\n", poz);

    return 0;
}
