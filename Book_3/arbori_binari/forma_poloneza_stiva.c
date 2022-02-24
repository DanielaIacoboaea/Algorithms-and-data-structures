#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stiva{
    char operator;
    int count;
} stiva;

int main()
{
    char forma_poloneza[100], c[2];
    stiva stack[100], stack_temp[100];
    int i, j = -1, n, k = 0, length = 0, m;
    printf("forma poloneza:\n");
    scanf(" %s", forma_poloneza);

    n = strlen(forma_poloneza);
    printf("n: %d\n", n);
    for (i = 0; i < n; i++)
    {
        printf("%c ", forma_poloneza[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        if (forma_poloneza[i] >= 'a' && forma_poloneza[i] <= 'z')
        {
            k++;
            length++;
            stack[k].operator = forma_poloneza[i];
            stack[k].count = -1;
        }else if (forma_poloneza[i] == '+' || forma_poloneza[i] == '-' || forma_poloneza[i] == '*' || forma_poloneza[i] == '/')
        {
            j++;

            if(stack[k-1].count < 0 && stack[k].count < 0)
            {
                printf("x%d = %c %c %c\n", j, stack[k-1].operator, forma_poloneza[i], stack[k].operator);
            }else if (stack[k-1].count >= 0)
            {
                printf("x%d = %c%d %c %c\n", j, stack[k-1].operator, stack[k-1].count, forma_poloneza[i], stack[k].operator);
            }else if (stack[k].count >= 0)
            {
                printf("x%d = %c %c %c%d\n", j, stack[k-1].operator, forma_poloneza[i], stack[k].operator, stack[k].count);
            }else if (stack[k-1].count >= 0 && stack[k].count >= 0)
            {
                printf("x%d = %c%d %c %c%d\n", j, stack[k-1].operator, stack[k-1].count, forma_poloneza[i], stack[k].operator, stack[k].count);
            }
            /*
            replace_operands(k, stack, j, length);
            length--;
            */
            stack[k-1].operator = 'x';
            stack[k-1].count = j;
            stack[k].operator = '\0';
            stack[k].count = 0;
            k--;
            length--;
/*
            printf("************\n");
            for (m = 1; m <= length; m++)
            {
                printf(" %c ", stack[m].operator);
            }
            printf("\n***********\n");
*/
        }
    }

    return 0;
}