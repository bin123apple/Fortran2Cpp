Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

std::string circular_shift(int x, int shift) {
    std::string xs = std::to_string(x);
    int len_xs = xs.length();
    if (len_xs < shift) {
        std::string reversed = reverse_string(xs);
        return reversed.substr(0, shift % len_xs) + reversed.substr(0, len_xs - (shift % len_xs));
    } else {
        int actual_shift = shift % len_xs;
        return xs.substr(len_xs - actual_shift, actual_shift) + xs.substr(0, len_xs - actual_shift);
    }
}

std::string reverse_string(const std::string& s) {
    std::string reversed;
    for (int i = s.length() - 1; i >= 0; --i) {
        reversed += s[i];
    }
    return reversed;
}

int main() {
    std::string result;

    result = circular_shift(100, 2);
    if (result != "001") {
        std::cerr << "Assertion failed: circular_shift(100, 2) == '001'" << std::endl;
        std::exit(1);
    }

    result = circular_shift(12, 2);
    if (result != "12") {
        std::cerr << "Assertion failed: circular_shift(12, 2) == '12'" << std::endl;
        std::exit(1);
    }

    result = circular_shift(97, 8);
    if (result != "79") {
        std::cerr << "Assertion failed: circular_shift(97, 8) == '79'" << std::endl;
        std::exit(1);
    }

    result = circular_shift(12, 1);
    if (result != "21") {
        std::cerr << "Assertion failed: circular_shift(12, 1) == '21'" << std::endl;
        std::exit(1);
    }

    result = circular_shift(11, 101);
    if (result != "11") {
        std::cerr << "Assertion failed: circular_shift(11, 101) == '11'" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}
```

### Explanation:
1. **Circular Shift Function:**
   - The `circular_shift` function takes an integer `x` and a shift value `shift`.
   - It converts `x` to a string `xs`.
   - If the length of `xs` is less than `shift`, it reverses the string and returns a substring of the reversed string.
   - Otherwise, it computes the actual shift and returns a substring of `xs`.

2. **Reverse String Function:**
   - The `reverse_string` function takes a string `s` and returns its reversed string.

3. **Main Function:**
   - The `main` function runs several tests to verify the correctness of the `circular_shift` function.
   - If any test fails, it prints an error message and exits with a non-zero status.
   - If all tests pass, it prints "All tests passed."

This C++ code should behave similarly to the provided Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program circular_shift_test
    implicit none
    character(len=100) :: result

    result = circular_shift(100, 2)
    if (trim(result) /= "001") then
        write(*,*) "Assertion failed: circular_shift(100, 2) == '001'"
        call exit(1)
    end if

    result = circular_shift(12, 2)
    if (trim(result) /= "12") then
        write(*,*) "Assertion failed: circular_shift(12, 2) == '12'"
        call exit(1)
    end if

    result = circular_shift(97, 8)
    if (trim(result) /= "79") then
        write(*,*) "Assertion failed: circular_shift(97, 8) == '79'"
        call exit(1)
    end if

    result = circular_shift(12, 1)
    if (trim(result) /= "21") then
        write(*,*) "Assertion failed: circular_shift(12, 1) == '21'"
        call exit(1)
    end if

    result = circular_shift(11, 101)
    if (trim(result) /= "11") then
        write(*,*) "Assertion failed: circular_shift(11, 101) == '11'"
        call exit(1)
    end if

    write(*,*) "All tests passed."

contains

    function circular_shift(x, shift) result(shifted)
        implicit none
        integer, intent(in) :: x, shift
        character(len=100) :: shifted
        character(len=100) :: xs
        integer :: len_xs, actual_shift

        write(xs, '(I0)') x
        len_xs = len(trim(xs))

        if (len_xs < shift) then
            shifted = reverse_string(trim(xs))
        else
            actual_shift = mod(shift, len_xs)
            shifted = trim(xs(len_xs-actual_shift+1:len_xs)) // trim(xs(1:len_xs-actual_shift))
        end if
    end function circular_shift

    function reverse_string(s) result(reversed)
        implicit none
        character(len=*), intent(in) :: s
        character(len=len(s)) :: reversed
        integer :: i, len_s

        len_s = len(trim(s))
        do i = 1, len_s
            reversed(i:i) = s(len_s-i+1:len_s-i+1)
        end do
    end function reverse_string

end program circular_shift_test
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

std::string circular_shift(int x, int shift) {
    std::string xs = std::to_string(x);
    int len_xs = xs.length();
    if (len_xs < shift) {
        std::string reversed = reverse_string(xs);
        return reversed.substr(0, shift % len_xs) + reversed.substr(0, len_xs - (shift % len_xs));
    } else {
        int actual_shift = shift % len_xs;
        return xs.substr(len_xs - actual_shift, actual_shift) + xs.substr(0, len_xs - actual_shift);
    }
}

std::string reverse_string(const std::string& s) {
    std::string reversed;
    for (int i = s.length() - 1; i >= 0; --i) {
        reversed += s[i];
    }
    return reversed;
}

int main() {
    std::string result;

    result = circular_shift(100, 2);
    if (result != "001") {
        std::cerr << "Assertion failed: circular_shift(100, 2) == '001'" << std::endl;
        std::exit(1);
    }

    result = circular_shift(12, 2);
    if (result != "12") {
        std::cerr << "Assertion failed: circular_shift(12, 2) == '12'" << std::endl;
