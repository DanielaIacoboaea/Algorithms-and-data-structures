/* fiierul virus.txt        fisierul sum.txt va contine:
w23, ,mmm230...20e          273
fsdj.4sal..45,,k56ddd90z    195
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char s[256];
    FILE *f, *g;
    int sm, i, c = 0;
    f = fopen("virus.txt", "r");
    g = fopen("sum.txt", "w");
    while (!feof(f)fscanf(f, "%s", s))
    {
        sm = 0;
        for (i = 0; i < strlen(s); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                c = c*10 +(s[i] -'0');
                printf("c: %d\n", c);
            }else
            {
                printf("sm: %d, c: %d\n", sm, c);
                sm = sm + c;
                printf("sm: %d\n", sm);
                c = 0;
            }
        }
        fprintf(g, "%d\n", sm);
    }
    fclose(f);
    fclose(g);
    return 0;
}
