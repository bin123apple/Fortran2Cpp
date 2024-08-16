Translating the provided Fortran code to C++ involves a few steps, including handling dynamic arrays, translating subroutines and functions, and adapting the testing framework. Here's how you can translate the Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

// Function to find the rolling maximum
void rolling_max(const std::vector<int>& numbers, std::vector<int>& out) {
    int max = 0;
    for (int num : numbers) {
        if (num > max) max = num;
        out.push_back(max);
    }
}

// Function to check if two vectors are the same
bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Assert function to check conditions
void assert_condition(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test case 1
    std::vector<int> numbers{};
    std::vector<int> result;
    std::vector<int> expected{};
    rolling_max(numbers, result);
    assert_condition(issame(result, expected));

    // Test case 2
    numbers = {1, 2, 3, 4};
    expected = {1, 2, 3, 4};
    rolling_max(numbers, result);
    assert_condition(issame(result, expected));

    // Test case 3
    numbers = {4, 3, 2, 1};
    expected = {4, 4, 4, 4};
    rolling_max(numbers, result);
    assert_condition(issame(result, expected));

    // Test case 4
    numbers = {3, 2, 3, 100, 3};
    expected = {3, 3, 3, 100, 100};
    rolling_max(numbers, result);
    assert_condition(issame(result, expected));

    return 0;
}
```

### Explanation:

1. **Dynamic Arrays**: In C++, we use `std::vector<int>` to handle dynamic arrays.
2. **Rolling Maximum**: The `rolling_max` function iterates through the input array and maintains the maximum value seen so far, appending it to the output array.
3. **Test Cases**: The `main` function contains test cases that verify the correctness of the `rolling_max` function.
4. **Assertion**: The `assert_condition` function checks if the condition is met. If not, it prints an error message and exits with a non-zero status.

This C++ code should behave similarly to the original Fortran code, ensuring the same functionality and output.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_main
    implicit none
    integer, allocatable :: numbers(:), result(:), expected(:)

    ! Test case 1
    if (allocated(numbers)) deallocate(numbers)
    allocate(numbers(0))
    if (allocated(expected)) deallocate(expected)
    allocate(expected(0))
    call rolling_max(numbers, result)
    call assert(issame(result, expected))

    ! Test case 2
    if (allocated(numbers)) deallocate(numbers)
    allocate(numbers(4))
    numbers = [1, 2, 3, 4]
    if (allocated(expected)) deallocate(expected)
    allocate(expected(4))
    expected = [1, 2, 3, 4]
    call rolling_max(numbers, result)
    call assert(issame(result, expected))

    ! Test case 3
    if (allocated(numbers)) deallocate(numbers)
    allocate(numbers(4))
    numbers = [4, 3, 2, 1]
    if (allocated(expected)) deallocate(expected)
    allocate(expected(4))
    expected = [4, 4, 4, 4]
    call rolling_max(numbers, result)
    call assert(issame(result, expected))

    ! Test case 4
    if (allocated(numbers)) deallocate(numbers)
    allocate(numbers(5))
    numbers = [3, 2, 3, 100, 3]
    if (allocated(expected)) deallocate(expected)
    allocate(expected(5))
    expected = [3, 3, 3, 100, 100]
    call rolling_max(numbers, result)
    call assert(issame(result, expected))

contains

    subroutine rolling_max(numbers, out)
        integer, intent(in) :: numbers(:)
        integer, allocatable, intent(out) :: out(:)
        integer :: i, max

        if (allocated(out)) deallocate(out)
        allocate(out(size(numbers)))
        max = 0
        do i = 1, size(numbers)
            if (numbers(i) > max) max = numbers(i)
            out(i) = max
        end do
    end subroutine rolling_max

    logical function issame(a, b)
        integer, intent(in) :: a(:), b(:)
        integer :: i

        if (size(a) /= size(b)) then
            issame = .false.
            return
        end if

        do i = 1, size(a)
            if (a(i) /= b(i)) then
                issame = .false.
                return
            end if
        end do

        issame = .true.
    end function issame

    subroutine assert(condition)
        logical, intent(in) :: condition
        if (.not. condition) then
            write(*,*) "Assertion failed"
            call exit(1)
        end if
    end subroutine assert

end program test_main
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

// Function to find the rolling maximum
void rolling_max(const std::vector<int>& numbers, std::vector<int>& out) {
    int max = 0;
    for (int num : numbers) {
        if (num > max) max = num;
        out.push_back(max);
    }
}

// Function to check if two vectors are the same
bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Assert function to check conditions
void assert_condition(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test case 1
    std::vector<int> numbers{};
    std::vector<int> result;
    std::vector<int> expected{};
    rolling_max(numbers, result);
    assert_condition(issame(result, expected));

    // Test case 2
    numbers = {1, 2, 3, 4};
    expected = {1, 2, 3, 4};
    rolling_max(numbers, result);
    assert_condition(issame(result, expected));

    // Test case 3
    numbers = {4, 3, 2, 1};
    expected = {4, 4, 4, 4};
    rolling_max(numbers, result);
    assert_condition(issame(result,
