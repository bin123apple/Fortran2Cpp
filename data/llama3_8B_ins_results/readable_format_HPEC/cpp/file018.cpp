#include <iostream>
#include <omp.h>

using namespace std;

class A {
public:
    // assume A has a constructor that takes two integers
    A(int, int);
};

A::A(int x, int y) {}

int counter = 0;
int pcounter = 0;

int main() {
    A c(0, 0);

    #pragma omp parallel
    {
        counter++;
        pcounter++;
    }

    cout << counter << " " << pcounter << endl;

    return 0;
}
