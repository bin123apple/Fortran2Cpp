#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int len = 1000;
    long long sum = 0;
    long long sum1 = 0;

    #pragma omp parallel
    {
        long long sum0 = 0;
        #pragma omp for
        for (int i = 1; i <= len; i++) {
            foo(i);
        }
        #pragma omp critical
        {
            sum += sum0;
        }
    }

    for (int i = 1; i <= len; i++) {
        sum1 += i;
    }

    cout << "sum = " << sum << ", sum1 = " << sum1 << endl;

    return 0;
}
