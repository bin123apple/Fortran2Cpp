#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int dp = sizeof(double);
    const int double_kind = dp;
    int64_t i, i2, len, l_limit, tmp;
    double sum, sum2;
    std::vector<double> a(2560), b(2560);

    len = 2560;
    sum = 0.0;
    sum2 = 0.0;

    for (i = 0; i < len; ++i) {
        a[i] = static_cast<double>(i + 1) / 2.0;
        b[i] = static_cast<double>(i + 1) / 3.0;
    }

    #pragma omp target map(to: a[0:len], b[0:len]) map(tofrom: sum)
    {
        #pragma omp teams num_teams(10) thread_limit(256) reduction(+:sum)
        {
            #pragma omp distribute
            for (i2 = 0; i2 < len; i2 += 256) {
                #pragma omp parallel for reduction(+:sum)
                for (i = i2 + 1; i < std::min(i2 + 256, len); ++i) {
                    sum += a[i] * b[i];
                }
            }
        }
    }

    #pragma omp parallel for reduction(+:sum2)
    for (i = 0; i < len; ++i) {
        sum2 += a[i] * b[i];
    }

    std::cout << "sum = " << static_cast<int64_t>(sum) << "; sum2 = " << static_cast<int64_t>(sum2) << std::endl;

    return 0;
}
