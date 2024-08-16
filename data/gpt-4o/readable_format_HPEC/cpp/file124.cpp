#include <stdio.h>
void foo();
int main()
{
#pragma omp parallel
 foo();
 return 0;
}
void foo()
{
 // function body here
}
