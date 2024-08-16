#include <stdio.h>
#include <omp.h>

int main()
{
 int init, local;
#pragma omp parallel shared(init) private(local)
 {
#pragma omp single
 init = 10;
 local = init;
 }

return 0;
}
