Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>

int largest_divisor(int n) {
    for (int i = 2; i <= static_cast<int>(std::sqrt(n)); ++i) {
        if (n % i == 0) {
            return n / i;
        }
    }
    return 1;
}

int main() {
    int result;

    // Test cases
    result = largest_divisor(3);
    if (result != 1) {
        std::cerr << "Assertion failed: largest_divisor(3) == 1" << std::endl;
        std::exit(1);
    }

    result = largest_divisor(7);
    if (result != 1) {
        std::cerr << "Assertion failed: largest_divisor(7) == 1" << std::endl;
        std::exit(1);
    }

    result = largest_divisor(10);
    if (result != 5) {
        std::cerr << "Assertion failed: largest_divisor(10) == 5" << std::endl;
        std::exit(1);
    }

    result = largest_divisor(100);
    if (result != 50) {
        std::cerr << "Assertion failed: largest_divisor(100) == 50" << std::endl;
        std::exit(1);
    }

    result = largest_divisor(49);
    if (result != 7) {
        std::cerr << "Assertion failed: largest_divisor(49) == 7" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}
```

This C++ code includes the `largest_divisor` function, which computes the largest divisor of a given integer `n`, and a `main` function that contains several test cases to verify the correctness of the `largest_divisor` function. If any of the test cases fail, the program will print an error message and exit with a status code of 1. Otherwise, it will print "All tests passed."
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `largest_divisor` function in both languages.

### Fortran Unit Test Code

To compile and run the Fortran code, you can use a Fortran compiler like `gfortran`. Here is the unit test code:

```fortran
program test_largest_divisor
  implicit none

  integer :: result

  ! Test cases
  result = largest_divisor(3)
  if (result /= 1) then
    write(*,*) "Test failed: largest_divisor(3) == 1"
    call exit(1)
  end if

  result = largest_divisor(7)
  if (result /= 1) then
    write(*,*) "Test failed: largest_divisor(7) == 1"
    call exit(1)
  end if

  result = largest_divisor(10)
  if (result /= 5) then
    write(*,*) "Test failed: largest_divisor(10) == 5"
    call exit(1)
  end if

  result = largest_divisor(100)
  if (result /= 50) then
    write(*,*) "Test failed: largest_divisor(100) == 50"
    call exit(1)
  end if

  result = largest_divisor(49)
  if (result /= 7) then
    write(*,*) "Test failed: largest_divisor(49) == 7"
    call exit(1)
  end if

  write(*,*) "All tests passed."

contains

  integer function largest_divisor(n)
    implicit none
    integer, intent(in) :: n
    integer :: i

    do i = 2, int(sqrt(real(n)))
      if (mod(n, i) == 0) then
        largest_divisor = n / i
        return
      end if
    end do

    largest_divisor = 1
  end function largest_divisor

end program test_largest_divisor
```

### C++ Unit Test Code

To compile and run the C++ code, you can use a C++ compiler like `g++`. Here is the unit test code:

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>

int largest_divisor(int n) {
    for (int i = 2; i <= static_cast<int>(std::sqrt(n)); ++i) {
        if (n % i == 0) {
            return n / i;
        }
    }
    return 1;
}

int main() {
    int result;

    // Test cases
    result = largest_divisor(3);
    if (result != 1) {
        std::cerr << "Test failed: largest_divisor(3) == 1" << std::endl;
        std::exit(1);
    }

    result = largest_divisor(7);
    if (result != 1) {
        std::cerr << "Test failed: largest_divisor(7) == 1" << std::endl;
        std::exit(1);
    }

    result = largest_divisor(10);
    if (result != 5) {
        std::cerr << "Test failed: largest_divisor(10) == 5" << std::endl;
        std::exit(1);
    }

    result = largest_divisor(100);
    if (result != 50) {
        std::cerr << "Test failed: largest_divisor(100) == 50" << std::endl;
        std::exit(1);
    }

    result = largest_divisor(49);
    if (result != 7) {
        std::cerr << "Test failed: largest_divisor(49) == 7" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran code, use the following commands in your terminal:

```sh
gfortran -o test_largest_divisor test_largest_divisor.f90
./test_largest_divisor
```

#### C++

To compile and run the C++ code, use the following commands in your terminal:

```sh
g++ -o test_largest_divisor test_largest_divisor.cpp
./test_largest_divisor
```

These commands will compile the respective unit test codes and execute them, verifying the correctness of the `largest_divisor` function in both Fortran and C++. If all tests pass, the programs will print "All tests passed."
