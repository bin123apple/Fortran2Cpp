Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the same functionality and the same set of tests to verify the correctness of the `count_nums` function.

```cpp
#include <iostream>
#include <vector>
#include <cmath>

int count_nums(const std::vector<int>& n) {
    int num = 0;
    for (int i = 0; i < n.size(); ++i) {
        if (n[i] > 0) {
            ++num;
        } else {
            int sum = 0;
            int w = std::abs(n[i]);
            while (w >= 10) {
                sum += w % 10;
                w /= 10;
            }
            sum -= w;
            if (sum > 0) ++num;
        }
    }
    return num;
}

int main() {
    std::vector<int> test_case_1 = {0};
    if (count_nums(test_case_1) != 0) {
        std::cerr << "Assertion failed: count_nums({0}) == 0" << std::endl;
        return 1;
    }

    std::vector<int> test_case_2 = {-1, -2, 0};
    if (count_nums(test_case_2) != 0) {
        std::cerr << "Assertion failed: count_nums({-1, -2, 0}) == 0" << std::endl;
        return 1;
    }

    std::vector<int> test_case_3 = {1, 1, 2, -2, 3, 4, 5};
    if (count_nums(test_case_3) != 6) {
        std::cerr << "Assertion failed: count_nums({1, 1, 2, -2, 3, 4, 5}) == 6" << std::endl;
        return 1;
    }

    std::vector<int> test_case_4 = {1, 6, 9, -6, 0, 1, 5};
    if (count_nums(test_case_4) != 5) {
        std::cerr << "Assertion failed: count_nums({1, 6, 9, -6, 0, 1, 5}) == 5" << std::endl;
        return 1;
    }

    std::vector<int> test_case_5 = {1, 100, 98, -7, 1, -1};
    if (count_nums(test_case_5) != 4) {
        std::cerr << "Assertion failed: count_nums({1, 100, 98, -7, 1, -1}) == 4" << std::endl;
        return 1;
    }

    std::vector<int> test_case_6 = {12, 23, 34, -45, -56, 0};
    if (count_nums(test_case_6) != 5) {
        std::cerr << "Assertion failed: count_nums({12, 23, 34, -45, -56, 0}) == 5" << std::endl;
        return 1;
    }

    std::vector<int> test_case_7 = {-0, 1};
    if (count_nums(test_case_7) != 1) {
        std::cerr << "Assertion failed: count_nums({-0, 1}) == 1" << std::endl;
        return 1;
    }

    std::vector<int> test_case_8 = {1};
    if (count_nums(test_case_8) != 1) {
        std::cerr << "Assertion failed: count_nums({1}) == 1" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}
```

This C++ code defines a function `count_nums` that takes a vector of integers as input and returns the number of positive numbers and the number of numbers that have a sum of positive digits (excluding leading zeros) when negated. The `main` function contains a series of tests to verify the correctness of `count_nums` against various input vectors.
