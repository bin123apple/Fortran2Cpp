#include <iostream>
#include <omp.h>

using namespace std;

class A {
public:
    A(int, int);
};

A::A(int x, int y) {
    // implementation of A constructor
}

int counter = 0;
int pcounter = 0;

int main() {
    A c(0, 0);

    #pragma omp parallel
    {
        foo();
    }

    cout << counter << " " << pcounter << endl;

    return 0;
}
