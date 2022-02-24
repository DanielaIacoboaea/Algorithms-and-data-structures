#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod* next;

}Nod;

int main()
{
    int n, i, number;
    Nod* vf, *temp, *to_add;
    vf = (Nod* ) malloc(sizeof(Nod));

    printf("n: ");
    scanf("%d", &n);
    printf("number: ");
    scanf("%d", &vf->info);
    vf->next = NULL;

    for (i = 1; i < n; i++)
    {
        to_add = (Nod* ) malloc(sizeof(Nod));
        printf("number: ");
        scanf("%d", &to_add->info);
    
        if(to_add->info < vf->info)
        {
            to_add->next = vf;
            vf = to_add;
            
        }else if(to_add->info > vf->info)
        {
            if (vf->next == NULL)
            {
                vf->next = to_add;
                to_add->next = NULL;
            }else {
                temp = vf;
              
                while(to_add->info > temp->next->info)
                {
                    if (temp->next->next == NULL)
                    {
                        temp->next->next = to_add;
                        to_add->next = NULL;
                        break;
                    }else{
                        temp = temp->next;
                    }
                }
                to_add->next = temp->next;
                temp->next = to_add;
            }
        }
    }
    while(vf)
    {
        printf("%d ", vf->info);
        vf = vf->next;
    }

    return 0;
}