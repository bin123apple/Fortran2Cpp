Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the necessary headers and uses standard library features to achieve the same functionality as the original Fortran code.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

void intersperse(const std::vector<int>& numbers, int delimeter, std::vector<int>& out) {
    if (numbers.empty()) {
        out.clear();
        return;
    }
    out.resize(2 * numbers.size() - 1);
    out[0] = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        out[2 * i - 1] = delimeter;
        out[2 * i] = numbers[i];
    }
}

bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) {
        return false;
    }
    return std::equal(a.begin(), a.end(), b.begin());
}

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    std::vector<int> numbers, result, expected;
    int delimeter;

    // Test case 1
    numbers.clear();
    expected.clear();
    intersperse(numbers, 7, result);
    assert(issame(result, expected));

    // Test case 2
    numbers = {5, 6, 3, 2};
    expected = {5, 8, 6, 8, 3, 8, 2};
    intersperse(numbers, 8, result);
    assert(issame(result, expected));

    // Test case 3
    numbers = {2, 2, 2};
    expected = {2, 2, 2, 2, 2};
    intersperse(numbers, 2, result);
    assert(issame(result, expected));

    return 0;
}
```

This C++ code includes the following functionalities:

1. **Interspersing Numbers**: The `intersperse` function takes a vector of numbers and a delimiter, and returns a new vector with the numbers interspersed with the delimiter.
2. **Comparing Vectors**: The `issame` function compares two vectors to check if they contain the same elements.
3. **Assertions**: The `assert` function checks a condition and exits the program with an error message if the condition is false.

The `main` function contains three test cases similar to the Fortran code, verifying the functionality of the `intersperse` and `issame` functions.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will help verify the correctness of the translation.

### Fortran Unit Test Code

```fortran
program test_main
    implicit none
    integer, allocatable :: numbers(:), result(:), expected(:)
    integer :: delimeter

    ! Test case 1
    if (allocated(numbers)) deallocate(numbers)
    allocate(numbers(0))
    if (allocated(expected)) deallocate(expected)
    allocate(expected(0))
    call intersperse(numbers, 7, result)
    call assert(issame(result, expected))

    ! Test case 2
    if (allocated(numbers)) deallocate(numbers)
    allocate(numbers(4))
    numbers = [5, 6, 3, 2]
    if (allocated(expected)) deallocate(expected)
    allocate(expected(7))
    expected = [5, 8, 6, 8, 3, 8, 2]
    call intersperse(numbers, 8, result)
    call assert(issame(result, expected))

    ! Test case 3
    if (allocated(numbers)) deallocate(numbers)
    allocate(numbers(3))
    numbers = [2, 2, 2]
    if (allocated(expected)) deallocate(expected)
    allocate(expected(5))
    expected = [2, 2, 2, 2, 2]
    call intersperse(numbers, 2, result)
    call assert(issame(result, expected))

contains

    subroutine intersperse(numbers, delimeter, out)
        integer, intent(in) :: numbers(:)
        integer, intent(in) :: delimeter
        integer, allocatable, intent(out) :: out(:)
        integer :: i, n

        n = size(numbers)
        if (n == 0) then
            allocate(out(0))
        else
            allocate(out(2*n-1))
            out(1) = numbers(1)
            do i = 2, n
                out(2*i-2) = delimeter
                out(2*i-1) = numbers(i)
            end do
        end if
    end subroutine intersperse

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

void intersperse(const std::vector<int>& numbers, int delimeter, std::vector<int>& out) {
    if (numbers.empty()) {
        out.clear();
        return;
    }
    out.resize(2 * numbers.size() - 1);
    out[0] = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        out[2 * i - 1] = delimeter;
        out[2 * i] = numbers[i];
    }
}

bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) {
        return false;
    }
    return std::equal(a.begin(), a.end(), b.begin());
}

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    std::vector<int> numbers, result, expected;
    int delimeter;

    // Test case 1
    numbers.clear();
    expected.clear();
    intersperse(numbers, 7, result);
    assert(issame(result, expected));

    // Test case 2
    numbers = {5, 6, 3, 2};
    expected = {5, 8, 6, 8, 3, 8, 2};
    intersperse(numbers, 8, result);
    assert(issame(result, expected));

    // Test case 3
    numbers = {2, 2, 2};
    expected = {2, 2, 2, 2, 2};
    intersperse(numbers, 2, result);
    assert(issame(result, expected));

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}
```

### Explanation

- **Fortran Unit Test Code**: This code defines a main program that includes three test cases for the `intersperse` subroutine and the `issame` function
