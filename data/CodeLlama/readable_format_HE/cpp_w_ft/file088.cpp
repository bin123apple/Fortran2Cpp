Translating the given Fortran code to C++ involves several steps, including adapting the syntax, converting the functions, and handling array operations. Here's how the Fortran code can be translated to C++:

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> even_odd_palindrome(int n) {
    std::vector<int> result(2, 0);
    int num1 = 0, num2 = 0;
    for (int i = 1; i <= n; ++i) {
        std::string w = std::to_string(i);
        std::string p = w;
        std::reverse(p.begin(), p.end());
        if (w == p) {
            if (i % 2 == 1) {
                num1++;
            } else {
                num2++;
            }
        }
    }
    result[0] = num2;
    result[1] = num1;
    return result;
}

void test_even_odd_palindrome(int n, const std::vector<int>& expected) {
    std::vector<int> result = even_odd_palindrome(n);
    if (result != expected) {
        std::cerr << "Assertion failed for n = " << n << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    test_even_odd_palindrome(123, {8, 13});
    test_even_odd_palindrome(12, {4, 6});
    test_even_odd_palindrome(3, {1, 2});
    test_even_odd_palindrome(63, {6, 8});
    test_even_odd_palindrome(25, {5, 6});
    test_even_odd_palindrome(19, {4, 6});
    test_even_odd_palindrome(9, {4, 5});
    test_even_odd_palindrome(1, {0, 1});

    return 0;
}
```

### Explanation:
1. **Function Conversion**:
   - The `even_odd_palindrome` function is converted to a C++ function that returns a `std::vector<int>`.
   - The `reverse_string` function is not needed in C++ as the `std::reverse` algorithm from the `<algorithm>` header can be used to reverse a string.

2. **Array Handling**:
   - Fortran arrays are converted to `std::vector<int>` in C++ for dynamic sizing and ease of use.

3. **String Handling**:
   - The Fortran `write` statement for converting integers to strings is replaced with `std::to_string` in C++.
   - String reversal is handled using `std::reverse`.

4. **Testing**:
   - The `test_even_odd_palindrome` function is implemented to compare the result of `even_odd_palindrome` with an expected vector.

5. **Main Function**:
   - The main function in C++ calls `test_even_odd_palindrome` with various test cases.

This C++ code should provide equivalent functionality to the original Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_main
    implicit none
    integer, dimension(2) :: result
    integer :: n

    ! Test cases
    call test_even_odd_palindrome(123, [8, 13])
    call test_even_odd_palindrome(12, [4, 6])
    call test_even_odd_palindrome(3, [1, 2])
    call test_even_odd_palindrome(63, [6, 8])
    call test_even_odd_palindrome(25, [5, 6])
    call test_even_odd_palindrome(19, [4, 6])
    call test_even_odd_palindrome(9, [4, 5])
    call test_even_odd_palindrome(1, [0, 1])

contains

    subroutine test_even_odd_palindrome(n, expected)
        integer, intent(in) :: n
        integer, dimension(2), intent(in) :: expected
        integer, dimension(2) :: result

        result = even_odd_palindrome(n)
        if (.not. issame(result, expected)) then
            write(*,*) "Assertion failed for n =", n
            call exit(1)
        end if
    end subroutine test_even_odd_palindrome

    function even_odd_palindrome(n) result(res)
        integer, intent(in) :: n
        integer, dimension(2) :: res
        integer :: i, num1, num2
        character(len=20) :: w, p

        num1 = 0
        num2 = 0
        do i = 1, n
            write(w, '(I0)') i
            p = reverse_string(trim(w))
            if (trim(w) == trim(p)) then
                if (mod(i, 2) == 1) then
                    num1 = num1 + 1
                else
                    num2 = num2 + 1
                end if
            end if
        end do
        res = [num2, num1]
    end function even_odd_palindrome

    function reverse_string(s) result(rev)
        character(len=*), intent(in) :: s
        character(len=len(s)) :: rev
        integer :: i, len_s

        len_s = len_trim(s)
        do i = 1, len_s
            rev(i:i) = s(len_s-i+1:len_s-i+1)
        end do
        rev(len_s+1:) = ' '  ! Pad the rest with spaces
    end function reverse_string

    logical function issame(a, b)
        integer, dimension(2), intent(in) :: a, b
        integer :: i

        issame = .true.
        do i = 1, size(a)
            if (a(i) /= b(i)) then
                issame = .false.
                return
            end if
        end do
    end function issame

end program test_main
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> even_odd_palindrome(int n) {
    std::vector<int> result(2, 0);
    int num1 = 0, num2 = 0;
    for (int i = 1; i <= n; ++i) {
        std::string w = std::to_string(i);
        std::string p = w;
        std::reverse(p.begin(), p.end());
        if (w == p) {
            if (i % 2 == 1) {
                num1++;
            } else {
                num2++;
            }
        }
    }
    result[0] = num2;
    result[1] = num1;
    return result;
}

void test_even_odd_palindrome(int n, const std::vector<int>& expected) {
    std::vector<int> result = even_odd_palindrome(n);
    if (result != expected) {
        std::cerr << "Assertion failed for n = " << n << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    test_even_odd_palindrome(123, {8, 13});
    test_even_odd_palindrome(12, {4, 6});
    test_even_odd_palindrome(3, {1, 2});
    test_even_odd_palindrome(63, {6, 8});
    test_even_odd_palindrome(25, {5, 6});
