/* a(n, m) cu elemente in multimea cifrelor 0...9
det pe fiecare linie baza minima in care cifrele respective pot reprezenta un numar
considerand ca pe fiecare linie este reprezentat in acest mod un numar, det valoarea obtinuta la conversia lui in baza 10
afisati pt fiecare linie baza minima si valoarea dupa conversie
ex: n = 3, m = 3
1 2 3
1 0 1
7 8 9 
se va afisa:
4 27
2 5
10 789
*/

#include <stdio.h>
#include <math.h>

int numberBase(int arr[], int size)
{
    int i, max = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max+1;
}

int numberBaseTen(int a[], int size, int b)
{
    int i, num = 0, p = 0;
    for (i = size-1; i >= 0; i--)
    {
        num = num + a[i] * pow(b,p);
        p++;
    }
    return num;
}
int main()
{
    int i, j, n, m, base, number, k;
    int a[10][10];
    int v[10];
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < n; i++)
    {
        base = numberBase(&a[i][0], m);
        number = numberBaseTen(&a[i][0], m, base);
        printf("base: %d, number in base 10: %d\n", base, number);
    }
    return 0;
}
