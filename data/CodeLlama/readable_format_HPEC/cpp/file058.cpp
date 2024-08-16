#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<double> a(len); // Using vector for dynamic array allocation

    // Filling the array
    for (int i = 0; i < len; ++i) {
        a[i] = static_cast<double>(i) / 2.0;
    }

    // OpenMP pragmas for targeting and teams
    #pragma omp target map(tofrom: a[0:len])
    {
        #pragma omp teams num_teams(2)
        {
            a[50] = a[50] * 2.0; // Modifying the 50th element
        }
    }

    // Printing the result
    std::cout << "a[50]= " << a[50] << std::endl;

    // No need to explicitly deallocate 'a', as it will be automatically done by the vector destructor
    return 0;
}
