#include <stdio.h>
#include <omp.h>
int i = 0;
void f1(int &i) {
#pragma omp parallel
{
i++;
}
}
int main()
{
f1(i);
if (i != 0)
printf("i = %d\n", i);
return 0;
}
