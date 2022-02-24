/* teatru.in        se va afisa
10.00 12.30         9.30 13.20
9.30 13.20          12.20 15.30
15.00 16.00
12.20 15.30
12.30 14.20 
*/

#include <stdio.h>

typedef struct shedule{
    float start_h, end_h;
} shedule;
int main()
{
    FILE *f;
    f = fopen("teatru.in", "r");
    int n, i, count = 0, j, u;
    shedule plays[50], aux;
    float start, finish;
    printf("n: ");
    scanf("%d", &n);
    while (!feof(f))
    {
        fscanf(f, "%f %f", &plays[count].start_h, &plays[count].end_h);
        count++;
    }
    for (i = 0; i < count; i++)
    {
        for (j = count - 1;j > i; j--)
        {
            if (plays[j].start_h < plays[j-1].start_h || (plays[j].start_h == plays[j-1].start_h && plays[j].end_h < plays[j-1].end_h))
            {
                aux = plays[j];
                plays[j] = plays[j-1];
                plays[j-1] = aux;
            }
        }
    }
    u = 0;
    finish = plays[0].end_h;
    for (i = 1; i < count; i++)
    {
        if (plays[i].end_h < finish)
        {
            printf("%.2f %.2f\n", plays[u].start_h, plays[u].end_h);
            u = i; 
            finish = plays[i].end_h;
        }else if (plays[i].start_h < finish)
        {
            printf("%.2f %.2f\n", plays[i].start_h, plays[i].end_h);
        }else
        {
            u = i;
            finish = plays[i].end_h;
        }
    }
    fclose(f);
    return 0;
}
