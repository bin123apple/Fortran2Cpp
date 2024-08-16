#include <iostream>
#include <omp.h>
#include <vector>

// Assuming the existence of a function gen_task that modifies the vector a in some way
void gen_task(int i, std::vector<int>& a) {
    // Placeholder for the actual task generation logic
    a[i-1] = i + 1; // Adjusting for 0-based indexing
}

int main() {
    const int size = 100;
    std::vector<int> a(size);

    #pragma omp parallel
    {
        #pragma omp single
        for (int i = 1; i <= size; ++i) {
            gen_task(i, a);
        }
    }

    for (int i = 1; i <= size; ++i) {
        if (a[i-1]!= i + 1) {
            std::cout << "warning: a(" << i << ") = " << a[i-1] << " not expected " << i + 1 << std::endl;
        }
        // Uncomment the following line if you want to see the results
        // std::cout << a[i-1] << " " << i + 1 << std::endl;
    }

    return 0;
}
