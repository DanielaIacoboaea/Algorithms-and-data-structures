/* orice virus de tip A se divide si se obtin un virus de tip A, un nou virus de tip B si un nou virus de tip C
ditr-un virus de tip B si un virus de tip C se obtin trei noi virusi (unul de tip C si doi de tip B)
sa se det nr de virui existenti dupa n < 26 sec;
*/

#include <stdio.h>

int main()
{
    int a = 1, b = 1, c = 1, n, i;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        b = b + 2 *c + a;
        c = c * 2 + a;
        a = a * 2;
    }
    printf("A: %d, B: %d, C: %d\n", a, b, c);
    return 0;
}
