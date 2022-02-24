/* n calculatoare 
tipul procesorului (486, Pentium I, II, III, IV, Duron, etc)
frecventa procesorului (in MHz)
memoria RAM (exprimata in MB)
capacitatea hard-discului (in MB)
afisati calculatoarele care pot fi conectate in retea (frecevnta de cel putin x MHz, memoria de cel putin y MB si capacitate 
hard-disc de cel putin z MB)
server - calculatorul cu cele mai bune performante in ordinea: Frecventa, Memorie RAM;
*/

#include<stdio.h>

typedef struct computer{
    char p[256];
    int fv, mem, hd;
} computer;

int main()
{
    int n, i, x, y, z, max_fv = 0, max_mem = 0, s;
    computer server;
    computer info[50];
    printf("n,x,y,z:\n");
    scanf("%d,%d,%d,%d", &n, &x, &y, &z);
    for (i = 0; i < n; i++)
    {
        printf("Procesor %d:", i);
        fgets(info[i].p, sizeof(info[i].p), stdin);
        scanf(" %s", info[i].p);
        printf("fv,mem,hd: ");
        scanf("%d,%d,%d", &info[i].fv, &info[i].mem, &info[i].hd);
        if (info[i].fv > max_fv)
        {
            max_fv = info[i].fv;
            s = i;
            server.fv = info[i].fv;
            server.mem = info[i].mem;
        }
        if (info[i].fv == max_fv && info[i].mem > max_mem)
        {
            max_fv = info[i].fv;
            s = i;
            server.fv = info[i].fv;
            server.mem = info[i].mem;
        }
    }
    printf("Server: %d\n", s+1);
    for (i = 0; i < n; i++)
    {
        if (info[i].fv >= x && info[i].mem >= y && info[i].hd >=z)
        {
            printf("%s este in retea\n", info[i].p);
        } 
    }
    return 0;
}
