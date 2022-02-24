/* 1, 12, 123, 1234, 12345678910..., 
ex n = 5, se va afisa 4
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, d = 0, number;
    printf("n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        number = number * 10 + i;
        if (number % 3 == 0)
        {
            printf("nr: %d", number);
            d++;
        }
    }
    printf("numere divizibile cu 3: %d", d);
    
    return 0;
}
