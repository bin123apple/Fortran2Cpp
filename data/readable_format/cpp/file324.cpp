#include <iostream>
#include <vector>
#include <omp.h>

bool testVectorValues(const std::vector<int>& vec, int value) {
    for (auto val : vec) {
        if (val != value) return false;
    }
    return true;
}

int main() {
    std::vector<int> a(16, 0);

    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                for (auto& val : a) {
                    #pragma omp atomic
                    val += 1;
                }
            }
            #pragma omp section
            {
                for (auto& val : a) {
                    #pragma omp atomic
                    val += 2;
                }
            }
        }
    }

    if (!testVectorValues(a, 3)) {
        std::cerr << "Test failed: Not all elements are 3" << std::endl;
        return 1;
    }

    std::cout << "Test passed: All elements are 3." << std::endl;
    return 0;
}