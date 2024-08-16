Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the necessary headers and uses modern C++ standards for better code readability and maintainability.

```cpp
#include <iostream>
#include <vector>
#include <cstdlib> // For exit()

std::vector<int> incr_list(const std::vector<int>& l) {
    std::vector<int> res(l.size());
    for (size_t i = 0; i < l.size(); ++i) {
        res[i] = l[i] + 1;
    }
    return res;
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

int main() {
    std::vector<int> l, result, expected;
    bool condition;

    // Test case 1
    l = {0};
    expected = {0};
    result = incr_list(l);
    condition = issame(result, expected);
    if (!condition) {
        std::cerr << "Test case 1: assertion failed" << std::endl;
        exit(1);
    }

    // Test case 2
    l = {3, 2, 1};
    expected = {4, 3, 2};
    result = incr_list(l);
    condition = issame(result, expected);
    if (!condition) {
        std::cerr << "Test case 2: assertion failed" << std::endl;
        exit(1);
    }

    // Test case 3
    l = {5, 2, 5, 2, 3, 3, 9, 0, 123};
    expected = {6, 3, 6, 3, 4, 4, 10, 1, 124};
    result = incr_list(l);
    condition = issame(result, expected);
    if (!condition) {
        std::cerr << "Test case 3: assertion failed" << std::endl;
        exit(1);
    }

    std::cout << "All tests passed" << std::endl;
    return 0;
}
```

This C++ code defines the `incr_list` function, which increments each element of the input vector by 1, and the `issame` function, which compares two vectors to check if they are equal. The `main` function contains several test cases to verify the correctness of the `incr_list` function. If any test case fails, it prints an error message and exits with a non-zero status. Otherwise, it prints "All tests passed" indicating success.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `incr_list` function in both languages.

### Fortran Unit Test Code

```fortran
program test_main
    implicit none
    integer, allocatable :: l(:), result(:), expected(:)
    logical :: condition

    ! Test case 1
    allocate(l(0))
    allocate(expected(0))
    result = incr_list(l)
    condition = issame(result, expected)
    if (.not. condition) then
        write(*,*) "Test case 1: assertion failed"
        call exit(1)
    end if

    ! Test case 2
    allocate(l(3))
    l = [3, 2, 1]
    allocate(expected(3))
    expected = [4, 3, 2]
    result = incr_list(l)
    condition = issame(result, expected)
    if (.not. condition) then
        write(*,*) "Test case 2: assertion failed"
        call exit(1)
    end if

    ! Test case 3
    allocate(l(9))
    l = [5, 2, 5, 2, 3, 3, 9, 0, 123]
    allocate(expected(9))
    expected = [6, 3, 6, 3, 4, 4, 10, 1, 124]
    result = incr_list(l)
    condition = issame(result, expected)
    if (.not. condition) then
        write(*,*) "Test case 3: assertion failed"
        call exit(1)
    end if

    write(*,*) "All tests passed"
    call exit(0)
contains

    function incr_list(l) result(res)
        integer, intent(in) :: l(:)
        integer, allocatable :: res(:)
        integer :: i

        allocate(res(size(l)))
        res = l + 1
    end function incr_list

    function issame(a, b) result(is_equal)
        integer, intent(in) :: a(:), b(:)
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

end program test_main
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <cstdlib> // For exit()

std::vector<int> incr_list(const std::vector<int>& l) {
    std::vector<int> res(l.size());
    for (size_t i = 0; i < l.size(); ++i) {
        res[i] = l[i] + 1;
    }
    return res;
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

int main() {
    std::vector<int> l, result, expected;
    bool condition;

    // Test case 1
    l = {0};
    expected = {0};
    result = incr_list(l);
    condition = issame(result, expected);
    if (!condition) {
        std::cerr << "Test case 1: assertion failed" << std::endl;
        exit(1);
    }

    // Test case 2
    l = {3, 2, 1};
    expected = {4, 3, 2};
    result = incr_list(l);
    condition = issame(result, expected);
    if (!condition) {
        std::cerr << "Test case 2: assertion failed" << std::endl;
        exit(1);
    }

    // Test case 3
    l = {5, 2, 5, 2, 3, 3, 9, 0, 123};
    expected = {6, 3, 6, 3, 4, 4, 10, 1, 124};
    result = incr_list(l);
    condition = issame(result, expected);
    if (!condition) {
        std::cerr << "Test case 3: assertion failed" << std::endl;
        exit(1);
    }

    std::cout << "All tests passed" << std::endl;
    return 0;
}
```

These unit test codes are designed to verify the correctness of the `incr_list` function in both Fortran and C++. If any test case fails, the program will print an error message and exit with a non-zero status. If all tests pass, it will print "All tests passed" indicating success.
