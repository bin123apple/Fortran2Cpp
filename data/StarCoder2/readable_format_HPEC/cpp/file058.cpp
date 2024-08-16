#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<double> a(len);

    // Initialization of the array
    for (int i = 0; i < len; ++i) {
        a[i] = static_cast<double>(i + 1) / 2.0;
    }

    // OpenMP target directive with teams
    #pragma omp target map(tofrom: a[0:len])
    {
        #pragma omp teams num_teams(2)
        {
            a[49] = a[49] * 2.0; // Adjusted index for C++ 0-based indexing
        }
    }

    // Print the result
    std::cout << "a[50]=" << a[50] << std::endl;

    return 0;
}
