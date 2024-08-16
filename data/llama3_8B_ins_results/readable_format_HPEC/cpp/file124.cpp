#include <omp.h>

using namespace std;

void foo() {
  // code to be executed in parallel
}

int main() {
  #pragma omp parallel
  {
    foo();
  }
  return 0;
}
