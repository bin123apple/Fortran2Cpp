Translating the provided Fortran code to C++ involves a few steps, including adapting the array handling, function definitions, and I/O operations to C++ conventions. Here's how the Fortran code could be translated into C++:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<float> rescale_to_unit(const std::vector<float>& numbers) {
    std::vector<float> rescaled(numbers.size());
    float min_val = *std::min_element(numbers.begin(), numbers.end());
    float max_val = *std::max_element(numbers.begin(), numbers.end());

    for (size_t i = 0; i < numbers.size(); ++i) {
        rescaled[i] = (numbers[i] - min_val) / (max_val - min_val);
    }

    return rescaled;
}

bool issame(const std::vector<float>& a, const std::vector<float>& b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (size_t i = 0; i < a.size(); ++i) {
        if (std::abs(a[i] - b[i]) > 1.0e-4) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<float> numbers;
    std::vector<float> result;
    std::vector<float> expected1 = {0.0, 1.0};
    std::vector<float> expected2 = {1.0, 0.0};
    std::vector<float> expected3 = {0.0, 0.25, 0.5, 0.75, 1.0};
    std::vector<float> expected4 = {0.25, 0.0, 1.0, 0.5, 0.75};
    std::vector<float> expected5 = {0.25, 0.0, 1.0, 0.5, 0.75};

    // Test case 1
    numbers = {2.0, 49.9};
    result = rescale_to_unit(numbers);
    if (!issame(result, expected1)) {
        std::cerr << "Assertion failed for test case 1" << std::endl;
        return 1;
    }

    // Test case 2
    numbers = {100.0, 49.9};
    result = rescale_to_unit(numbers);
    if (!issame(result, expected2)) {
        std::cerr << "Assertion failed for test case 2" << std::endl;
        return 1;
    }

    // Test case 3
    numbers = {1.0, 2.0, 3.0, 4.0, 5.0};
    result = rescale_to_unit(numbers);
    if (!issame(result, expected3)) {
        std::cerr << "Assertion failed for test case 3" << std::endl;
        return 1;
    }

    // Test case 4
    numbers = {2.0, 1.0, 5.0, 3.0, 4.0};
    result = rescale_to_unit(numbers);
    if (!issame(result, expected4)) {
        std::cerr << "Assertion failed for test case 4" << std::endl;
        return 1;
    }

    // Test case 5
    numbers = {12.0, 11.0, 15.0, 13.0, 14.0};
    result = rescale_to_unit(numbers);
    if (!issame(result, expected5)) {
        std::cerr << "Assertion failed for test case 5" << std::endl;
        return 1;
    }

    std::cout << "All tests passed successfully" << std::endl;
    return 0;
}
```

This C++ code includes the necessary headers, uses `std::vector` for dynamic arrays, and defines the `rescale_to_unit` and `issame` functions to perform the same operations as the Fortran code. The `main` function contains the test cases, similar to the Fortran program. Note that C++ uses zero-based indexing, but since the code here is directly translated from Fortran, the indexing starts from 0 as well.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write unit tests that cover the specified test cases. Below are the unit test codes for both languages.

### Fortran Unit Test Code

To test the Fortran code, we can create a separate program that calls the `rescale_to_unit` function with different inputs and checks if the outputs match the expected results.

```fortran
program test_rescale_unit
    implicit none
    real, allocatable :: numbers(:), result(:)
    real, dimension(2) :: expected1 = [0.0, 1.0]
    real, dimension(2) :: expected2 = [1.0, 0.0]
    real, dimension(5) :: expected3 = [0.0, 0.25, 0.5, 0.75, 1.0]
    real, dimension(5) :: expected4 = [0.25, 0.0, 1.0, 0.5, 0.75]
    real, dimension(5) :: expected5 = [0.25, 0.0, 1.0, 0.5, 0.75]

    ! Test case 1
    allocate(numbers(2))
    numbers = [2.0, 49.9]
    result = rescale_to_unit(numbers)
    if (.not. issame(result, expected1)) then
        write(*,*) "Test case 1 failed"
    else
        write(*,*) "Test case 1 passed"
    end if
    deallocate(numbers)

    ! Test case 2
    allocate(numbers(2))
    numbers = [100.0, 49.9]
    result = rescale_to_unit(numbers)
    if (.not. issame(result, expected2)) then
        write(*,*) "Test case 2 failed"
    else
        write(*,*) "Test case 2 passed"
    end if
    deallocate(numbers)

    ! Test case 3
    allocate(numbers(5))
    numbers = [1.0, 2.0, 3.0, 4.0, 5.0]
    result = rescale_to_unit(numbers)
    if (.not. issame(result, expected3)) then
        write(*,*) "Test case 3 failed"
    else
        write(*,*) "Test case 3 passed"
    end if
    deallocate(numbers)

    ! Test case 4
    allocate(numbers(5))
    numbers = [2.0, 1.0, 5.0, 3.0, 4.0]
    result = rescale_to_unit(numbers)
    if (.not. issame(result, expected4)) then
        write(*,*) "Test case 4 failed"
    else
        write(*,*) "Test case 4 passed"
    end if
    deallocate(numbers)

    ! Test case 5
    allocate(numbers(5))
    numbers = [12.0, 11.0, 15.0, 13.0, 14.0]
    result = rescale_to_unit(numbers)
    if (.not. issame(result, expected5)) then
        write(*,*) "Test case 5 failed"
    else
        write(*,*) "Test case 5 passed"
    end if
    deallocate(numbers)

contains

    function rescale_to_unit(numbers) result(rescaled)
        implicit none
        real, intent(in) :: numbers(:)
        real, allocatable :: rescaled(:)
        real :: min_val, max_val
        integer :: i

        allocate(rescaled(size(numbers)))
        min_
