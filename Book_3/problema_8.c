/* n - nr natural si n nr reale care se memoreaza intr-un vector alocat in Heap
sa se afiseze media artimetica
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numbers[50], medie, sum = 0;
    float *p = numbers;
    int n, i;
    printf("n: ");
    scanf("%d", &n);
    p = (float*) malloc(n * sizeof(float));
    if (p == NULL)
    {
        printf("malloc failed\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        printf("numbers[i]: ");
        scanf("%f", &numbers[i]);
        sum = sum + numbers[i];
    }
    for (i = 0; i < n; i++)
    {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");
    printf("media: %.2f\n", sum/n);
    free(p);

    return 0;
}
