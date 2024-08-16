#include <stdio.h>
#include <omp.h>
#include <cmath>

#define dp 1.0
#define len 2560

double a[len], b[len];
double sum = 0.0;
double sum2 = 0.0;

int main() {
    for (int i = 0; i < len; i++) {
        a[i] = double(i) / 2.0;
        b[i] = double(i) / 3.0;
    }

#pragma omp target map(to: a[0:len], b[0:len]) map(tofrom: sum)
#pragma omp teams num_teams(10) thread_limit(256) reduction(+:sum)
#pragma omp distribute
    for (int i2 = 0; i2 < len; i2 += 256) {
#pragma omp parallel for reduction(+:sum)
        for (int i = i2 + 1; i < std::min(i2+256, len); i++)
            sum += a[i] * b[i];
    }

#pragma omp parallel for reduction(+:sum2)
    for (int i = 0; i < len; i++)
        sum2 += a[i] * b[i];

    printf("sum = %d; sum2 = %d
", (int)sum, (int)sum2);

    return 0;
}
