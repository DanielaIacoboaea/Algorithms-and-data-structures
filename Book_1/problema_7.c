/* o pers poate sa coboare 1 sau 2 trepte deodata. 
trebuie sa coboare o scara cu N trepte; in cate moduri poate sa coboare?
ex: n = 3; rasp 2;
*/

#include <stdio.h>

int main()
{
    int n, a, b, c, i;
    printf("n: ");
    scanf("%d", &n);
    a = 1;
    b = 1;
    if (n == 1)
    {
        printf("%d", a);
    }
    if (n == 2)
    {
        printf("%d", b);
    }
    for (i = 3; i < n; i++)
    {
        c = a + b; //2 3 4
        a = b; // 1 2 3
        b = c; // 2 3 2
    }
    printf("%d ", c);

    return 0;
}
