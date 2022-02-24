#include <stdio.h>

void hanoi(int n, char* a, char* b, char* c)
{
    if(n==1)
    {
        printf("din if: %c%c\n", *a, *b);
        printf("ififif\n");
    }else{
        hanoi(n-1, a, c, b);
        printf("hanoi1hanoi1hanoi1\n");
        printf("din else: %c%c\n", *a, *b);
        hanoi(n-1, c, b, a);
        printf("hanoi2hanoi2hanoi2\n");
    }
}

int main()
{
    char a, b, c;
    int n;
    a = 'a';
    b = 'b';
    c = 'c';
    printf("n: ");
    scanf("%d", &n);

    hanoi(n, &a, &b, &c);

    return 0;
}