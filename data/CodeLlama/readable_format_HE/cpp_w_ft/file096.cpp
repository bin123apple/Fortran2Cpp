Certainly! Below is the equivalent C++ code for the provided Fortran program. This C++ code includes the necessary function to handle the array and perform the calculations as per the Fortran code.

```cpp
#include <iostream>
#include <vector>
#include <cstdlib> // For exit()

// Function to calculate the sum of odd numbers in the array
int solutions(const std::vector<int>& lst) {
    int sum = 0;
    for (size_t i = 0; i < lst.size(); i += 2) {
        if (lst[i] % 2 == 1) {
            sum += lst[i];
        }
    }
    return sum;
}

int main() {
    // Test cases
    std::vector<int> test1 = {5, 8, 7, 1};
    if (solutions(test1) != 12) {
        std::cerr << "Assertion failed: solutions({5, 8, 7, 1}) == 12" << std::endl;
        std::exit(1);
    }

    std::vector<int> test2 = {3, 3, 3, 3, 3};
    if (solutions(test2) != 9) {
        std::cerr << "Assertion failed: solutions({3, 3, 3, 3, 3}) == 9" << std::endl;
        std::exit(1);
    }

    std::vector<int> test3 = {30, 13, 24, 321};
    if (solutions(test3) != 0) {
        std::cerr << "Assertion failed: solutions({30, 13, 24, 321}) == 0" << std::endl;
        std::exit(1);
    }

    std::vector<int> test4 = {5, 9};
    if (solutions(test4) != 5) {
        std::cerr << "Assertion failed: solutions({5, 9}) == 5" << std::endl;
        std::exit(1);
    }

    std::vector<int> test5 = {2, 4, 8};
    if (solutions(test5) != 0) {
        std::cerr << "Assertion failed: solutions({2, 4, 8}) == 0" << std::endl;
        std::exit(1);
    }

    std::vector<int> test6 = {30, 13, 23, 32};
    if (solutions(test6) != 23) {
        std::cerr << "Assertion failed: solutions({30, 13, 23, 32}) == 23" << std::endl;
        std::exit(1);
    }

    std::vector<int> test7 = {3, 13, 2, 9};
    if (solutions(test7) != 3) {
        std::cerr << "Assertion failed: solutions({3, 13, 2, 9}) == 3" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}
```

This C++ code defines a `solutions` function that takes a vector of integers as input and returns the sum of the odd numbers in the array, similar to the Fortran version. The `main` function contains several test cases to verify the correctness of the `solutions` function, similar to the Fortran program. If any test case fails, it prints an error message and exits with a non-zero status, indicating a failure.
