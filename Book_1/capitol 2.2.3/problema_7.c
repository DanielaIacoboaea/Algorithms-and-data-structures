/* se considera un tablou bidimensional a(n,m) cu elemente intregi
realizati un program care inverseaza elementele tabloului, prin intermediul unui vector de n*m elemente
ex: 
n = 3, m = 3
1 2 3 
4 5 6
7 8 9
se va afisa

9 8 7 
6 5 4
3 2 1
*/ 

#include <stdio.h>

int main()
{
    int i, j, n, m, size, k, l, aux, count = 0;
    int a[10][10];
    int b[20];
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    size = n * m;
    k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
            b[k] = a[i][j];
            k++;
        }
    }
    for (k = 0; k < size; k++)
    {
        printf("%d ", b[k]);
    }
    printf("\n");
    
    for (k = 0; k < size/2; k++)
    {
        aux = b[k];
        b[k] = b[size - k - 1];
        b[size - k - 1] = aux;
    }
    for (k = 0; k < size; k++)
    {
        printf("%d ", b[k]);
    }
    printf("\n");

    for (k = 0; k < size; k++)
    {
        printf("%d ", b[k]);
        count++;
        if (count == m)
        {
            printf("\n");
            count = 0;
        }
    }
      
    return 0;
}
