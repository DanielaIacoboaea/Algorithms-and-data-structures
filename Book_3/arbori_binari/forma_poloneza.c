#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nod{
    int operator;
    struct Nod* left;
    struct Nod* right;
} Nod;

Nod* arb(int li, int ls, char efp[30], int pfp[30])
{
    Nod* c;
    int i, j, min;
    min = pfp[ls];
    i = ls;
    for (j = ls; j >= li; j--)
    {
        if (pfp[j] < min)
        {
            min = pfp[j];
            i = j;
        }
    }
    c = (Nod*) malloc (sizeof(Nod));
    c->operator = efp[i];
    if (li == ls)
    {
        c->left = NULL;
        c->right = NULL;
    }else{
        c->left = arb(li, i - 1, efp, pfp);
        c->right = arb(i+1, ls, efp, pfp);
    }
    return c;
}

void parcurgere(Nod* temp)
{
    if (temp == NULL)
    {
        return;
    }
    parcurgere(temp->left);
    parcurgere(temp->right);
    printf(" %c ", temp->operator);
}

int main()
{
    char expresie[30], efp[30];
    char a;
    int pfp[30], p[30], i, j, n = 1;
    Nod* c = NULL;
    printf("a:\n");
    scanf(" %c", &a);

    while (a != '.')
    {
        expresie[n++] = a;
        printf("a:\n");
        scanf(" %c", &a);
    }
    n--;

    for (i = 1; i <= n; i++)
    {
        switch (expresie[i])
        {
            case ')':
                j = j - 10;
                break;
            case '(':
                j = j + 10;
                break;
            case '+':
                p[i] = j + 1;
                break;
            case '-':
                p[i] = j+1;
                break;
            case '*':
                p[i] = j+10;
                break;
            case '/':
                p[i] = j + 10;
                break;
            default: 
                p[i] = 1000;
                break;
        }
    }

    j = 1;
    for (i = 1; i <= n; i++)
    {
        if (expresie[i] != ')' && expresie[i] != '(')
        {
            efp[j] = expresie[i];
            pfp[j] = p[i];
            j++;
        }
    }

    c = arb(1, j-1, efp, pfp);
    parcurgere(c);

    return 0;
}