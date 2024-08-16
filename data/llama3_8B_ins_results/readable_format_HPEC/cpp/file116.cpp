#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int i = 0;

    #pragma omp parallel
    {
        f1(i);
    }

    if (i!= 0) {
        cout << "i = " << i << endl;
    }

    return 0;
}
