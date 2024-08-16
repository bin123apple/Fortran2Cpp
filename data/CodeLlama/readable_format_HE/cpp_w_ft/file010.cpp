Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the `greatest_common_divisor` function and the `assert` function to verify the correctness of the GCD calculation.

```cpp
#include <iostream>
#include <cstdlib>

// Function to calculate the greatest common divisor
int greatest_common_divisor(int a, int b) {
    int temp_a = a, temp_b = b;

    while (true) {
        if (temp_a < temp_b) {
            std::swap(temp_a, temp_b);
        }
        temp_a = temp_a % temp_b;
        if (temp_a == 0) {
            return temp_b;
        }
    }
}

// Assert function to verify the correctness
void assert(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << message << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    assert(greatest_common_divisor(3, 7) == 1, "Assertion failed: gcd(3, 7) == 1");
    assert(greatest_common_divisor(10, 15) == 5, "Assertion failed: gcd(10, 15) == 5");
    assert(greatest_common_divisor(49, 14) == 7, "Assertion failed: gcd(49, 14) == 7");
    assert(greatest_common_divisor(144, 60) == 12, "Assertion failed: gcd(144, 60) == 12");

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}
```

This C++ code defines the `greatest_common_divisor` function, which computes the greatest common divisor of two integers using the Euclidean algorithm. The `assert` function is used to verify the correctness of the `greatest_common_divisor` function with various test cases. If any test case fails, the program will print the corresponding message and exit with a non-zero status. If all tests pass, it will print a success message.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `greatest_common_divisor` function with various inputs.

### Fortran Unit Tests

To compile and run the Fortran code, you can use a Fortran compiler like `gfortran`. Here is the complete Fortran code with the unit tests:

```fortran
module gcd_module
  implicit none

contains

  integer function greatest_common_divisor(a, b)
    implicit none
    integer, intent(in) :: a, b
    integer :: m, temp_a, temp_b

    temp_a = a
    temp_b = b

    do
      if (temp_a < temp_b) then
        m = temp_a
        temp_a = temp_b
        temp_b = m
      end if
      temp_a = mod(temp_a, temp_b)
      if (temp_a == 0) then
        greatest_common_divisor = temp_b
        return
      end if
    end do
  end function greatest_common_divisor

  subroutine assert(condition, message)
    implicit none
    logical, intent(in) :: condition
    character(len=*), intent(in) :: message

    if (.not. condition) then
      write(*,*) message
      call exit(1)
    end if
  end subroutine assert

end module gcd_module

program main
  use gcd_module
  implicit none

  call assert(greatest_common_divisor(3, 7) == 1, "Assertion failed: gcd(3, 7) == 1")
  call assert(greatest_common_divisor(10, 15) == 5, "Assertion failed: gcd(10, 15) == 5")
  call assert(greatest_common_divisor(49, 14) == 7, "Assertion failed: gcd(49, 14) == 7")
  call assert(greatest_common_divisor(144, 60) == 12, "Assertion failed: gcd(144, 60) == 12")

  print *, "All tests passed successfully."
end program main
```

### C++ Unit Tests

To compile and run the C++ code, you can use a C++ compiler like `g++`. Here is the complete C++ code with the unit tests:

```cpp
#include <iostream>
#include <cstdlib>
#include <string>

// Function to calculate the greatest common divisor
int greatest_common_divisor(int a, int b) {
    int temp_a = a, temp_b = b;

    while (true) {
        if (temp_a < temp_b) {
            std::swap(temp_a, temp_b);
        }
        temp_a = temp_a % temp_b;
        if (temp_a == 0) {
            return temp_b;
        }
    }
}

// Assert function to verify the correctness
void assert(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << message << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    assert(greatest_common_divisor(3, 7) == 1, "Assertion failed: gcd(3, 7) == 1");
    assert(greatest_common_divisor(10, 15) == 5, "Assertion failed: gcd(10, 15) == 5");
    assert(greatest_common_divisor(49, 14) == 7, "Assertion failed: gcd(49, 14) == 7");
    assert(greatest_common_divisor(144, 60) == 12, "Assertion failed: gcd(144, 60) == 12");

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}
```

### Compilation and Execution

- **For Fortran:**
  ```sh
  gfortran -o gcd_test your_fortran_file.f90
  ./gcd_test
  ```

- **For C++:**
  ```sh
  g++ -o gcd_test your_cpp_file.cpp
  ./gcd_test
  ```

These commands will compile and run the respective programs, executing the unit tests and verifying the correctness of the `greatest_common_divisor` function.
