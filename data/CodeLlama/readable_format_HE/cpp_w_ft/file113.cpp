Translating the provided Fortran code to C++ involves several steps, including handling dynamic arrays, string manipulation, and sorting algorithms. Below is the translated C++ code:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

std::vector<int> order_by_points(const std::vector<int>& nums) {
    if (nums.empty()) return nums;

    std::vector<int> sumdigit(nums.size());
    std::vector<int> sorted_nums = nums;

    for (size_t i = 0; i < nums.size(); ++i) {
        std::string w = std::to_string(std::abs(nums[i]));
        int sum = 0;
        for (size_t j = 1; j < w.length(); ++j) {
            sum += w[j] - '0';
        }
        if (nums[i] > 0) {
            sum += w[0] - '0';
        } else {
            sum -= w[0] - '0';
        }
        sumdigit[i] = sum;
    }

    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = 0; j < nums.size() - i - 1; ++j) {
            if (sumdigit[j] > sumdigit[j + 1]) {
                std::swap(sumdigit[j], sumdigit[j + 1]);
                std::swap(sorted_nums[j], sorted_nums[j + 1]);
            }
        }
    }

    return sorted_nums;
}

bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void assert_condition(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    std::vector<int> nums;
    std::vector<int> result;

    // Test case 1
    nums = {1, 11, -1, -11, -12};
    result = order_by_points(nums);
    assert_condition(issame(result, {-1, -11, 1, -12, 11}));

    // Test case 2
    nums = {1234, 423, 463, 145, 2, 423, 423, 53, 6, 37, 3457, 3, 56, 0, 46};
    result = order_by_points(nums);
    assert_condition(issame(result, {0, 2, 3, 6, 53, 423, 423, 423, 1234, 145, 37, 46, 56, 463, 3457}));

    // Test case 3
    nums = {};
    result = order_by_points(nums);
    assert_condition(issame(result, nums));

    // Test case 4
    nums = {1, -11, -32, 43, 54, -98, 2, -3};
    result = order_by_points(nums);
    assert_condition(issame(result, {-3, -32, -98, -11, 1, 2, 43, 54}));

    // Test case 5
    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    result = order_by_points(nums);
    assert_condition(issame(result, {1, 10, 2, 11, 3, 4, 5, 6, 7, 8, 9}));

    // Test case 6
    nums = {0, 6, 6, -76, -21, 23, 4};
    result = order_by_points(nums);
    assert_condition(issame(result, {-76, -21, 0, 4, 23, 6, 6}));

    return 0;
}
```

### Explanation:
1. **Dynamic Arrays**: In C++, we use `std::vector<int>` to handle dynamic arrays.
2. **String Manipulation**: The `std::string` class is used for string manipulation, especially for converting integers to strings and vice versa.
3. **Sorting**: The sorting logic is implemented using bubble sort.
4. **Assertions**: The `assert_condition` function checks the condition and prints an error message if the condition is false, similar to the Fortran `assert` subroutine.

This C++ code should behave similarly to the original Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_main
    implicit none
    integer, dimension(:), allocatable :: nums, result
    integer :: i

    ! Test cases
    call test_case_1()
    call test_case_2()
    call test_case_3()
    call test_case_4()
    call test_case_5()
    call test_case_6()

contains

    subroutine test_case_1()
        if (allocated(nums)) deallocate(nums)
        nums = [1, 11, -1, -11, -12]
        result = order_by_points(nums)
        call assert(issame(result, [-1, -11, 1, -12, 11]))
    end subroutine test_case_1

    subroutine test_case_2()
        if (allocated(nums)) deallocate(nums)
        nums = [1234, 423, 463, 145, 2, 423, 423, 53, 6, 37, 3457, 3, 56, 0, 46]
        result = order_by_points(nums)
        call assert(issame(result, [0, 2, 3, 6, 53, 423, 423, 423, 1234, 145, 37, 46, 56, 463, 3457]))
    end subroutine test_case_2

    subroutine test_case_3()
        if (allocated(nums)) deallocate(nums)
        allocate(nums(0))
        result = order_by_points(nums)
        call assert(issame(result, nums))
    end subroutine test_case_3

    subroutine test_case_4()
        if (allocated(nums)) deallocate(nums)
        nums = [1, -11, -32, 43, 54, -98, 2, -3]
        result = order_by_points(nums)
        call assert(issame(result, [-3, -32, -98, -11, 1, 2, 43, 54]))
    end subroutine test_case_4

    subroutine test_case_5()
        if (allocated(nums)) deallocate(nums)
        nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
        result = order_by_points(nums)
