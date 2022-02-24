#include <stdio.h>

int a[100], n, k = 0;

void poz(int li, int ls, int* k, int a[100])
{
    int i = li;
    int j = ls;
    int c;
    int i1 = 0;
    int j1 = -1;
    while (i < j)
    {
        if(a[i] > a[j])
        {
            c = a[j];
            a[j] = a[i];
            a[i] = c;
            
            c = i1;
            i1 = -j1;
            j1 = -c;
        }
        i = i+i1;
        j = j+j1;
    }
    *k = i;
}

void quick(int li, int ls)
{
    int i;
    if (li < ls)
    {
        printf("\nl1: %d, ls: %d\n", li, ls);
        poz(li, ls, &k, a);
        printf("k dupa poza: %d\n", k);
        printf("\ndupa poza: l1: %d, ls: %d\n", li, ls);
        printf("\narray dupa poza:\n");
        for (i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        printf("BEFORE: quick li, k-1: %d,%d\n", li, k-1);
        printf("\ndBEFORE: quick li, k-1: li %d, ls: %d\n", li, ls);
        quick(li, k-1);
        printf("AFTER: quick li, k-1: %d,%d\n", li, k-1);
         printf("\nAFTER quick li, k-1: li %d, ls: %d\n", li, ls);
        printf("k dupa quick li, k-1: %d\n", k);
        printf("\n quick li, k-1: li %d, ls: %d\n", li, ls);
        printf("\narray dupa quick li, k-1:\n");
        for (i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        printf("BEFORE quick k+1, ls: %d, %d\n", k+1, ls);
        printf("\ndBEFORE: quick k+1, ls: li %d, ls: %d\n", li, ls);
        quick(k+1, ls);
        printf("AFTER quick k+1, ls: %d, %d\n", k+1, ls);
        printf("\nAFTER quick k+1, ls: li %d, ls: %d\n", li, ls);
        printf("k dupa quick k+1, ls: %d\n", k);
        printf("\n quick k+1, ls: li %d, ls: %d\n", li, ls);

        printf("\narray dupa quick k+1, ls:\n");
        for (i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

int main()
{
    int i;
    printf("n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    quick(1, n);

    for (i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}