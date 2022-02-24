/* fiind dat un numar natural de maxim 9 cifre sa se det intre care dintre cifre se poate plasa operatorul 
de inmultire astfel incat produsul celor doua numere obtinute sa fie maxim
ex: pt 3203 se va afisa 320*3 = 960.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int x, r, r_temp = 0, c, prod, prod_max = 0, nr_prod_1, nr_prod_2;
    printf("x: ");
    scanf("%d", &x);
    int ten = 0;
    while (x != 0)
    {
        r = x % 10;
        c = x / 10;
        
        r_temp = r * pow(10, ten) + r_temp;
        prod = c * r_temp;
        if (prod > prod_max)
        {
            prod_max = prod;
            nr_prod_1 = c;
            nr_prod_2 = r_temp;
        }
        ten++;
        x = x/10;
    }
    printf("%d * %d = %d\n", nr_prod_1, nr_prod_2, prod_max);

    return 0;
}
