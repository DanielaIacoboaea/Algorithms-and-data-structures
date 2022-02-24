#include <stdio.h>
#include <stdlib.h>

void add(int a) {
    a = a + 1;
}

void p_add(int* c) {
    *c = *c + 2;
}

void p_change(int *c) {
    int* tmp;
    tmp = (int*) malloc(sizeof(int));
    *tmp = 100;

    c = tmp;
}

void p_p_change(int **p_p, int *p, int a) {
    int c = a;
    p = (int*) malloc(sizeof(int));
    *p = 100;

    a = 10;
    p = &a;

    *p_p = p;

    *p_p = malloc(sizeof(int));
    **p_p = 99;

}

int main() {
    int a = 2;

    add(a);
    printf("%d\n", a);

    int *p = &a;
    p_add(p);
    printf("%d\n", a);

    p_change(p);
    printf("%d\n", *p);

    p_p_change(&p, p, a);
    printf("%d\n", *p);
}