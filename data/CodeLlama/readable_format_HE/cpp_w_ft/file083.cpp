Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>

void make_a_pile(int n, std::vector<int>& out) {
    out.resize(n);
    out[0] = n;
    for (int i = 1; i < n; ++i) {
        out[i] = out[i - 1] + 2;
    }
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
    std::vector<int> pile;
    int n;

    make_a_pile(3, pile);
    assert(issame(pile, {3, 5, 7}));

    make_a_pile(4, pile);
    assert(issame(pile, {4, 6, 8, 10}));

    make_a_pile(5, pile);
    assert(issame(pile, {5, 7, 9, 11, 13}));

    make_a_pile(6, pile);
    assert(issame(pile, {6, 8, 10, 12, 14, 16}));

    make_a_pile(8, pile);
    assert(issame(pile, {8, 10, 12, 14, 16, 18, 20, 22}));

    return 0;
}
```

### Explanation:
1. **Functions and Variables**:
   - The `make_a_pile` function creates a pile of numbers based on the input `n`.
   - The `issame` function checks if two vectors are equal.
   - The `assert` function is used to assert the condition.

2. **Main Function**:
   - The `main` function calls `make_a_pile` with different values of `n` and uses `assert` to verify the correctness.

This C++ code should behave similarly to the provided Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_main
    implicit none
    integer, allocatable :: pile(:)
    integer :: n

    ! Test case 1
    call make_a_pile(3, pile)
    call assert(issame(pile, [3, 5, 7]))

    ! Test case 2
    call make_a_pile(4, pile)
    call assert(issame(pile, [4, 6, 8, 10]))

    ! Test case 3
    call make_a_pile(5, pile)
    call assert(issame(pile, [5, 7, 9, 11, 13]))

    ! Test case 4
    call make_a_pile(6, pile)
    call assert(issame(pile, [6, 8, 10, 12, 14, 16]))

    ! Test case 5
    call make_a_pile(8, pile)
    call assert(issame(pile, [8, 10, 12, 14, 16, 18, 20, 22]))

contains

    subroutine make_a_pile(n, out)
        integer, intent(in) :: n
        integer, allocatable, intent(out) :: out(:)
        integer :: i

        allocate(out(n))
        out(1) = n
        do i = 2, n
            out(i) = out(i-1) + 2
        end do
    end subroutine make_a_pile

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
#include <cstdlib>

void make_a_pile(int n, std::vector<int>& out) {
    out.resize(n);
    out[0] = n;
    for (int i = 1; i < n; ++i) {
        out[i] = out[i - 1] + 2;
    }
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
    std::vector<int> pile;
    int n;

    // Test case 1
    make_a_pile(3, pile);
    assert(issame(pile, {3, 5, 7}));

    // Test case 2
    make_a_pile(4, pile);
    assert(issame(pile, {4, 6, 8, 10}));

    // Test case 3
    make_a_pile(5, pile);
    assert(issame(pile, {5, 7, 9, 11, 13}));

    // Test case 4
    make_a_pile(6, pile);
    assert(issame(pile, {6, 8, 10, 12, 14, 16}));

    // Test case 5
    make_a_pile(8, pile);
    assert(issame(pile, {8, 10, 12, 14, 16, 18, 20, 22}));

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The `test_main` program calls the `make_a_pile` subroutine with different values of `n` and checks the output using the `assert` subroutine.
   - The `make_a_pile` subroutine creates a pile of numbers based on the input `n`.
   - The `issame` function checks if two arrays are equal.
   - The `assert` subroutine is used to assert the condition.

2. **C++ Unit Test Code**:
   - The `main` function calls the `make_a_pile` function with different values of `n` and checks the output using the `assert` function.
   - The `make_a_pile` function creates a pile of numbers based on the input `n
