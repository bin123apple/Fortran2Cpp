Translating the given Fortran code to C++ involves several steps, including adapting the array handling, subroutine calls, and loop constructs to their C++ equivalents. Here's how the Fortran code can be translated into C++:

```cpp
#include <iostream>
#include <vector>
#include <cstdlib> // For exit()

void tri(int n, std::vector<int>& out) {
    if (n == 0) {
        out = {1};
        return;
    }

    out.resize(n + 1);
    out[0] = 1;
    out[1] = 3;

    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 0) {
            out[i] = 1 + (i - 1) / 2;
        } else {
            out[i] = out[i - 1] + out[i - 2] + 1 + (i / 2);
        }
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

void test_tri(int n, const std::vector<int>& expected) {
    std::vector<int> result;
    tri(n, result);

    if (!issame(result, expected)) {
        std::cerr << "Assertion failed for n = " << n << std::endl;
        exit(1);
    }
}

int main() {
    test_tri(3, {1, 3, 2, 8});
    test_tri(4, {1, 3, 2, 8, 3});
    test_tri(5, {1, 3, 2, 8, 3, 15});
    test_tri(6, {1, 3, 2, 8, 3, 15, 4});
    test_tri(7, {1, 3, 2, 8, 3, 15, 4, 24});
    test_tri(8, {1, 3, 2, 8, 3, 15, 4, 24, 5});
    test_tri(9, {1, 3, 2, 8, 3, 15, 4, 24, 5, 35});
    test_tri(20, {1, 3, 2, 8, 3, 15, 4, 24, 5, 35, 6, 48, 7, 63, 8, 80, 9, 99, 10, 120, 11});
    test_tri(0, {1});
    test_tri(1, {1, 3});

    return 0;
}
```

### Key Points:

1. **Array Handling**: C++ uses `std::vector<int>` for dynamic arrays, which is more flexible and safer compared to raw arrays.

2. **Subroutine Calls**: Fortran's `call` is replaced by direct function calls in C++.

3. **Loop Constructs**: Fortran's `do` loop is replaced by C++'s `for` loop.

4. **Array Allocation and Initialization**: Fortran's `allocate` and array initialization are replaced by C++'s `std::vector` methods.

5. **Logical Function**: The `issame` function checks if two vectors are equal, which is a common operation in C++.

6. **Error Handling**: Fortran's `write` and `exit` are replaced by C++'s `std::cerr` and `exit(1)`.

This C++ code should provide equivalent functionality to the original Fortran code, ensuring the same logic and output for the given test cases.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `tri` function and the `issame` function.

### Fortran Unit Test Code

```fortran
program test_main
    implicit none
    integer, allocatable :: result(:)
    integer, allocatable :: expected(:)
    integer :: i

    ! Test cases for the tri function
    call test_tri(3, [1, 3, 2, 8])
    call test_tri(4, [1, 3, 2, 8, 3])
    call test_tri(5, [1, 3, 2, 8, 3, 15])
    call test_tri(6, [1, 3, 2, 8, 3, 15, 4])
    call test_tri(7, [1, 3, 2, 8, 3, 15, 4, 24])
    call test_tri(8, [1, 3, 2, 8, 3, 15, 4, 24, 5])
    call test_tri(9, [1, 3, 2, 8, 3, 15, 4, 24, 5, 35])
    call test_tri(20, [1, 3, 2, 8, 3, 15, 4, 24, 5, 35, 6, 48, 7, 63, 8, 80, 9, 99, 10, 120, 11])
    call test_tri(0, [1])
    call test_tri(1, [1, 3])

contains

    subroutine test_tri(n, expected)
        integer, intent(in) :: n
        integer, intent(in) :: expected(:)
        integer, allocatable :: result(:)

        call tri(n, result)
        if (.not. issame(result, expected)) then
            write(*,*) "Assertion failed for n = ", n
            call exit(1)
        end if
    end subroutine test_tri

    subroutine tri(n, out)
        integer, intent(in) :: n
        integer, allocatable, intent(out) :: out(:)
        integer :: i

        if (n == 0) then
            allocate(out(1))
            out = [1]
            return
        end if

        allocate(out(n+1))
        out(1) = 1
        out(2) = 3

        do i = 3, n+1
            if (mod(i-1, 2) == 0) then
                out(i) = 1 + (i-1)/2
            else
                out(i) = out(i-1) + out(i-2) + 1 + (i/2)
            end if
        end do
    end subroutine tri

    logical function issame(a, b)
        integer, intent(in) :: a(:)
        integer, intent(in) :: b(:)
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

end program test_main
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <cstdlib> // For exit()

void tri(int n, std::vector<int>& out) {
    if (n == 0) {
        out = {1};
        return;
    }

    out.resize(n + 1);
    out[0] = 1;
    out[1] = 3;

    for (int i = 2; i <= n; ++i) {
        if (i
