Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>

int smallest_change(const std::vector<int>& arr) {
    int out = 0;
    int n = arr.size();
    for (int i = 0; i < n / 2; ++i) {
        if (arr[i] != arr[n - 1 - i]) {
            ++out;
        }
    }
    return out;
}

int main() {
    std::vector<int> test_case_1 = {1, 2, 3, 5, 4, 7, 9, 6};
    if (smallest_change(test_case_1) != 4) {
        std::cerr << "Assertion failed: smallest_change([1, 2, 3, 5, 4, 7, 9, 6]) == 4" << std::endl;
        std::exit(1);
    }

    std::vector<int> test_case_2 = {1, 2, 3, 4, 3, 2, 2};
    if (smallest_change(test_case_2) != 1) {
        std::cerr << "Assertion failed: smallest_change([1, 2, 3, 4, 3, 2, 2]) == 1" << std::endl;
        std::exit(1);
    }

    std::vector<int> test_case_3 = {1, 4, 2};
    if (smallest_change(test_case_3) != 1) {
        std::cerr << "Assertion failed: smallest_change([1, 4, 2]) == 1" << std::endl;
        std::exit(1);
    }

    std::vector<int> test_case_4 = {1, 4, 4, 2};
    if (smallest_change(test_case_4) != 1) {
        std::cerr << "Assertion failed: smallest_change([1, 4, 4, 2]) == 1" << std::endl;
        std::exit(1);
    }

    std::vector<int> test_case_5 = {1, 2, 3, 2, 1};
    if (smallest_change(test_case_5) != 0) {
        std::cerr << "Assertion failed: smallest_change([1, 2, 3, 2, 1]) == 0" << std::endl;
        std::exit(1);
    }

    std::vector<int> test_case_6 = {3, 1, 1, 3};
    if (smallest_change(test_case_6) != 0) {
        std::cerr << "Assertion failed: smallest_change([3, 1, 1, 3]) == 0" << std::endl;
        std::exit(1);
    }

    std::vector<int> test_case_7 = {1};
    if (smallest_change(test_case_7) != 0) {
        std::cerr << "Assertion failed: smallest_change([1]) == 0" << std::endl;
        std::exit(1);
    }

    std::vector<int> test_case_8 = {0, 1};
    if (smallest_change(test_case_8) != 1) {
        std::cerr << "Assertion failed: smallest_change([0, 1]) == 1" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
```

This C++ code includes the `smallest_change` function, which computes the smallest number of changes needed to make the array palindrome, and a `main` function that runs several test cases to verify the correctness of the `smallest_change` function. The test cases are similar to those in the Fortran code, and the output is checked against the expected results. If any test case fails, an error message is printed, and the program exits with a non-zero status.
