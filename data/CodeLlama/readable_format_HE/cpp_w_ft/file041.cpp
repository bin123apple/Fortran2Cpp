Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <cstdlib> // For exit()

// Function declaration
int modp(int n, int p);

int main() {
    // Variable declaration
    int result;

    // Assertions
    result = modp(3, 5);
    if (result != 3) {
        std::cerr << "modp(3, 5) == 3: assertion failed" << std::endl;
        std::exit(1);
    }

    result = modp(1101, 101);
    if (result != 2) {
        std::cerr << "modp(1101, 101) == 2: assertion failed" << std::endl;
        std::exit(1);
    }

    result = modp(0, 101);
    if (result != 1) {
        std::cerr << "modp(0, 101) == 1: assertion failed" << std::endl;
        std::exit(1);
    }

    result = modp(3, 11);
    if (result != 8) {
        std::cerr << "modp(3, 11) == 8: assertion failed" << std::endl;
        std::exit(1);
    }

    result = modp(100, 101);
    if (result != 1) {
        std::cerr << "modp(100, 101) == 1: assertion failed" << std::endl;
        std::exit(1);
    }

    result = modp(30, 5);
    if (result != 4) {
        std::cerr << "modp(30, 5) == 4: assertion failed" << std::endl;
        std::exit(1);
    }

    result = modp(31, 5);
    if (result != 3) {
        std::cerr << "modp(31, 5) == 3: assertion failed" << std::endl;
        std::exit(1);
    }

    std::cout << "All assertions passed." << std::endl;

    return 0;
}

// Function definition
int modp(int n, int p) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * 2) % p;
    }
    return result;
}
```

This C++ code includes the necessary headers and uses the `std::cerr` for error output and `std::exit(1)` for exiting the program with an error code if any of the assertions fail. The `modp` function is defined similarly to the Fortran version, using a for-loop to iterate through the bits of `n` and multiplying the result by 2, modulo `p`, for each bit.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `modp` function in both languages.

### Fortran Unit Test Code

```fortran
program test_modp
    implicit none

    ! Test cases
    call test_case(3, 5, 3)
    call test_case(1101, 101, 2)
    call test_case(0, 101, 1)
    call test_case(3, 11, 8)
    call test_case(100, 101, 1)
    call test_case(30, 5, 4)
    call test_case(31, 5, 3)

contains

    ! Function definition
    integer function modp(n, p)
        integer, intent(in) :: n, p
        integer :: i
        modp = 1
        do i = 1, n
            modp = mod(modp * 2, p)
        end do
    end function modp

    ! Test case subroutine
    subroutine test_case(n, p, expected)
        integer, intent(in) :: n, p, expected
        integer :: result
        result = modp(n, p)
        if (result /= expected) then
            write(*,*) "Test failed: modp(", n, ",", p, ") == ", expected, ", got ", result
            call exit(1)
        else
            write(*,*) "Test passed: modp(", n, ",", p, ") == ", expected
        end if
    end subroutine test_case

end program test_modp
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <cstdlib> // For exit()

// Function declaration
int modp(int n, int p);

// Test case function
void test_case(int n, int p, int expected) {
    int result = modp(n, p);
    if (result != expected) {
        std::cerr << "Test failed: modp(" << n << ", " << p << ") == " << expected << ", got " << result << std::endl;
        std::exit(1);
    } else {
        std::cout << "Test passed: modp(" << n << ", " << p << ") == " << expected << std::endl;
    }
}

int main() {
    // Test cases
    test_case(3, 5, 3);
    test_case(1101, 101, 2);
    test_case(0, 101, 1);
    test_case(3, 11, 8);
    test_case(100, 101, 1);
    test_case(30, 5, 4);
    test_case(31, 5, 3);

    return 0;
}

// Function definition
int modp(int n, int p) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * 2) % p;
    }
    return result;
}
```

### Explanation

- **Fortran Unit Test Code**:
  - The `modp` function is defined as before.
  - The `test_case` subroutine is used to test the `modp` function with different inputs and expected outputs.
  - If the result does not match the expected output, it prints an error message and exits with a non-zero status.
  - If the test passes, it prints a success message.

- **C++ Unit Test Code**:
  - The `modp` function is defined as before.
  - The `test_case` function is used to test the `modp` function with different inputs and expected outputs.
  - If the result does not match the expected output, it prints an error message and exits with a non-zero status.
  - If the test passes, it prints a success message.

These unit tests will help ensure that the `modp` function behaves correctly in both Fortran and C++.
