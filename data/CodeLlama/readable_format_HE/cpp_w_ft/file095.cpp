Translating the provided Fortran code to C++ involves several steps, including changing array handling, subroutine and function definitions, and the way assertions are handled. Here's a C++ version of the code:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

void bubble_sort(std::vector<int>& arr) {
    int temp;
    for (int i = 0; i < arr.size() - 1; ++i) {
        for (int j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

std::vector<int> maximum(const std::vector<int>& arr, int k) {
    std::vector<int> sorted_arr = arr;
    bubble_sort(sorted_arr);
    return std::vector<int>(sorted_arr.rbegin(), sorted_arr.rbegin() + k);
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

void run_tests() {
    assert(issame(maximum({-3, -4, 5}, 3), {-4, -3, 5}));
    assert(issame(maximum({4, -4, 4}, 2), {4, 4}));
    assert(issame(maximum({-3, 2, 1, 2, -1, -2, 1}, 1), {2}));
    assert(issame(maximum({123, -123, 20, 0, 1, 2, -3}, 3), {2, 20, 123}));
    assert(issame(maximum({-123, 20, 0, 1, 2, -3}, 4), {0, 1, 2, 20}));
    assert(issame(maximum({5, 15, 0, 3, -13, -8, 0}, 7), {-13, -8, 0, 0, 3, 5, 15}));
    assert(issame(maximum({-1, 0, 2, 5, 3, -10}, 2), {3, 5}));
    assert(issame(maximum({1, 0, 5, -7}, 1), {5}));
    assert(issame(maximum({4, -4}, 2), {-4, 4}));
    assert(issame(maximum({-10, 10}, 2), {-10, 10}));
    // Handle the empty array case separately
    assert(issame(maximum({1, 2, 3, -23, 243, -400, 0}, 0), {}));
}

int main() {
    run_tests();
    return 0;
}
```

### Key Differences and Considerations:

1. **Array Handling**: C++ uses `std::vector<int>` for dynamic arrays, which is more flexible and safer compared to raw arrays.
2. **Sorting**: The `bubble_sort` function uses nested loops to compare and swap elements, similar to the Fortran version.
3. **Maximum Function**: The `maximum` function sorts the array and returns the last `k` elements in reverse order.
4. **Assertions**: The `assert` function checks a condition and prints an error message if the condition is false, then exits the program.
5. **Testing**: The `run_tests` function contains several assertions to verify the correctness of the `maximum` and `bubble_sort` functions.
6. **Empty Array Case**: The C++ version handles the empty array case by returning an empty vector, which matches the Fortran behavior.

This C++ code should behave similarly to the provided Fortran code, ensuring the same functionality and correctness through the unit tests.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `bubble_sort`, `maximum`, and `issame` functions.

### Fortran Unit Test Code

```fortran
program test_main
    implicit none
    integer, dimension(:), allocatable :: expected

    call run_tests()

contains

    subroutine bubble_sort(arr)
        integer, dimension(:), intent(inout) :: arr
        integer :: i, j, temp
        do i = 1, size(arr) - 1
            do j = 1, size(arr) - i
                if (arr(j) > arr(j + 1)) then
                    temp = arr(j)
                    arr(j) = arr(j + 1)
                    arr(j + 1) = temp
                end if
            end do
        end do
    end subroutine bubble_sort

    function maximum(arr, k) result(out)
        integer, dimension(:), intent(in) :: arr
        integer, intent(in) :: k
        integer, dimension(:), allocatable :: out
        integer, dimension(:), allocatable :: sorted_arr
        integer :: n

        n = size(arr)
        allocate(sorted_arr(n))
        sorted_arr = arr
        call bubble_sort(sorted_arr)
        allocate(out(k))
        out = sorted_arr(n-k+1:n)
    end function maximum

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

    subroutine run_tests()
        integer, dimension(:), allocatable :: expected

        call assert(issame(maximum([-3, -4, 5], 3), [-4, -3, 5]))
        call assert(issame(maximum([4, -4, 4], 2), [4, 4]))
        call assert(issame(maximum([-3, 2, 1, 2, -1, -2, 1], 1), [2]))
        call assert(issame(maximum([123, -123, 20, 0, 1, 2, -3], 3), [2, 20, 123]))
        call assert(issame(maximum([-123, 20, 0, 1, 2, -3], 4), [0, 1, 2, 20]))
        call assert(issame(maximum([5, 15, 0, 3, -13, -8, 0], 7), [-13, -8, 0, 0, 3, 5, 15]))
        call assert(issame(maximum([-1, 0, 2, 5, 3, -10], 2), [3, 5]))
        call assert(issame(maximum([1, 0,
