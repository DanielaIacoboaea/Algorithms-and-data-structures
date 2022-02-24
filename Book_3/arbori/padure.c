#include <stdio.h>

int arb_root(int nod, int track[25])
{
    while (track[nod])
    {
        nod = track[nod];
    }

    return nod;
}

void adaug(int i, int j, int track[25], int height[25])
{
    int v1, v2;

    v1 = arb_root(i, track);
    v2 = arb_root(j, track);

    if (v1 != v2)
    {
        if (height[v1] == height[v2])
        {
            track[v1] = v2;
            height[v2]++;
        }else
        {
            if(height[v1] < height[v2])
            {
                track[v1] = v2;
            }else{
                track[v2] = v1;
            }
        }
    }
}

int main()
{
    int n = 6, i, j;
    int track[25], height[25];
    FILE* f;
    f = fopen("padure.txt", "r");

    while (!feof(f))
    {
        fscanf(f, "%d %d", &i, &j);
        adaug(i, j, track, height);
    }

    printf("enter i, j:\n");
    scanf("%d,%d", &i, &j);

    if (arb_root(i, track) == arb_root(j, track))
    {
        printf("triunghiurile sunt asemenea\n");
    }else{
        printf("triunghiurile nu sunt asemenea\n");
    }

    fclose(f);

    return 0;
}