#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int len = 1000;
    int sum = 0;
    int sum0 = 0;
    int sum1 = 0;

    #pragma omp parallel
    {
        int local_sum0 = 0;
        #pragma omp for
        for (int i = 1; i <= len; i++) {
            local_sum0 += i;
        }
        #pragma omp critical
        {
            sum += local_sum0;
        }
    }

    for (int i = 1; i <= len; i++) {
        sum1 += i;
    }

    cout << "sum = " << sum << ", sum1 = " << sum1 << endl;

    return 0;
}
