Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

int digits(int n) {
    int prod = 1;
    int has = 0;
    std::string s = std::to_string(n); // Convert integer to string

    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] % 2 == 1) {
            has = 1;
            prod *= (s[i] - '0');
        }
    }

    if (has == 0) {
        return 0;
    } else {
        return prod;
    }
}

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    // Assertions
    assert(digits(5) == 5);
    assert(digits(54) == 5);
    assert(digits(120) == 1);
    assert(digits(5014) == 5);
    assert(digits(98765) == 315);
    assert(digits(5576543) == 2625);
    assert(digits(2468) == 0);

    return 0;
}
```

### Explanation:
1. **Function `digits`**:
   - Converts the integer `n` to a string using `std::to_string`.
   - Iterates through each character of the string, multiplies `prod` by the digit if it is odd, and sets `has` to 1 if an odd digit is found.
   - Returns 0 if no odd digits are found, otherwise returns the product of the odd digits.

2. **Function `assert`**:
   - Checks if the condition is false. If so, it prints an error message and exits the program with a non-zero status.

3. **`main` function**:
   - Contains assertions similar to the Fortran version.

This C++ code should behave similarly to the original Fortran code, performing the same calculations and checks.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_main
    implicit none
    integer :: n

    ! Assertions
    call assert(digits(5) == 5)
    call assert(digits(54) == 5)
    call assert(digits(120) == 1)
    call assert(digits(5014) == 5)
    call assert(digits(98765) == 315)
    call assert(digits(5576543) == 2625)
    call assert(digits(2468) == 0)

contains

    integer function digits(n)
        implicit none
        integer, intent(in) :: n
        integer :: i, prod, has
        character(len=20) :: s

        prod = 1
        has = 0
        write(s, '(I0)') n  ! Convert integer to string

        do i = 1, len_trim(s)
            if (mod(iachar(s(i:i)), 2) == 1) then
                has = 1
                prod = prod * (iachar(s(i:i)) - iachar('0'))
            end if
        end do

        if (has == 0) then
            digits = 0
        else
            digits = prod
        end if
    end function digits

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
#include <string>
#include <cstdlib>

int digits(int n) {
    int prod = 1;
    int has = 0;
    std::string s = std::to_string(n); // Convert integer to string

    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] % 2 == 1) {
            has = 1;
            prod *= (s[i] - '0');
        }
    }

    if (has == 0) {
        return 0;
    } else {
        return prod;
    }
}

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    // Assertions
    assert(digits(5) == 5);
    assert(digits(54) == 5);
    assert(digits(120) == 1);
    assert(digits(5014) == 5);
    assert(digits(98765) == 315);
    assert(digits(5576543) == 2625);
    assert(digits(2468) == 0);

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The `test_main` program contains assertions similar to the original Fortran code.
   - The `digits` function and `assert` subroutine are defined as in the original code.

2. **C++ Unit Test Code**:
   - The `main` function contains assertions similar to the translated C++ code.
   - The `digits` function and `assert` function are defined as in the translated code.

These unit test codes will help verify that the translation from Fortran to C++ is correct by checking the output of the `digits` function with various inputs.
