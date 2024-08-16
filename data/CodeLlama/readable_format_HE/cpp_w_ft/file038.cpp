Certainly! Below is the equivalent C++ code for the provided Fortran code:

```cpp
#include <iostream>
#include <cstdlib> // For exit()

// Function declaration
int fib4(int n);

int main() {
    // Assertions
    if (fib4(5) != 4) {
        std::cerr << "fib4(5) == 4: assertion failed" << std::endl;
        std::exit(1);
    }

    if (fib4(8) != 28) {
        std::cerr << "fib4(8) == 28: assertion failed" << std::endl;
        std::exit(1);
    }

    if (fib4(10) != 104) {
        std::cerr << "fib4(10) == 104: assertion failed" << std::endl;
        std::exit(1);
    }

    if (fib4(12) != 386) {
        std::cerr << "fib4(12) == 386: assertion failed" << std::endl;
        std::exit(1);
    }

    return 0;
}

// Function definition
int fib4(int n) {
    static int f[100]; // Static array to store the sequence
    if (n < 4) {
        // Initialize the first four elements
        if (n == 0) return 0;
        if (n == 1) return 0;
        if (n == 2) return 2;
        if (n == 3) return 0;
    }

    // Compute the sequence if not already computed
    if (f[n] == 0) {
        f[n] = fib4(n-1) + fib4(n-2) + fib4(n-3) + fib4(n-4);
    }

    return f[n];
}
```

### Explanation:
1. **Function Declaration and Definition**: The `fib4` function is defined similarly to the Fortran version, using a static array to store the computed values.
2. **Main Function**: The main function contains assertions similar to the Fortran code. If any assertion fails, it prints an error message and exits with a non-zero status.
3. **Static Array**: The static array `f` is used to store the computed values of the Fibonacci sequence to avoid recomputing the same values.
4. **Initialization**: The first four elements are initialized directly within the function, similar to the Fortran version.
5. **Recursion**: The function uses recursion to compute the Fibonacci sequence.

This C++ code should behave similarly to the provided Fortran code, ensuring the same correctness and performance.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Tests

To create unit tests for the Fortran code, you can use a simple testing approach by adding test cases directly in the program. Here is an example:

```fortran
program fib4_program
    implicit none

    ! Test cases
    call test_fib4()

contains

    ! Function definition
    integer function fib4(n)
        implicit none
        integer, intent(in) :: n
        integer, dimension(0:99) :: f
        integer :: i

        ! Initialize the first four elements
        f(0) = 0
        f(1) = 0
        f(2) = 2
        f(3) = 0

        ! Compute the sequence
        do i = 4, n
            f(i) = f(i-1) + f(i-2) + f(i-3) + f(i-4)
        end do

        fib4 = f(n)
    end function fib4

    ! Test function
    subroutine test_fib4()
        implicit none
        integer :: i
        integer, parameter :: expected(4) = [4, 28, 104, 386]
        integer, parameter :: n(4) = [5, 8, 10, 12]

        do i = 1, 4
            if (fib4(n(i)) /= expected(i)) then
                write(*,*) "Test failed for fib4(", n(i), "): expected ", expected(i), ", got ", fib4(n(i))
                call exit(1)
            end if
        end do

        write(*,*) "All tests passed."
    end subroutine test_fib4

end program fib4_program
```

### C++ Unit Tests

For the C++ code, you can use a simple testing approach by adding test cases directly in the `main` function. Here is an example:

```cpp
#include <iostream>
#include <cstdlib> // For exit()

// Function declaration
int fib4(int n);

void test_fib4() {
    int expected[4] = {4, 28, 104, 386};
    int n[4] = {5, 8, 10, 12};

    for (int i = 0; i < 4; ++i) {
        if (fib4(n[i]) != expected[i]) {
            std::cerr << "Test failed for fib4(" << n[i] << "): expected " << expected[i] << ", got " << fib4(n[i]) << std::endl;
            std::exit(1);
        }
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    // Assertions (optional, if you want to use the same approach as in the original code)
    // ...

    // Test cases
    test_fib4();

    return 0;
}

// Function definition
int fib4(int n) {
    static int f[100]; // Static array to store the sequence
    if (n < 4) {
        // Initialize the first four elements
        if (n == 0) return 0;
        if (n == 1) return 0;
        if (n == 2) return 2;
        if (n == 3) return 0;
    }

    // Compute the sequence if not already computed
    if (f[n] == 0) {
        f[n] = fib4(n-1) + fib4(n-2) + fib4(n-3) + fib4(n-4);
    }

    return f[n];
}
```

### Explanation:

1. **Fortran Unit Tests**:
   - The `test_fib4` subroutine contains test cases for the `fib4` function.
   - It checks if the output of `fib4` matches the expected values.
   - If any test fails, it prints an error message and exits with a non-zero status.
   - If all tests pass, it prints "All tests passed."

2. **C++ Unit Tests**:
   - The `test_fib4` function contains test cases for the `fib4` function.
   - It checks if the output of `fib4` matches the expected values.
   - If any test fails, it prints an error message and exits with a non-zero status.
   - If all tests pass, it prints "All tests passed."

These unit tests will help verify that the translated C++ code behaves correctly and matches the output of the original Fortran code.
