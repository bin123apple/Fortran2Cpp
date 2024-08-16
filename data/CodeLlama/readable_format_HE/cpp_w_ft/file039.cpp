Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the `sort` and `median` functions within a namespace `utilities` similar to the Fortran module. The `median_test` function demonstrates how to use these functions and includes a few test cases to verify their correctness.

```cpp
#include <iostream>
#include <vector>
#include <cmath>

namespace utilities {
    void sort(std::vector<float>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (arr[i] > arr[j]) {
                    std::swap(arr[i], arr[j]);
                }
            }
        }
    }

    float median(const std::vector<float>& arr) {
        std::vector<float> sorted_arr = arr;
        sort(sorted_arr);
        int n = sorted_arr.size();
        if (n % 2 == 1) {
            return sorted_arr[n / 2];
        } else {
            return (sorted_arr[n / 2 - 1] + sorted_arr[n / 2]) / 2.0f;
        }
    }
}

void median_test() {
    using namespace utilities;

    // Test cases
    float result = median({3.0f, 1.0f, 2.0f, 4.0f, 5.0f});
    if (std::abs(result - 3.0f) > 1e-4) {
        std::cerr << "Test case 1 failed: assertion failed" << std::endl;
        exit(1);
    }

    result = median({-10.0f, 4.0f, 6.0f, 1000.0f, 10.0f, 20.0f});
    if (std::abs(result - 8.0f) > 1e-4) {
        std::cerr << "Test case 2 failed: assertion failed" << std::endl;
        exit(1);
    }

    result = median({5.0f});
    if (std::abs(result - 5.0f) > 1e-4) {
        std::cerr << "Test case 3 failed: assertion failed" << std::endl;
        exit(1);
    }

    result = median({6.0f, 5.0f});
    if (std::abs(result - 5.5f) > 1e-4) {
        std::cerr << "Test case 4 failed: assertion failed" << std::endl;
        exit(1);
    }

    result = median({8.0f, 1.0f, 3.0f, 9.0f, 9.0f, 2.0f, 7.0f});
    if (std::abs(result - 7.0f) > 1e-4) {
        std::cerr << "Test case 5 failed: assertion failed" << std::endl;
        exit(1);
    }

    std::cout << "All test cases passed." << std::endl;
}

int main() {
    median_test();
    return 0;
}
```

This C++ code defines the `sort` and `median` functions within the `utilities` namespace, similar to the Fortran module. The `median_test` function demonstrates how to use these functions and includes a few test cases to verify their correctness. The test cases compare the computed median against expected values and print an error message if any test case fails.
