Translating the provided Fortran code to C++ involves several steps, including changing the syntax for array handling, function definitions, and control structures. Here's a C++ version of the code:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Function to sort an array
void sort_array(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

// Function to sort every third element of the input array
std::vector<int> sort_third(const std::vector<int>& l) {
    std::vector<int> third;
    std::vector<int> out(l.size());

    // Extract every third element
    for (size_t i = 0; i < l.size(); i += 3) {
        third.push_back(l[i]);
    }

    // Sort the third array
    sort_array(third);

    // Reconstruct the output array
    for (size_t i = 0; i < l.size(); ++i) {
        if (i % 3 == 0) {
            out[i] = third[i / 3];
        } else {
            out[i] = l[i];
        }
    }

    return out;
}

// Function to check if two vectors are equal
bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

// Subroutine to assert a condition
void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

// Subroutine to run tests
void run_tests() {
    assert(issame(sort_third({1, 2, 3}), sort_third({1, 2, 3})));
    assert(issame(sort_third({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10}), sort_third({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10})));
    assert(issame(sort_third({5, 8, -12, 4, 23, 2, 3, 11, 12, -10}), sort_third({5, 8, -12, 4, 23, 2, 3, 11, 12, -10})));
    assert(issame(sort_third({5, 6, 3, 4, 8, 9, 2}), {2, 6, 3, 4, 8, 9, 5}));
    assert(issame(sort_third({5, 8, 3, 4, 6, 9, 2}), {2, 8, 3, 4, 6, 9, 5}));
    assert(issame(sort_third({5, 6, 9, 4, 8, 3, 2}), {2, 6, 9, 4, 8, 3, 5}));
    assert(issame(sort_third({5, 6, 3, 4, 8, 9, 2, 1}), {2, 6, 3, 4, 8, 9, 5, 1}));
}

int main() {
    run_tests();
    return 0;
}
```

### Key Changes:

1. **Array Handling**: C++ uses `std::vector` for dynamic arrays, which is more flexible and safer compared to raw arrays.
2. **Function Definitions**: Functions are defined using `std::vector<int>` for input and output parameters, and `void` for functions that do not return a value.
3. **Sorting Algorithm**: The sorting algorithm is implemented using nested loops, which is a common approach in C++ for sorting arrays.
4. **Testing**: The `assert` function checks conditions and prints an error message if the condition is false. The `run_tests` function runs several assertions to verify the correctness of the `sort_third` function.

This C++ code should provide equivalent functionality to the original Fortran code, ensuring that the sorting logic and the testing framework are correctly translated.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create unit tests that cover various scenarios. Below are the unit test codes for both languages.

### Fortran Unit Test Code

Here is a Fortran program that includes the `sort_third` function and a series of tests to verify its correctness:

```fortran
program test_sort_third
    implicit none
    integer, allocatable :: test_array(:)
    integer, allocatable :: result_array(:)
    logical :: test_passed

    ! Test 1
    allocate(test_array(3))
    test_array = [1, 2, 3]
    result_array = sort_third(test_array)
    test_passed = issame(result_array, [1, 2, 3])
    call assert(test_passed)

    ! Test 2
    allocate(test_array(9))
    test_array = [5, 3, -5, 2, -3, 3, 9, 0, 123]
    result_array = sort_third(test_array)
    test_passed = issame(result_array, [5, 3, -5, 2, -3, 3, 9, 0, 123])
    call assert(test_passed)

    ! Test 3
    allocate(test_array(7))
    test_array = [5, 8, -12, 4, 23, 2, 3]
    result_array = sort_third(test_array)
    test_passed = issame(result_array, [5, 8, -12, 4, 23, 2, 3])
    call assert(test_passed)

    ! Test 4
    allocate(test_array(7))
    test_array = [5, 6, 3, 4, 8, 9, 2]
    result_array = sort_third(test_array)
    test_passed = issame(result_array, [2, 6, 3, 4, 8, 9, 5])
    call assert(test_passed)

    ! Test 5
    allocate(test_array(7))
    test_array = [5, 8, 3, 4, 6, 9, 2]
    result_array = sort_third(test_array)
    test_passed = issame(result_array, [2, 8, 3, 4, 6, 9, 5])
    call assert(test_passed)

    ! Test 6
    allocate(test_array(7))
    test_array = [5, 6, 9, 4, 8, 3, 2]
    result_array = sort_third(test_array)
    test_passed = issame(result_array, [2, 6, 9, 4, 8, 3, 5])
    call assert(test_passed)

    ! Test 7
    allocate(test_array(8))
    test_array = [5, 6, 3, 4, 8, 9, 2, 1]
    result_array = sort_third(test_array)
    test_passed = issame(result_array, [2, 6, 3,
