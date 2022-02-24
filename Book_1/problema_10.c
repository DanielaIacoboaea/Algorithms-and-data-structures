/* brocuta sare - cuac cuac - dupa n secunde oboseste si lungimea sariturii se injumatateste; 
se citeste p, n si t - durata totala a deplasarii broscutei in sec; afiseaza ditanta totala cu 2 zec. e stie ca T/n < 16.
ex: n = 10
    p = 20
    T = 33
*/

#include <stdio.h>

int main()
{
    int n, t;
    float dis = 0, p;
    printf("n: ");
    scanf("%d", &n);
    printf("p: ");
    scanf("%f", &p);
    printf("t: ");
    scanf("%d", &t);
    while (n <= t)
    {
        dis = dis + n * p;
        p = p * 0.5;
        t = t - n;
    }
    dis = dis + t * p;
    printf("dis: %.2f\n", dis);
    return 0;
}
