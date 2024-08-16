Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<float> find_closest_elements(const std::vector<float>& numbers) {
    std::vector<float> out(2, 0.0f);
    float min_diff = std::numeric_limits<float>::infinity();

    for (size_t i = 0; i < numbers.size(); ++i) {
        for (size_t j = i + 1; j < numbers.size(); ++j) {
            float diff = std::abs(numbers[i] - numbers[j]);
            if (diff < min_diff) {
                out[0] = numbers[i];
                out[1] = numbers[j];
                min_diff = diff;
            }
        }
    }

    if (out[0] > out[1]) {
        std::swap(out[0], out[1]);
    }

    return out;
}

bool issame(const std::vector<float>& a, const std::vector<float>& b, float epsilon = 1e-4) {
    if (a.size() != b.size()) {
        return false;
    }

    for (size_t i = 0; i < a.size(); ++i) {
        if (std::abs(a[i] - b[i]) > epsilon) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<float> test1 = {1.0, 2.0, 3.9, 4.0, 5.0, 2.2};
    std::vector<float> test2 = {1.0, 2.0, 5.9, 4.0, 5.0};
    std::vector<float> test3 = {1.0, 2.0, 3.0, 4.0, 5.0, 2.2};
    std::vector<float> test4 = {1.0, 2.0, 3.0, 4.0, 5.0, 2.0};
    std::vector<float> test5 = {1.1, 2.2, 3.1, 4.1, 5.1};

    std::vector<float> result;

    result = find_closest_elements(test1);
    if (!issame(result, {3.9, 4.0})) {
        std::cerr << "Assertion failed for test1" << std::endl;
        return 1;
    }

    result = find_closest_elements(test2);
    if (!issame(result, {5.0, 5.9})) {
        std::cerr << "Assertion failed for test2" << std::endl;
        return 1;
    }

    result = find_closest_elements(test3);
    if (!issame(result, {2.0, 2.2})) {
        std::cerr << "Assertion failed for test3" << std::endl;
        return 1;
    }

    result = find_closest_elements(test4);
    if (!issame(result, {2.0, 2.0})) {
        std::cerr << "Assertion failed for test4" << std::endl;
        return 1;
    }

    result = find_closest_elements(test5);
    if (!issame(result, {2.2, 3.1})) {
        std::cerr << "Assertion failed for test5" << std::endl;
        return 1;
    }

    std::cout << "All tests passed" << std::endl;

    return 0;
}
```

This C++ code includes the necessary headers and uses the standard library features such as `std::vector` for dynamic arrays and `std::abs` for calculating the absolute value. The `find_closest_elements` function and the `issame` function are implemented similarly to the Fortran code, with adjustments for C++ syntax and conventions.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `find_closest_elements` and `issame` functions.

### Fortran Unit Test Code

```fortran
module utils
    implicit none
    contains

    function find_closest_elements(numbers) result(out)
        implicit none
        real, dimension(:), intent(in) :: numbers
        real, dimension(:), allocatable :: out
        integer :: i, j
        real :: min_diff

        allocate(out(2))
        out = [0.0, 0.0]
        min_diff = huge(1.0)

        do i = 1, size(numbers)
            do j = i + 1, size(numbers)
                if (abs(numbers(i) - numbers(j)) < min_diff) then
                    out = [numbers(i), numbers(j)]
                    min_diff = abs(numbers(i) - numbers(j))
                end if
            end do
        end do

        if (out(1) > out(2)) then
            out = [out(2), out(1)]
        end if
    end function find_closest_elements

    logical function issame(a, b)
        implicit none
        real, dimension(:), intent(in) :: a, b
        integer :: i

        if (size(a) /= size(b)) then
            issame = .false.
            return
        end if

        do i = 1, size(a)
            if (abs(a(i) - b(i)) > 1e-4) then
                issame = .false.
                return
            end if
        end do

        issame = .true.
    end function issame

end module utils

program main
    use utils
    implicit none
    real, dimension(:), allocatable :: result
    real, dimension(6) :: test1 = [1.0, 2.0, 3.9, 4.0, 5.0, 2.2]
    real, dimension(5) :: test2 = [1.0, 2.0, 5.9, 4.0, 5.0]
    real, dimension(6) :: test3 = [1.0, 2.0, 3.0, 4.0, 5.0, 2.2]
    real, dimension(6) :: test4 = [1.0, 2.0, 3.0, 4.0, 5.0, 2.0]
    real, dimension(5) :: test5 = [1.1, 2.2, 3.1, 4.1, 5.1]

    allocate(result(2))
    result = find_closest_elements(test1)
    if (.not. issame(result, [3.9, 4.0])) then
        write(*,*) "Assertion failed for test1"
        call exit(1)
    end if

    result = find_closest_elements(test2)
    if (.not. issame(result, [5.0, 5.9])) then
        write(*,*) "Assertion failed for test2"
        call exit(1)
    end if

    result = find_closest_elements(test3)
    if (.not. issame(result, [2.0, 2.2])) then
        write(*,*) "Assertion failed for test3"
        call exit(1)
    end if

    result = find_closest_elements(test4)
    if (.not. issame(result, [2.0, 2.0])) then
        write(*,*) "Assertion failed for test4"
        call exit(1)
    end if

    result = find_closest_elements(test5)
    if (.not. issame(result, [2.2, 3.1])) then
        write(*,*) "Assertion failed for test5"
        call exit(1)
    end if

    write(*,*) "All tests passed"
    deallocate(result)
end program main
```
