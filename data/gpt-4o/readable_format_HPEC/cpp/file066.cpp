#include <stdio.h>
#include <omp.h>
#include <cstdlib>

int main(int argc, char* argv[]) {
 int i, len = 10000, x;

 if (argc == 1) {
  printf("No command line arguments provided.
");
  return 1;
 }

 len = atoi(argv[1]);

 if (len == 0) {
  printf("Error, invalid integer value.
");
  return 1;
 }

#pragma omp parallel for private(i)
 for (i = 0; i < len; i++) {
  x = i;
 }

 printf("x = %d
", x);

 return 0;
}
