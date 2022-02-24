/* ex n clase = 2 si m elevi =4     se va afisa
clasa 1: 2 navetisti, 1 baiat       numarul de fete: 4
clasa 2: 1 navetist, 3 baieti       procentajul navetistilor: 37.5%
                                    Lista: clasa 1
*/

#include <stdio.h>

typedef struct clasa {
    int b, nv, f;
    float p;

} clasa;

int main()
{
    int n, m, i, fete = 0, total_nv = 0, lista;
    float max_nv, c_nv;
    clasa all_class[50];
    printf("n,m: ");
    scanf("%d,%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        printf("Clasa %i: nr navetisti, nr baieti:\n", i);
        scanf("%d,%d", &all_class[i].nv, &all_class[i].b);
        all_class[i].f = m - all_class[i].b;
        all_class[i].p = (100 * all_class[i].nv)/m;
    }
    for (i = 0; i < n; i++)
    {
        fete = fete + (m - all_class[i].b);
    }
    printf("Numarul de fete: %d\n", fete);
    for (i = 0; i < n; i++)
    {
        total_nv = total_nv + all_class[i].nv;
    }
    c_nv = (total_nv * 100)/(m*n);
    printf("Procentajul navetistilor %.1f\n", c_nv);
    max_nv = c_nv;
    for (i = 0; i < n; i++)
    {
        if (all_class[i].p > max_nv)
        {
            max_nv = all_class[i].p;
            lista = i;
        }
    }
    printf("Lista: clasa %d\n", lista+1);
    
    return 0;
}
