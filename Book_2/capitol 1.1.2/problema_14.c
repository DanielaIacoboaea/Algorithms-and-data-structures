/* se considera un sir de n cuvinte
se doreste afisarea lor pe verticala respectand urmatoarele cerinte
- pe fiecare coloana sa afla in ordine cate un cuvant, de la primul pana la ultimul 
- pe ultima linie se afla primele litere ale fiecarui cuvant
- pe prima linie se afla ultimele litere ale celor mai lungi cuvinte
ex: sirul de 4 cuv: "eu", "masa","noi","vine" se va afisa

  a   e
  s i n
u a o i
e m n v
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][256];
    int i, n, max, h[100];
    printf("n: \n");
    scanf("%d", &n);
    max = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
        h[i] = strlen(a[i]) - 1;
        if (max < h[i])
        {
            max = h[i];
        }
    }
    for (;max >=0; max--)
    {
        printf("max: %d\n", max);
        for (i = 0; i < n; i++)
        {
            printf("i: %d\n", i);
            printf("h[i]: %d\n", h[i]);
            if (h[i] == max)
            {
                printf("%c", a[i][h[i]]);
                h[i]--;
                printf("h[i]2: %d\n", h[i]);
            }else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    /*size = n-1;
    for (i = 0; i < n; i++)
    {
        k = 0;
        fgets(w, sizeof(w), stdin);
        for (j = 0; j < strlen(w); j++)
        {
            a[size][k] = w[j];
            size--;
        }
        size = n-1;
        k++;
    }
    for (i = 0; i < n; i++)
    {
        printf("%s", a[i]);
    }*/
    return 0;
}
