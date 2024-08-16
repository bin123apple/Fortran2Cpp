Translating the provided Fortran code to C++ involves several steps, including changing the syntax for loops, array handling, and function definitions. Here's how the Fortran code can be translated into C++:

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

std::vector<int> sort_array(const std::vector<int>& arr) {
    std::vector<int> sorted_arr(arr.size());
    std::vector<int> bin(arr.size());

    // Copy input array to sorted_arr
    sorted_arr = arr;

    // Calculate the number of 1s in the binary representation of each element
    for (size_t i = 0; i < arr.size(); ++i) {
        int b = 0;
        int n = std::abs(arr[i]);
        while (n > 0) {
            b += n % 2;
            n /= 2;
        }
        bin[i] = b;
    }

    // Sort the array based on the bin values and the original values
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = 1; j < arr.size(); ++j) {
            if (bin[j] < bin[j - 1] || (bin[j] == bin[j - 1] && sorted_arr[j] < sorted_arr[j - 1])) {
                std::swap(sorted_arr[j], sorted_arr[j - 1]);
                std::swap(bin[j], bin[j - 1]);
            }
        }
    }

    return sorted_arr;
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

void test_case(const std::vector<int>& arr, const std::vector<int>& expected) {
    std::vector<int> sorted_arr = sort_array(arr);
    if (!issame(sorted_arr, expected)) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

void run_tests() {
    // Test cases
    test_case({1, 5, 2, 3, 4}, {1, 2, 4, 3, 5});
    test_case({-2, -3, -4, -5, -6}, {-4, -2, -6, -5, -3});
    test_case({1, 0, 2, 3, 4}, {0, 1, 2, 4, 3});
    test_case({2, 5, 77, 4, 5, 3, 5, 7, 2, 3, 4}, {2, 2, 4, 4, 3, 3, 5, 5, 5, 7, 77});
    test_case({3, 6, 44, 12, 32, 5}, {32, 3, 5, 6, 12, 44});
    test_case({2, 4, 8, 16, 32}, {2, 4, 8, 16, 32});
    test_case({2, 4, 8, 16, 32}, {2, 4, 8, 16, 32});
}

int main() {
    run_tests();
    return 0;
}
```

### Key Differences and Considerations:

1. **Array Handling**: C++ uses `std::vector` for dynamic arrays, which is more flexible and safer compared to raw arrays.
2. **Looping**: The `for` loop syntax in C++ is different from Fortran. The loop variables are declared within the `for` statement.
3. **Binary Representation**: The binary representation calculation is similar, but C++ uses different operators and functions (`%` for modulus, `/` for division).
4. **Sorting**: The sorting logic is preserved, but the syntax for swapping elements is different (`std::swap`).
5. **Testing**: The `test_case` function in C++ checks if the sorted array matches the expected array and reports an error if they do not match.
6. **Program Structure**: The `main` function in C++ serves as the entry point, similar to the `program` block in Fortran. The `run_tests` function contains the test cases.

This C++ code should compile and run similarly to the provided Fortran code, ensuring the same functionality and output.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `sort_array` function and the `issame` function.

### Fortran Unit Test Code

```fortran
program test_main
    implicit none

    call run_tests()

contains

    function sort_array(arr) result(sorted_arr)
        integer, dimension(:), intent(in) :: arr
        integer, dimension(:), allocatable :: sorted_arr
        integer, dimension(:), allocatable :: bin
        integer :: i, j, n, b, m

        allocate(sorted_arr(size(arr)))
        allocate(bin(size(arr)))

        ! Copy input array to sorted_arr
        sorted_arr = arr

        ! Calculate the number of 1s in the binary representation of each element
        do i = 1, size(arr)
            b = 0
            n = abs(arr(i))
            do while (n > 0)
                b = b + mod(n, 2)
                n = n / 2
            end do
            bin(i) = b
        end do

        ! Sort the array based on the bin values and the original values
        do i = 1, size(arr)
            do j = 2, size(arr)
                if (bin(j) < bin(j-1) .or. (bin(j) == bin(j-1) .and. sorted_arr(j) < sorted_arr(j-1))) then
                    m = sorted_arr(j)
                    sorted_arr(j) = sorted_arr(j-1)
                    sorted_arr(j-1) = m
                    m = bin(j)
                    bin(j) = bin(j-1)
                    bin(j-1) = m
                end if
            end do
        end do
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

    subroutine test_case(arr, expected)
        integer, dimension(:), intent(in) :: arr, expected
        integer, dimension(:), allocatable :: sorted_arr

        sorted_arr = sort_array(arr)
        if (.not. issame(sorted_arr, expected)) then
            write(*,*) "Assertion failed"
            call exit(1)
        end if
    end subroutine test_case

    subroutine run_tests()
        ! Test cases
        call test_case([1, 5, 2, 3, 4], [1, 2, 4, 3, 5])
        call test_case([-2, -3, -4, -5, -6], [-4, -2, -6, -5, -3])
        call test_case([1, 0, 2, 3, 4], [0, 1, 2, 4, 3])
