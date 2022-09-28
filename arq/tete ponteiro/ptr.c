#include <stdio.h>

void ptr(int *p, int *a, int *b) {
    *a = *a + *b;
    p = b;
    *p = 5;
}
// p continuou com o valor de a, pq??
int main()
{   
    int a = 2;
    int b = 4;
    int *p = &a;

    printf("%d", *p);
    printf("\n%d", a);
    ptr(p, &a, &b);
    printf("\n%d", a);
    printf("\n%d", b);
    printf("\n%d", *p);
    return 0;
}
