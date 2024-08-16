#include <stdio.h>
extern void foo();
int main()
{
#pragma omp parallel
{
 foo();
}
 return 0;
}
