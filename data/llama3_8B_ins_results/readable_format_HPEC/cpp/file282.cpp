#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int i, sum = 0, sum1 = 0;
    int sum0 = 0; // assuming this is a global variable

    #pragma omp parallel
    {
        #pragma omp for
        for (i = 1; i <= 1001; i++) {
            foo(i);
        }
        #pragma omp critical
        {
            sum += sum0;
        }
    }

    for (i = 1; i <= 1001; i++) {
        sum1 += i;
    }

    cout << "sum = " << sum << ", sum1 = " << sum1 << endl;

    return 0;
}
