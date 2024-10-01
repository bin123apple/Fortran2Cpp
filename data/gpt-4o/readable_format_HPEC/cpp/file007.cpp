#include <stdio.h>
#include <omp.h>

class A {
  public:
    static int counter;
    static int pcounter;

    A(int x, int y) {
      counter = x;
      pcounter = y;
    }

    static void foo() {
      #pragma omp parallel
      {
        counter++;
        #pragma omp atomic
        pcounter++;
      }
    }
};

int A::counter = 0;
int A::pcounter = 0;

int main() {
  A c(0,0);
  A::foo();
  printf("%d %d\n", A::counter, A::pcounter);
  return 0;
}
