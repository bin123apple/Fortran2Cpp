#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int dp = 8; // Assuming double precision
    const int double_kind = 8; // Assuming c_double equivalent
    int64_t i, i2, len, l_limit, tmp;
    double sum, sum2;
    std::vector<double> a, b;

    len = 2560;
    sum = 0.0;
    sum2 = 0.0;

    a.resize(len);
    b.resize(len);

    for (i = 1; i <= len; ++i) {
        a[i-1] = static_cast<double>(i) / 2.0;
        b[i-1] = static_cast<double>(i) / 3.0;
    }

    #pragma omp target map(to: a[0:len], b[0:len]) map(tofrom: sum)
    #pragma omp teams num_teams(10) thread_limit(256) reduction(+:sum)
    #pragma omp distribute
    for (i2 = 1; i2 <= len; i2 += 256) {
        #pragma omp parallel for reduction(+:sum)
        for (i = i2 + 1; i <= std::min(i2 + 256, len); ++i) {
            sum += a[i-1] * b[i-1];
        }
    }

    #pragma omp parallel for reduction(+:sum2)
    for (i = 1; i <= len; ++i) {
        sum2 += a[i-1] * b[i-1];
    }

    std::cout << "sum = " << static_cast<int64_t>(sum) << "; sum2 = " << static_cast<int64_t>(sum2) << std::endl;

    return 0;
}
