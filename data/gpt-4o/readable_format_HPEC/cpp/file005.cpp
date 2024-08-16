#include <stdio.h>
#include <stdlib.h>

void foo(int n, int *a, int *b, int *c, int *d);

int main()
{
    int n = 1000;
    int *a = (int*)malloc(n*sizeof(int));
    int *b = (int*)malloc(n*sizeof(int));
    int *c = (int*)malloc(n*sizeof(int));
    int *d = (int*)malloc(n*sizeof(int));

    foo(n, a, b, c, d);

    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}
