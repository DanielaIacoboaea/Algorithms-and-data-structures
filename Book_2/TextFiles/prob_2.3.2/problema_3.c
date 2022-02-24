/* in fisierul text in.txt exista dispuse pe fiecare linie cate un numar din sirul numerelor 
primelor n (n<30000) numere naturale nenule. exceptie face un singur numar care a fost omis 
realizati un program care det nr lipsa 
ex:
in.txt
2 
4
5
1
se va afisa: 3
*/

#include <stdio.h>

int main()
{
    FILE *f;
    int count = 0, sum = 0, x, number;
    f = fopen("in.txt", "r");
    while (!feof(f))
    {
        fscanf(f,"%d\n", &x);
        sum = sum + x;
        printf("x: %d, sum: %d\n", x, sum);
        count++;
        printf("count: %d\n", count);
    }
    printf("sum: %d\n", sum);
    number = ((count+1) * (count + 2)/2) - sum;
    printf("nr lipsa: %d\n", number);
    fclose(f);
    return 0;
}
