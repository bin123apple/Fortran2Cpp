Certainly! Here's the equivalent C++ code for the provided Fortran program and function:

```cpp
#include <iostream>
#include <vector>
#include <cmath>

int prod_signs(const std::vector<int>& arr) {
    if (arr.empty() || (arr.size() == 1 && arr[0] == 0)) {
        return -32768;
    }

    int sum = 0;
    int prods = 1;

    for (int num : arr) {
        sum += std::abs(num);
        if (num == 0) {
            prods = 0;
        }
        if (num < 0) {
            prods = -prods;
        }
    }

    return sum * prods;
}

int main() {
    std::vector<int> test_case_1 = {1, 2, 2, -4};
    if (prod_signs(test_case_1) != -9) {
        std::cerr << "Assertion failed: prod_signs({1, 2, 2, -4}) == -9" << std::endl;
        return 1;
    }

    std::vector<int> test_case_2 = {0, 1};
    if (prod_signs(test_case_2) != 0) {
        std::cerr << "Assertion failed: prod_signs({0, 1}) == 0" << std::endl;
        return 1;
    }

    std::vector<int> test_case_3 = {1, 1, 1, 2, 3, -1, 1};
    if (prod_signs(test_case_3) != -10) {
        std::cerr << "Assertion failed: prod_signs({1, 1, 1, 2, 3, -1, 1}) == -10" << std::endl;
        return 1;
    }

    std::vector<int> test_case_4 = {0};
    if (prod_signs(test_case_4) != -32768) {
        std::cerr << "Assertion failed: prod_signs({}) == -32768" << std::endl;
        return 1;
    }

    std::vector<int> test_case_5 = {2, 4, 1, 2, -1, -1, 9};
    if (prod_signs(test_case_5) != 20) {
        std::cerr << "Assertion failed: prod_signs({2, 4, 1, 2, -1, -1, 9}) == 20" << std::endl;
        return 1;
    }

    std::vector<int> test_case_6 = {-1, 1, -1, 1};
    if (prod_signs(test_case_6) != 4) {
        std::cerr << "Assertion failed: prod_signs({-1, 1, -1, 1}) == 4" << std::endl;
        return 1;
    }

    std::vector<int> test_case_7 = {-1, 1, 1, 1};
    if (prod_signs(test_case_7) != -4) {
        std::cerr << "Assertion failed: prod_signs({-1, 1, 1, 1}) == -4" << std::endl;
        return 1;
    }

    std::vector<int> test_case_8 = {-1, 1, 1, 0};
    if (prod_signs(test_case_8) != 0) {
        std::cerr << "Assertion failed: prod_signs({-1, 1, 1, 0}) == 0" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
```

This C++ code defines a `prod_signs` function that computes the product of the signs of the elements in an integer array, similar to the Fortran version. The `main` function contains a series of test cases to verify the correctness of the `prod_signs` function. Each test case checks if the function returns the expected result and prints an error message if the assertion fails.
