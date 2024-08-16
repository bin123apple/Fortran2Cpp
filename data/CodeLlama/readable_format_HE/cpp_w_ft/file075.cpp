Translating the provided Fortran code to C++ involves several steps, including adapting the syntax, changing array handling, and implementing the logic for sorting and testing. Here's a C++ version of the code:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

std::vector<int> sort_array(const std::vector<int>& array) {
    std::vector<int> out = array;
    int n = out.size();

    if (n == 0) {
        return out;
    }

    // Bubble sort implementation
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (out[j] > out[j + 1]) {
                std::swap(out[j], out[j + 1]);
            }
        }
    }

    if (out[0] + out[n - 1] % 2 == 1) {
        return out;
    } else {
        std::reverse(out.begin(), out.end());
    }

    return out;
}

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

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

void test_cases() {
    assert(issame(sort_array({0}), {0}));
    assert(issame(sort_array({5}), {5}));
    assert(issame(sort_array({2, 4, 3, 0, 1, 5}), {0, 1, 2, 3, 4, 5}));
    assert(issame(sort_array({2, 4, 3, 0, 1, 5, 6}), {6, 5, 4, 3, 2, 1, 0}));
    assert(issame(sort_array({2, 1}), {1, 2}));
    assert(issame(sort_array({15, 42, 87, 32, 11, 0}), {0, 11, 15, 32, 42, 87}));
    assert(issame(sort_array({21, 14, 23, 11}), {23, 21, 14, 11}));
}

int main() {
    test_cases();
    return 0;
}
```

### Key Points:

1. **Array Handling**: C++ uses `std::vector<int>` for dynamic arrays, which is more flexible and safer compared to raw arrays.

2. **Sorting Algorithm**: The bubble sort algorithm is implemented directly in the `sort_array` function.

3. **Logic for Odd-Even Sort**: The logic for the odd-even sort is preserved, but note that C++ uses zero-based indexing.

4. **Assertion and Testing**: The `assert` function and `test_cases` subroutine are implemented similarly to the Fortran version, but in C++.

5. **Main Function**: The `main` function in C++ is used to call the `test_cases` function, similar to the Fortran program structure.

This C++ code should provide the same functionality as the original Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the sorting and comparison functionalities.

### Fortran Unit Test Code

```fortran
program test_main
    implicit none
    integer, dimension(:), allocatable :: array, sorted_array, expected_array
    integer :: i
    logical :: result

    call test_cases()

contains

    function sort_array(array) result(out)
        integer, dimension(:), intent(in) :: array
        integer, dimension(:), allocatable :: out
        integer :: n, i, j, temp

        n = size(array)
        if (n == 0) then
            allocate(out(0))
            return
        end if

        allocate(out(n))
        out = array

        ! Bubble sort implementation
        do i = 1, n-1
            do j = 1, n-i
                if (out(j) > out(j+1)) then
                    temp = out(j)
                    out(j) = out(j+1)
                    out(j+1) = temp
                end if
            end do
        end do

        if (mod(out(1) + out(n), 2) == 1) then
            return
        else
            out = out(n:1:-1)
        end if
    end function sort_array

    function issame(a, b) result(is_equal)
        integer, dimension(:), intent(in) :: a, b
        logical :: is_equal
        integer :: i

        if (size(a) /= size(b)) then
            is_equal = .false.
            return
        end if

        is_equal = .true.
        do i = 1, size(a)
            if (a(i) /= b(i)) then
                is_equal = .false.
                return
            end if
        end do
    end function issame

    subroutine assert(condition)
        logical, intent(in) :: condition
        if (.not. condition) then
            write(*,*) "Assertion failed"
            call exit(1)
        end if
    end subroutine assert

    subroutine test_cases
        call assert(issame(sort_array([0]), [0]))
        call assert(issame(sort_array([5]), [5]))
        call assert(issame(sort_array([2, 4, 3, 0, 1, 5]), [0, 1, 2, 3, 4, 5]))
        call assert(issame(sort_array([2, 4, 3, 0, 1, 5, 6]), [6, 5, 4, 3, 2, 1, 0]))
        call assert(issame(sort_array([2, 1]), [1, 2]))
        call assert(issame(sort_array([15, 42, 87, 32, 11, 0]), [0, 11, 15, 32, 42, 87]))
        call assert(issame(sort_array([21, 14, 23, 11]), [23, 21, 14, 11]))
    end subroutine test_cases

end program test_main
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

std::vector<int> sort_array(const std::vector<int>& array) {
    std::vector<int> out = array;
    int n = out.size();

    if (n == 0) {
        return out;
    }

    // Bubble sort implementation
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (out[j] > out[j + 1]) {
                std::swap(out[j], out[j + 1]);
            }
        }
    }

    if (out[0] + out[n - 1] % 2 == 1) {
        return out;
    } else {
        std::reverse(out.begin(), out.end());
    }

    return out;
}

bool issame(const std::vector<int>& a, const std::vector
