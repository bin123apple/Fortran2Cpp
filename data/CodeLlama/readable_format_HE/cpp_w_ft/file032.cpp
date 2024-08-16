Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the necessary headers and uses the standard library for array operations and sorting.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<float> sort_even(const std::vector<float>& l) {
    std::vector<float> out(l.size());
    std::vector<float> even(l.size() / 2 + l.size() % 2);

    // Extract even-indexed elements
    for (size_t i = 0; i < even.size(); ++i) {
        even[i] = l[i * 2];
    }

    // Sort the even-indexed elements
    std::sort(even.begin(), even.end());

    // Merge sorted even-indexed elements back into the output array
    for (size_t i = 0; i < l.size(); ++i) {
        if (i % 2 == 0) {
            out[i] = even[i / 2];
        } else {
            out[i] = l[i];
        }
    }

    return out;
}

void sort_array(std::vector<float>& arr) {
    std::sort(arr.begin(), arr.end());
}

bool issame(const std::vector<float>& a, const std::vector<float>& b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (size_t i = 0; i < a.size(); ++i) {
        if (std::abs(a[i] - b[i]) > 1e-4) {
            return false;
        }
    }

    return true;
}

void run_tests() {
    // Test case 1
    std::vector<float> l = {1.0, 2.0, 3.0};
    std::vector<float> expected = {1.0, 2.0, 3.0};
    std::vector<float> result = sort_even(l);
    if (!issame(result, expected)) {
        std::cerr << "Test case 1 failed" << std::endl;
        std::exit(1);
    }

    // Test case 2
    l = {5.0, 3.0, -5.0, 2.0, -3.0, 3.0, 9.0, 0.0, 123.0, 1.0, -10.0};
    expected = {-10.0, 3.0, -5.0, 2.0, -3.0, 3.0, 5.0, 0.0, 9.0, 1.0, 123.0};
    result = sort_even(l);
    if (!issame(result, expected)) {
        std::cerr << "Test case 2 failed" << std::endl;
        std::exit(1);
    }

    // Test case 3
    l = {5.0, 8.0, -12.0, 4.0, 23.0, 2.0, 3.0, 11.0, 12.0, -10.0};
    expected = {-12.0, 8.0, 3.0, 4.0, 5.0, 2.0, 12.0, 11.0, 23.0, -10.0};
    result = sort_even(l);
    if (!issame(result, expected)) {
        std::cerr << "Test case 3 failed" << std::endl;
        std::exit(1);
    }

    std::cout << "All test cases passed" << std::endl;
}

int main() {
    run_tests();
    return 0;
}
```

This C++ code defines the `sort_even` function, which sorts the elements of an array based on their even indices, and the `sort_array` subroutine, which sorts an array using the standard library's `std::sort` function. The `issame` function checks if two vectors are approximately equal, and the `run_tests` function runs several test cases to verify the correctness of the `sort_even` function.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `sort_even` function in both languages.

### Fortran Unit Test Code

```fortran
program test_sort_even
    implicit none
    real, dimension(:), allocatable :: l, result, expected

    ! Test case 1
    allocate(l(3))
    l = [1.0, 2.0, 3.0]
    allocate(expected(3))
    expected = [1.0, 2.0, 3.0]
    result = sort_even(l)
    if (.not. issame(result, expected)) then
        write(*,*) "Test case 1 failed"
        call exit(1)
    end if
    deallocate(l, result, expected)

    ! Test case 2
    allocate(l(11))
    l = [5.0, 3.0, -5.0, 2.0, -3.0, 3.0, 9.0, 0.0, 123.0, 1.0, -10.0]
    allocate(expected(11))
    expected = [-10.0, 3.0, -5.0, 2.0, -3.0, 3.0, 5.0, 0.0, 9.0, 1.0, 123.0]
    result = sort_even(l)
    if (.not. issame(result, expected)) then
        write(*,*) "Test case 2 failed"
        call exit(1)
    end if
    deallocate(l, result, expected)

    ! Test case 3
    allocate(l(10))
    l = [5.0, 8.0, -12.0, 4.0, 23.0, 2.0, 3.0, 11.0, 12.0, -10.0]
    allocate(expected(10))
    expected = [-12.0, 8.0, 3.0, 4.0, 5.0, 2.0, 12.0, 11.0, 23.0, -10.0]
    result = sort_even(l)
    if (.not. issame(result, expected)) then
        write(*,*) "Test case 3 failed"
        call exit(1)
    end if
    deallocate(l, result, expected)

    write(*,*) "All test cases passed"

contains

    function sort_even(l) result(out)
        real, dimension(:), intent(in) :: l
        real, dimension(:), allocatable :: out, even
        integer :: i, n

        n = size(l)
        allocate(out(n))
        allocate(even((n+1)/2))

        ! Extract even-indexed elements
        do i = 1, (n+1)/2
            even(i) = l(2*i - 1)
        end do

        ! Sort the even-indexed elements
        call sort_array(even)

        ! Merge sorted even-indexed elements back into the output array
        do i = 1, n
            if (mod(i, 2) == 1) then
                out(i) = even((i+1)/2)
            else
                out(i) = l(i)
            end if
        end do
    end function sort_even

    subroutine sort_array(arr)
        real, dimension(:), intent(inout) :: arr
        integer :: i, j
        real :: temp
        integer :: n

        n = size(arr)
        do i = 1, n-1
            do j = i+1, n
                if (arr(i) > arr(j)) then
                    temp = arr(i)
                    arr(i) =
