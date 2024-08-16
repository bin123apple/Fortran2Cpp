#include <iostream>
#include <omp.h>

using namespace std;

void f1(int& i) {
    // implementation of f1
}

int main() {
    int i = 0;
    int sum = 0;

    #pragma omp parallel reduction(+:sum) num_threads(10)
    {
        f1(i);
        sum += i;
    }
    #pragma omp end parallel

    if (sum!= 10) {
        cout << "sum = " << sum << endl;
    }

    return 0;
}
