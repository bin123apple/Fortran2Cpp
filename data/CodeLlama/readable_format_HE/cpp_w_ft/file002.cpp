Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

float mean_absolute_deviation(const std::vector<float>& numbers) {
    int n = numbers.size();
    float sum = 0.0f;
    for (int i = 0; i < n; ++i) {
        sum += numbers[i];
    }
    float avg = sum / n;

    float msum = 0.0f;
    for (int i = 0; i < n; ++i) {
        msum += std::abs(numbers[i] - avg);
    }
    return msum / n;
}

int main() {
    // Test cases
    std::vector<float> test_case_1 = {1.0f, 2.0f, 3.0f};
    if (std::abs(mean_absolute_deviation(test_case_1) - 2.0f / 3.0f) > 1e-4) {
        std::cerr << "Assertion failed for test case 1" << std::endl;
        return 1;
    }

    std::vector<float> test_case_2 = {1.0f, 2.0f, 3.0f, 4.0f};
    if (std::abs(mean_absolute_deviation(test_case_2) - 1.0f) > 1e-4) {
        std::cerr << "Assertion failed for test case 2" << std::endl;
        return 1;
    }

    std::vector<float> test_case_3 = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    if (std::abs(mean_absolute_deviation(test_case_3) - 6.0f / 5.0f) > 1e-4) {
        std::cerr << "Assertion failed for test case 3" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;
    return 0;
}
```

This C++ code defines a function `mean_absolute_deviation` that computes the mean absolute deviation of a given vector of floats. The `main` function contains test cases that verify the correctness of the `mean_absolute_deviation` function with different input vectors.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `mean_absolute_deviation` function with different input vectors.

### Fortran Unit Tests

To run the Fortran unit tests, you need to save the Fortran code and the test program in a file, for example, `mad_test.f90`, and then compile and run it using a Fortran compiler like `gfortran`.

```fortran
! Save this as mad_module.f90
module mad_module
    implicit none
contains
    function mean_absolute_deviation(numbers) result(mad)
        implicit none
        real, dimension(:), intent(in) :: numbers
        real :: mad
        real :: sum, avg, msum
        integer :: i, n

        n = size(numbers)
        sum = 0.0
        do i = 1, n
            sum = sum + numbers(i)
        end do
        avg = sum / n

        msum = 0.0
        do i = 1, n
            msum = msum + abs(numbers(i) - avg)
        end do
        mad = msum / n
    end function mean_absolute_deviation
end module mad_module

! Save this as mad_test.f90
program mean_absolute_deviation_program
    use mad_module
    implicit none
    real :: result

    ! Test cases
    result = mean_absolute_deviation([1.0, 2.0, 3.0])
    if (abs(result - 2.0/3.0) > 1e-4) then
        write(*,*) "Assertion failed for test case 1"
        call exit(1)
    end if

    result = mean_absolute_deviation([1.0, 2.0, 3.0, 4.0])
    if (abs(result - 1.0) > 1e-4) then
        write(*,*) "Assertion failed for test case 2"
        call exit(1)
    end if

    result = mean_absolute_deviation([1.0, 2.0, 3.0, 4.0, 5.0])
    if (abs(result - 6.0/5.0) > 1e-4) then
        write(*,*) "Assertion failed for test case 3"
        call exit(1)
    end if

    write(*,*) "All test cases passed"
end program mean_absolute_deviation_program
```

Compile and run the Fortran code:

```sh
gfortran -o mad_test mad_module.f90 mad_test.f90
./mad_test
```

### C++ Unit Tests

To run the C++ unit tests, you need to save the C++ code in a file, for example, `mad_test.cpp`, and then compile and run it using a C++ compiler like `g++`.

```cpp
// Save this as mad_test.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

float mean_absolute_deviation(const std::vector<float>& numbers) {
    int n = numbers.size();
    float sum = 0.0f;
    for (int i = 0; i < n; ++i) {
        sum += numbers[i];
    }
    float avg = sum / n;

    float msum = 0.0f;
    for (int i = 0; i < n; ++i) {
        msum += std::abs(numbers[i] - avg);
    }
    return msum / n;
}

int main() {
    // Test cases
    std::vector<float> test_case_1 = {1.0f, 2.0f, 3.0f};
    if (std::abs(mean_absolute_deviation(test_case_1) - 2.0f / 3.0f) > 1e-4) {
        std::cerr << "Assertion failed for test case 1" << std::endl;
        return 1;
    }

    std::vector<float> test_case_2 = {1.0f, 2.0f, 3.0f, 4.0f};
    if (std::abs(mean_absolute_deviation(test_case_2) - 1.0f) > 1e-4) {
        std::cerr << "Assertion failed for test case 2" << std::endl;
        return 1;
    }

    std::vector<float> test_case_3 = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    if (std::abs(mean_absolute_deviation(test_case_3) - 6.0f / 5.0f) > 1e-4) {
        std::cerr << "Assertion failed for test case 3" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;
    return 0;
}
```

Compile and run the C++ code:

```sh
g++ -o mad_test mad_test.cpp
./mad_test
```

These unit tests will verify the correctness of the `mean_absolute_deviation` function in both Fortran and C++ implementations. If all tests pass, it indicates that the translation is correct.
