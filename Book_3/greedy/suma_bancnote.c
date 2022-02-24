#include <stdio.h>

void sorteaza(int b[20], int n)
{
    int temp, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = n-1; j > i; j--)
        {
            if(b[j] > b[j-1])
            {
                temp = b[j];
                b[j] = b[j-1];
                b[j-1] = temp;
            }
        }
    }
}


int main()
{
    int bancnote[20];
    int suma, i, n;
    
    printf("suma:\n");
    scanf("%d", &suma);
    printf("n: \n");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("bancnote[%d]: ", i);
        scanf("%d", &bancnote[i]);
    }
    i = 0;
    int count = 0;
    while (suma != 0 && i < n)
    {
        count = 0;
        while (suma >= bancnote[i])
        {
            suma = suma - bancnote[i];
            count++;
        }
        printf("%d bancnote de %d\n", count, bancnote[i]);
        i++;
    }
    return 0;
}