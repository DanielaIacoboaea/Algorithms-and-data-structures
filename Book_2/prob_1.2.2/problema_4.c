/* n sortimente 
-cantitatea (nr bucati)
- pret (achizitie)
-adaos comercial(exprimat in procent din valoarea de achizitie)
- o sapt s-a contorizat pe zile cantitatea vanduta din fiecare produs
-afiseaza valoarea maxima a vanzarilor obtinute intr-o zi
-afiseaza valoarea vanzarilor saptamanale ale unui produs x
*/

#include <stdio.h>

typedef struct prod{
    int c;
    float p_vanzare;
    float z[10];
} prod;

int main()
{
    int n, x, i, j;
    float p_a, p_ad, t, max = 0.0, s = 0.0;
    prod a[50];
    printf("n,x:\n");
    scanf("%d,%d", &n, &x);
    for (i = 0; i < n; i++)
    {
        printf("c prod %d: \n", i);
        scanf("%d", &a[i].c);
        printf("prod %d: p_a, p_ad\n", i);
        scanf("%f,%f", &p_a, &p_ad);
        a[i].p_vanzare = p_a + p_a * p_ad/100.0;
        for (j = 0; j < 7; j++)
        {
            printf("vanzarile zilnice zi %d:\n", j);
            scanf("%f", &a[i].z[j]);
        }
    }
    for (i = 0; i < 7; i++)
    {
        for (t = j = 0; j < n; j++)
        {
            t+=a[j].p_vanzare * a[j].z[i];
        }
        if (t > max)
        {
            max = t;
        }
    }
    x--;
    for (i = 0; i < 7; i++)
    {
        s+= a[x].z[i] * a[x].p_vanzare;
    }
    printf("%.2f %.2f\n", max, s);
    return 0;
}
