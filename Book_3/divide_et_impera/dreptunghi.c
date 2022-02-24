#include <stdio.h>

int l, h, i, n, xf, yf, lf, hf, xv[10], yv[10];

void dimp(int x, int y, int l, int h, int* xf, int* yf, int* lf, int* hf, int xv[10], int yv[10])
{
    int gasit = 0, i = 1;
    while(i <=n && !gasit)
    {
        if(xv[i] > x && xv[i] < l && yv[i] > y && yv[i] < y+h)
        {
            gasit = 1;
        }else{
            i++;
        }
    }
    if(gasit)
    {
        dimp(x, y, xv[i]-x, h, xf, yf, lf, hf, xv, yv);
        dimp(xv[i], y, l+x-xv[i], h, xf, yf, lf, hf, xv, yv);
        dimp(x, y, l, yv[i]-y, xf, yf, lf, hf, xv, yv);
        dimp(x, yv[i], l, h+y-yv[i], xf, yf, lf, hf, xv, yv);

    }else{
        if(l*h > (*lf)*(*hf))
        {
            *xf = x;
            *yf = y;
            *lf = l;
            *hf = h;
        }
    }
}

int main()
{
    printf("n: ");
    scanf("%d", &n);
    for (i = 1; i<= n; i++)
    {
        printf("x[%d]: ", i);
        scanf("%d", &xv[i]);
        printf("y[%d]: ", i);
        scanf("%d", &yv[i]);
    }
    printf("l:\n");
    scanf("%d", &l);
    printf("h:\n");
    scanf("%d", &h);

    dimp(0, 0, l, h, &xf, &yf, &lf, &hf, xv, yv);

    printf("x = %d, y = %d, l = %d, h = %d\n", xf, yf, lf, hf);
    return 0;
}