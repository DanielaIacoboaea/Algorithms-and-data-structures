#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    float info;
    struct Nod* next;

} Nod;

Nod* add_before(Nod* vf, float value)
{
    Nod* temp;
    temp = (Nod* ) malloc(sizeof(Nod));
    temp->info = value;
    temp->next = vf;
    vf = temp;

    return vf;
}

void print_list(Nod* vf)
{
    Nod* temp;
    temp = vf;
    while(temp)
    {
        printf("%.2f ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Nod* vf = NULL;
    int enter = 1;
    float x;
    do
    {
        printf("enter value: \n");
        scanf("%f", &x);
        vf = add_before(vf, x);
        printf("enter another value? yes: 1, no: 0\n");
        scanf("%d", &enter);
    } while (enter);

    print_list(vf);
    return 0;
}