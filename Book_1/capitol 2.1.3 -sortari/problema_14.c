/* realizati un program care det toate numerele mai mici o val naturala N (N<30.000)
folosindu-se de algoritmul numit "ciurul lui eratostene"
*/

#include <stdio.h>
#include <string.h>


int main()
{
    int ok[30000];
    int i, j, n;
    printf("n: ");
    scanf("%d", &n);
    memset(ok,1,sizeof(ok));
    for (i = 2; i * i <= n; i++)
    {
        printf("i: %d\n", i);
        if (ok[i])
        {
            printf("ok %d[%d]\n", ok[i], i);
            j = 2;
            printf("j: %d\n", j);
            while (i * j <= n)
            {
                ok [i * j] = 0;
                j++;
                printf("j din while %d\n", j);
            }
        }
    }
    for (i = 2; i <= n; i++)
    {
        if (ok[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
