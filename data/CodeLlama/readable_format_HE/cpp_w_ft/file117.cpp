Translating the given Fortran code to C++ involves several steps, including changing the syntax for loops, arrays, and function definitions. Here's how the Fortran code can be translated into C++:

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

// Function prototype
int64_t double_the_difference(const std::vector<double>& lst);
void assert(bool condition);

int main() {
    // Test cases
    assert(double_the_difference({0.0}) == 0);
    assert(double_the_difference({5.0, 4.0}) == 25);
    assert(double_the_difference({0.1, 0.2, 0.3}) == 0);
    assert(double_the_difference({-10.0, -20.0, -30.0}) == 0);
    assert(double_the_difference({-1.0, -2.0, 8.0}) == 0);
    assert(double_the_difference({0.2, 3.0, 5.0}) == 34);

    int64_t odd_sum = 0;
    std::vector<double> lst(100, 0.0);

    // Fill the array and calculate odd_sum
    for (int i = -99; i <= 99; i += 2) {
        lst[(i + 101) / 2] = static_cast<double>(i);
        if (i > 0 && i % 2 == 1) odd_sum += i * i;
    }

    // Check the final assertion
    int64_t result = double_the_difference(lst);
    assert(result == odd_sum);

    return 0;
}

int64_t double_the_difference(const std::vector<double>& lst) {
    int64_t sum = 0;
    for (size_t i = 0; i < lst.size(); ++i) {
        double rounded_value = std::round(lst[i]);
        if (std::abs(lst[i] - rounded_value) < 1e-4) {
            if (lst[i] > 0 && static_cast<int64_t>(std::round(rounded_value)) % 2 == 1) {
                sum += std::pow(static_cast<int64_t>(std::round(rounded_value)), 2);
            }
        }
    }
    return sum;
}

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}
```

### Key Changes:

1. **Data Types**: Fortran's `integer(8)` is equivalent to C++'s `int64_t` for 64-bit integers. The `real(8)` type in Fortran is equivalent to `double` in C++.

2. **Arrays**: Fortran's allocatable arrays are replaced with `std::vector<double>` in C++ for dynamic array functionality.

3. **Looping**: Fortran's `do` loop is replaced with a `for` loop in C++. The loop indices and conditions are adjusted to match C++ syntax.

4. **Math Functions**: Fortran's `nint` and `abs` functions are replaced with `std::round` and `std::abs` from the `<cmath>` header in C++.

5. **Assertions**: The `assert` subroutine in Fortran is replaced with a custom `assert` function in C++ that uses `std::cerr` for error output and `std::exit(1)` to terminate the program if the condition is false.

6. **Program Structure**: The `program` block in Fortran is replaced with the `main` function in C++. The `contains` section in Fortran is replaced by defining functions and variables before `main`.

This C++ code should provide equivalent functionality to the original Fortran code, with necessary adjustments for language syntax and conventions.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `double_the_difference` function and the overall logic in both implementations.

### Fortran Unit Test Code

To compile and run the Fortran unit test, you can use a Fortran compiler like `gfortran`. Save the following code in a file named `test_fortran.f90`:

```fortran
program test_fortran
    implicit none
    integer :: i
    real(8), allocatable :: lst(:)
    integer(8) :: odd_sum, result

    ! Test cases
    call assert(double_the_difference([real(0.0, 8)]) == 0)
    call assert(double_the_difference([5.0_8, 4.0_8]) == 25)
    call assert(double_the_difference([0.1_8, 0.2_8, 0.3_8]) == 0)
    call assert(double_the_difference([-10.0_8, -20.0_8, -30.0_8]) == 0)
    call assert(double_the_difference([-1.0_8, -2.0_8, 8.0_8]) == 0)
    call assert(double_the_difference([0.2_8, 3.0_8, 5.0_8]) == 34)

    ! Initialize variables
    odd_sum = 0
    allocate(lst(100))
    lst = 0.0_8

    ! Fill the array and calculate odd_sum
    do i = -99, 99, 2
        lst((i+101)/2) = real(i, 8)
        if (i > 0 .and. mod(i, 2) == 1) odd_sum = odd_sum + i*i
    end do

    ! Check the final assertion
    result = double_the_difference(lst)
    call assert(result == odd_sum)

contains

    function double_the_difference(lst) result(sum)
        implicit none
        real(8), intent(in) :: lst(:)
        integer(8) :: sum
        integer :: i
        real(8) :: rounded_value

        sum = 0
        do i = 1, size(lst)
            rounded_value = nint(lst(i))
            if (abs(lst(i) - rounded_value) < 1e-4) then
                if (lst(i) > 0 .and. mod(int(rounded_value), 2) == 1) then
                    sum = sum + int(rounded_value)**2
                end if
            end if
        end do
    end function double_the_difference

    subroutine assert(condition)
        logical, intent(in) :: condition
        if (.not. condition) then
            write(*,*) "Assertion failed"
            call exit(1)
        end if
    end subroutine assert

end program test_fortran
```

### C++ Unit Test Code

To compile and run the C++ unit test, you can use a C++ compiler like `g++`. Save the following code in a file named `test_cpp.cpp`:

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

// Function prototype
int64_t double_the_difference(const std::vector<double>& lst);
void assert(bool condition);

int main() {
    // Test cases
    assert(double_the_difference({0.0}) == 0);
    assert(double_the_difference({5.0, 4.0}) == 25);
    assert(double_the_difference({0.1, 0.2, 0.3}) == 0);
    assert(double_the_difference({-10.0, -20.0, -30.0}) == 0);
    assert(double_the_difference({-1.0, -2.0, 8.0}) == 0
