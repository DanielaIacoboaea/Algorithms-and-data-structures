#include <stdio.h>

typedef struct stiva{
    int nr;
    char inf[500];

} stiva;

int main()
{
    stiva st;
    int n, l, i, j, x, ok;
    freopen ("par.in","r",stdin);
    freopen("par.out","w",stdout);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l);
        ok = 1; 
        st.nr = 0;
        for (j = 0; j < 1; j++)
        {
            printf("j for: %d\n", j);
            scanf("%d", &x);
            printf("x: %d\n", x);
            if (x == 0 || x == 2)
            {
                st.inf[st.nr++] = x;
                printf("if st.inf[%d]: %c\n", st.nr++, st.inf[st.nr++]);
            }else if (!st.nr || x != st.inf[st.nr-1]+1)
            {
                printf("else st.inf[st.nr-1]+1: %d\n", st.inf[st.nr-1]+1);
                ok = 0;
                printf("ok: %d\n", ok);
                st.nr--;
                printf("st.nr --: %d\n", st.nr--);
            }
        }
        if ( ok && st.nr)
        {
            printf("ok && str.nr: %d si %d\n", ok, st.nr);
            ok = 0;
        }
        printf("%s\n", ok? "Da" : "Nu");
    }
    return 0;
}
