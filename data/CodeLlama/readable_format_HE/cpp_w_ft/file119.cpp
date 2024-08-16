Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the same functionality and test cases as the original Fortran code.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

std::vector<int> even_odd_count(int num) {
    std::string w = std::to_string(std::abs(num));
    int n1 = 0, n2 = 0;

    for (char c : w) {
        if (c % 2 == 1) {
            n1++;
        } else {
            n2++;
        }
    }

    return {n2, n1};
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

int main() {
    std::vector<int> result, expected;

    // Test cases
    result = even_odd_count(7);
    expected = {0, 1};
    assert(issame(result, expected));

    result = even_odd_count(-78);
    expected = {1, 1};
    assert(issame(result, expected));

    result = even_odd_count(3452);
    expected = {2, 2};
    assert(issame(result, expected));

    result = even_odd_count(346211);
    expected = {3, 3};
    assert(issame(result, expected));

    result = even_odd_count(-345821);
    expected = {3, 3};
    assert(issame(result, expected));

    result = even_odd_count(-2);
    expected = {1, 0};
    assert(issame(result, expected));

    result = even_odd_count(-45347);
    expected = {2, 3};
    assert(issame(result, expected));

    result = even_odd_count(0);
    expected = {1, 0};
    assert(issame(result, expected));

    return 0;
}
```

This C++ code includes the `even_odd_count` function, which computes the number of even and odd digits in a given integer, and the `issame` function to compare two vectors. The `assert` function is used to verify that the output matches the expected result. The `main` function contains the test cases that call `even_odd_count` with various inputs and verify the results using `assert`.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `even_odd_count` function in both languages.

### Fortran Unit Test Code

```fortran
program test_even_odd_count
    implicit none
    integer, dimension(2) :: result
    integer, dimension(2) :: expected

    ! Test cases
    result = even_odd_count(7)
    expected = (/0, 1/)
    call assert(issame(result, expected))

    result = even_odd_count(-78)
    expected = (/1, 1/)
    call assert(issame(result, expected))

    result = even_odd_count(3452)
    expected = (/2, 2/)
    call assert(issame(result, expected))

    result = even_odd_count(346211)
    expected = (/3, 3/)
    call assert(issame(result, expected))

    result = even_odd_count(-345821)
    expected = (/3, 3/)
    call assert(issame(result, expected))

    result = even_odd_count(-2)
    expected = (/1, 0/)
    call assert(issame(result, expected))

    result = even_odd_count(-45347)
    expected = (/2, 3/)
    call assert(issame(result, expected))

    result = even_odd_count(0)
    expected = (/1, 0/)
    call assert(issame(result, expected))

contains

    function even_odd_count(num) result(counts)
        integer, intent(in) :: num
        integer, dimension(2) :: counts
        character(len=20) :: w
        integer :: i, n1, n2, len

        ! Convert number to string and get its absolute value
        write(w, '(I0)') abs(num)
        len = len_trim(w)
        n1 = 0
        n2 = 0

        ! Count even and odd digits
        do i = 1, len
            if (mod(ichar(w(i:i)), 2) == 1) then
                n1 = n1 + 1
            else
                n2 = n2 + 1
            end if
        end do

        counts = (/n2, n1/)
    end function even_odd_count

    function issame(a, b) result(same)
        integer, dimension(2), intent(in) :: a, b
        logical :: same
        integer :: i

        same = .true.
        do i = 1, size(a)
            if (a(i) /= b(i)) then
                same = .false.
                exit
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

end program test_even_odd_count
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

std::vector<int> even_odd_count(int num) {
    std::string w = std::to_string(std::abs(num));
    int n1 = 0, n2 = 0;

    for (char c : w) {
        if (c % 2 == 1) {
            n1++;
        } else {
            n2++;
        }
    }

    return {n2, n1};
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

int main() {
    std::vector<int> result, expected;

    // Test cases
    result = even_odd_count(7);
    expected = {0, 1};
    assert(issame(result, expected));

    result = even_odd_count(-78);
    expected = {1, 1};
    assert(issame(result, expected));

    result = even_odd_count(3452);
    expected = {2, 2};
    assert(issame(result, expected));

    result = even_odd_count(346211);
    expected = {3, 3};
    assert(issame(result, expected));

    result = even_odd_count(-345821);
    expected = {3, 3};
    assert(issame(result, expected));

    result = even_odd_count(-2);
    expected = {
