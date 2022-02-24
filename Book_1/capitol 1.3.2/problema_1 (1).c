/* cercetasi din vrancea (2 zone: D1 (detasamente), N1 nr de cercetasi fiecare - din Galanciuc)
D2 (detasamente), N2 nr de cercetasi fiecare - din Soveja)
- reorganizare astfel incat sa fie formate din acelasi nr de cercetasi.
ex: 
D1 = 3;
N1 = 15;
D2 = 2;
N2 = 18;
nr de cercetasi din fiecare detasament: 9;
nr de detasamente D1 = 5;
nr de detasmente D2 = 4;
*/

#include <stdio.h>


int main()
{
    int d1, n1, d2, n2, prod1, prod2, i;
    printf("d1, n1 ");
    scanf("%d,%d", &d1, &n1);
    printf("d2, n2 ");
    scanf("%d,%d", &d2, &n2);

    prod1 = d1 * n1;
    prod2 = d2 * n2;

    for (i = 2; i < prod1 || i < prod2; i++)
    {
        if (prod1 % i == 0 && prod2 % i == 0)
        {
            n1 = i;
            n2 = i;
            d1 = prod1/i;
            d2 = prod2/i;
        }
    }

    printf("nr de cercetasi din fiecare detasament: %d\n", n1);
    printf("nr de detasamente din Galaciuc d1: %d\n", d1);
    printf("nr de detasamente din Soveja d2: %d\n", d2);

    return 0;
}
