#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* next;

} Nod;

Nod* a[50];

void add_succesor(int i, int j)
{
    Nod* temp, *newNod;
    newNod = (Nod* ) malloc(sizeof(Nod));
    newNod->info = j;
    newNod->next = NULL;
    temp = a[i];
    if(temp == 0)
    {
        a[i] = newNod;
    }else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNod;
    }
}

int find_zero_value(int n, int contor[50])
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if(contor[i] == 0)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int i, j, n, k, count = 0, value;
    int contor[50];
    Nod* temp, *c;

    printf("n: ");
    scanf("%d", &n);

    for(k = 1; k <= n; k++)
    {
        contor[k] = 0;
        a[k] = 0;
    }

    for(k = 1; k <= n; k++)
    {
        printf("i,j: ");
        scanf("%d,%d", &i, &j);
        contor[j]++;
        add_succesor(i, j);

    }
    for (k = 1; k <=n; k++)
    {
        printf("contor[%d]: %d\n", k, contor[k]);
    }

    while (count < n)
    {
        value = find_zero_value(n, contor);
        count++;
        printf("%d ", value);
        contor[value] = -1;
        c = a[value];
        while (c)
        {
            contor[c->info]--;
            c = c->next;
        }
    }
    return 0;
}