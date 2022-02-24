/* pinochio - in fiecare zi lucratoare din sap creste cu cate p< 101 centimetri
ambata si dum cand este Gepeto acasa scade nasul cu 1 centimetru/zi
care este dimensiunea nasului lui Pinochio dupa k < 257 zile stiind ca nasul sau inital masura n < 1001 cm?
ex:
n = 2;
p = 1;
k = 8;
rasp 6 cm;
*/

#include <stdio.h>

int main()
{
    int n, p, k, dim = 0, day_count = 1, i;
    printf("n,p,k: ");
    scanf("%d,%d,%d", &n, &p, &k);
    dim = n;
    for (i = 1; i <= 7 && day_count <= k; i++)
    {
        if (i != 6 && i != 7)
        {
            dim = dim + p;

        }else if (i == 6)
        {
            dim = dim - 1;
            
        }else if (i == 7)
        {
            dim = dim - 1;
            i = 1;
        }

        day_count++;

    }
    printf("dimensiunea nasului lui pinochio este: %d cm\n", dim);

    return 0;
}
