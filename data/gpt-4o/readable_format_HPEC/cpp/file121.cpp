#include <stdio.h>
int a[100];
void foo(int* a, int len, int value) {
#pragma omp parallel for firstprivate(value)
 for (int i = 0; i < len; i++)
 a[i] = value;
}
int main() {
 foo(a, 100, 7);
 printf("%d\n", a[50]);
 return 0;
}
