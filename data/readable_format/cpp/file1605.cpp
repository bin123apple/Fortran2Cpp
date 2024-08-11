// CorrectCppProgram.cpp
#include <iostream>
#include <vector>
#include <omp.h>

using Int3DVec = std::vector<std::vector<std::vector<int>>>;

void foo(Int3DVec &s, int l1, int l2) {
    #pragma omp parallel for collapse(3)
    for (int i = 0; i < l1; ++i) {
        for (int j = 0; j < l2; ++j) {
            for (int k = 0; k < 19; ++k) {
                s[i][j][k] = 1;
            }
        }
    }
}

int main() {
    const int l1 = 200, l2 = 100, l3 = 19;
    Int3DVec a(l1, std::vector<std::vector<int>>(l2, std::vector<int>(l3, 0)));

    foo(a, l1, l2);

    bool testPassed = true;
    for (const auto &dim1 : a) {
        for (const auto &dim2 : dim1) {
            for (int elem : dim2) {
                if (elem != 1) {
                    testPassed = false;
                    break;
                }
            }
            if (!testPassed) break;
        }
        if (!testPassed) break;
    }

    if (testPassed) {
        std::cout << "C++ Test Passed: All elements are set to 1." << std::endl;
    } else {
        std::cerr << "C++ Test Failed: Not all elements are set to 1." << std::endl;
    }

    return !testPassed;
}