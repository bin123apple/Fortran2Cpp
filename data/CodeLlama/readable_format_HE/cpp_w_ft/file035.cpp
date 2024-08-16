Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the necessary headers and uses the standard library, particularly the vector from the Standard Template Library (STL) for dynamic array allocation, which is a common practice in C++ for similar scenarios.

```cpp
#include <iostream>
#include <vector>
#include <cstdlib> // For exit()

bool pairs_sum_to_zero(const std::vector<int>& l) {
    for (size_t i = 0; i < l.size(); ++i) {
        for (size_t j = i + 1; j < l.size(); ++j) {
            if (l[i] + l[j] == 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::vector<int> l;
    bool result;

    // Test case 1
    l = {1, 3, 5, 0};
    result = pairs_sum_to_zero(l);
    if (result != false) {
        std::cerr << "Test case 1 failed" << std::endl;
        std::exit(1);
    }

    // Test case 2
    l = {1, 3, -2, 1};
    result = pairs_sum_to_zero(l);
    if (result != false) {
        std::cerr << "Test case 2 failed" << std::endl;
        std::exit(1);
    }

    // Test case 3
    l = {1, 2, 3, 7};
    result = pairs_sum_to_zero(l);
    if (result != false) {
        std::cerr << "Test case 3 failed" << std::endl;
        std::exit(1);
    }

    // Test case 4
    l = {2, 4, -5, 3, 5, 7};
    result = pairs_sum_to_zero(l);
    if (result != true) {
        std::cerr << "Test case 4 failed" << std::endl;
        std::exit(1);
    }

    // Test case 5
    l = {1};
    result = pairs_sum_to_zero(l);
    if (result != false) {
        std::cerr << "Test case 5 failed" << std::endl;
        std::exit(1);
    }

    // Test case 6
    l = {-3, 9, -1, 3, 2, 30};
    result = pairs_sum_to_zero(l);
    if (result != true) {
        std::cerr << "Test case 6 failed" << std::endl;
        std::exit(1);
    }

    // Test case 7
    l = {-3, 9, -1, 3, 2, 31};
    result = pairs_sum_to_zero(l);
    if (result != true) {
        std::cerr << "Test case 7 failed" << std::endl;
        std::exit(1);
    }

    // Test case 8
    l = {-3, 9, -1, 4, 2, 30};
    result = pairs_sum_to_zero(l);
    if (result != false) {
        std::cerr << "Test case 8 failed" << std::endl;
        std::exit(1);
    }

    // Test case 9
    l = {-3, 9, -1, 4, 2, 31};
    result = pairs_sum_to_zero(l);
    if (result != false) {
        std::cerr << "Test case 9 failed" << std::endl;
        std::exit(1);
    }

    std::cout << "All test cases passed" << std::endl;

    return 0;
}
```

This C++ code includes the `pairs_sum_to_zero` function, which performs the same logic as the Fortran function. It iterates through the vector `l` and checks for pairs of elements that sum to zero. The `main` function contains test cases similar to the Fortran program, using the `std::vector<int>` for dynamic array allocation and initialization. If any test case fails, it prints an error message and exits with a non-zero status, using `std::cerr` for error output and `std::exit(1)` for exiting the program with an error state.
