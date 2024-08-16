Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the same functionality and assertions as the original Fortran code.

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>

int largest_prime_factor(int n) {
    int num = n;
    for (int i = 2; i <= static_cast<int>(std::sqrt(static_cast<double>(n))); ++i) {
        while (num % i == 0 && num > i) {
            num /= i;
        }
    }
    return num;
}

int main() {
    // Assertions
    if (largest_prime_factor(15) != 5) {
        std::cerr << "Assertion failed: largest_prime_factor(15) == 5" << std::endl;
        std::exit(1);
    }

    if (largest_prime_factor(27) != 3) {
        std::cerr << "Assertion failed: largest_prime_factor(27) == 3" << std::endl;
        std::exit(1);
    }

    if (largest_prime_factor(63) != 7) {
        std::cerr << "Assertion failed: largest_prime_factor(63) == 7" << std::endl;
        std::exit(1);
    }

    if (largest_prime_factor(330) != 11) {
        std::cerr << "Assertion failed: largest_prime_factor(330) == 11" << std::endl;
        std::exit(1);
    }

    if (largest_prime_factor(13195) != 29) {
        std::cerr << "Assertion failed: largest_prime_factor(13195) == 29" << std::endl;
        std::exit(1);
    }

    return 0;
}
```

This C++ code defines a function `largest_prime_factor` which computes the largest prime factor of a given number, similar to the Fortran version. The `main` function contains assertions to verify the correctness of the `largest_prime_factor` function with specific test cases. If any assertion fails, it prints an error message and exits with a status code of 1, similar to the Fortran version.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `largest_prime_factor` function with a set of predefined test cases.

### Fortran Unit Test Code

To compile and run this Fortran code, you might need a Fortran compiler like `gfortran`. Save the code in a file named `test_main.f90` and compile it using a command like `gfortran -o test_main test_main.f90`.

```fortran
program test_main
  implicit none

  ! Test cases
  call test_case(15, 5)
  call test_case(27, 3)
  call test_case(63, 7)
  call test_case(330, 11)
  call test_case(13195, 29)

contains

  subroutine test_case(n, expected)
    implicit none
    integer, intent(in) :: n, expected
    integer :: result

    result = largest_prime_factor(n)
    if (result /= expected) then
      write(*,*) "Test failed: largest_prime_factor(", n, ") == ", expected, ", got ", result
      call exit(1)
    else
      write(*,*) "Test passed: largest_prime_factor(", n, ") == ", expected
    end if
  end subroutine test_case

  integer function largest_prime_factor(n)
    implicit none
    integer, intent(in) :: n
    integer :: i, num

    num = n
    do i = 2, int(sqrt(real(n)))
      do while (mod(num, i) == 0 .and. num > i)
        num = num / i
      end do
    end do
    largest_prime_factor = num
  end function largest_prime_factor

end program test_main
```

### C++ Unit Test Code

To compile and run this C++ code, you might need a C++ compiler like `g++`. Save the code in a file named `test_main.cpp` and compile it using a command like `g++ -o test_main test_main.cpp`.

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>

int largest_prime_factor(int n) {
    int num = n;
    for (int i = 2; i <= static_cast<int>(std::sqrt(static_cast<double>(n))); ++i) {
        while (num % i == 0 && num > i) {
            num /= i;
        }
    }
    return num;
}

void test_case(int n, int expected) {
    int result = largest_prime_factor(n);
    if (result != expected) {
        std::cerr << "Test failed: largest_prime_factor(" << n << ") == " << expected << ", got " << result << std::endl;
        std::exit(1);
    } else {
        std::cout << "Test passed: largest_prime_factor(" << n << ") == " << expected << std::endl;
    }
}

int main() {
    // Test cases
    test_case(15, 5);
    test_case(27, 3);
    test_case(63, 7);
    test_case(330, 11);
    test_case(13195, 29);

    return 0;
}
```

These unit test codes for both Fortran and C++ will verify the correctness of the `largest_prime_factor` function with predefined test cases. If any test fails, it will print an error message and exit with a status code of 1. If all tests pass, it will print a success message for each test case.
