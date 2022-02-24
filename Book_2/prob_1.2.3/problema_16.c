#include <stdio.h>

typedef struct program{
    int sala;
    float h_start, h_end;

} program;

int main()
{
    FILE *f;
    f = fopen("film.in","r");
    int n, i = 0, count = 0, j;
    float start, end, max_start , min_end;
    program film[256], aux;
    while (!feof(f))
    {
        fscanf(f, "%d", &n);
        count++;
        if (count == 1)
        {
            break;
        }
    }   
    while (!feof(f))
    {
        fscanf(f, "%f %f", &film[i].h_start, &film[i].h_end);
        film[i].sala = i;
        i++;
    }
    for (i = 0; i < n; i++)
    {
        printf("sala: %d, start: %.2f, end: %.2f\n", film[i].sala, film[i].h_start, film[i].h_end);
    }
    for (i = 0; i < n; i++)
    {
        for (j = n-1; j > i; j--)
        {
            if (film[j].h_start < film[j-1].h_start)
            {
                aux = film[j];
                film[j] = film[j-1];
                film[j-1] = aux;
            }
        }
    }
    max_start = 0;
    for (i = 0; i < n; i++)
    {
        if (film[i].h_start > max_start)
        {
            max_start = film[i].h_start;
        }
    }
    min_end = film[0].h_end;
    for (i = 0; i < n; i++)
    {
        if (film[i].h_end < min_end)
        {
            min_end = film[i].h_end;
        }
    }
    printf("Toate filmele ruleaza simultan intre:\n");
    printf("%.2f %.2f\n", max_start, min_end);
    printf("Lista salilor:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", film[i].sala + 1);
    }
    fclose(f);
    return 0;
}
