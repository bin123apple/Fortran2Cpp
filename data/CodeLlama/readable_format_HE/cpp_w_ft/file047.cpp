Certainly! Below is the equivalent C++ code for the provided Fortran code:

```cpp
#include <iostream>
#include <cstdlib> // For exit()

int fib(int n) {
    int f[1000];
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= n + 1; ++i) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n+1];
}

int main() {
    int result;

    // Test cases
    result = fib(10);
    if (result != 55) {
        std::cerr << "fib(10) == 55: assertion failed" << std::endl;
        std::exit(1);
    }

    result = fib(1);
    if (result != 1) {
        std::cerr << "fib(1) == 1: assertion failed" << std::endl;
        std::exit(1);
    }

    result = fib(8);
    if (result != 21) {
        std::cerr << "fib(8) == 21: assertion failed" << std::endl;
        std::exit(1);
    }

    result = fib(11);
    if (result != 89) {
        std::cerr << "fib(11) == 89: assertion failed" << std::endl;
        std::exit(1);
    }

    result = fib(12);
    if (result != 144) {
        std::cerr << "fib(12) == 144: assertion failed" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}
```

This C++ code defines a `fib` function to calculate the nth Fibonacci number and includes a main function with test cases to verify the correctness of the `fib` function. The test cases are similar to those in the Fortran code and will exit the program with an error code if any of the assertions fail.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the Fortran and C++ versions of the Fibonacci code. These tests will verify the correctness of the `fib` function for a range of inputs.

### Fortran Unit Tests

To run the Fortran unit tests, you can use a Fortran compiler like `gfortran`. Save the following code in a file named `fibonacci_tests.f90`:

```fortran
program fibonacci_tests
  implicit none
  integer :: result
  integer :: i

  ! Test cases
  do i = 1, 12
     result = fib(i)
     if (result /= expected_fib(i)) then
        write(*,*) "fib(", i, ") == ", expected_fib(i), ": assertion failed"
        call exit(1)
     end if
  end do

  write(*,*) "All tests passed successfully."

contains

  integer function fib(n)
    implicit none
    integer, intent(in) :: n
    integer :: f(1000)
    integer :: i

    f(1) = 0
    f(2) = 1
    do i = 3, n + 1
      f(i) = f(i-1) + f(i-2)
    end do
    fib = f(n+1)
  end function fib

  integer function expected_fib(n)
    implicit none
    integer, intent(in) :: n
    select case(n)
    case(1)
      expected_fib = 1
    case(2)
      expected_fib = 1
    case(3)
      expected_fib = 2
    case(4)
      expected_fib = 3
    case(5)
      expected_fib = 5
    case(6)
      expected_fib = 8
    case(7)
      expected_fib = 13
    case(8)
      expected_fib = 21
    case(9)
      expected_fib = 34
    case(10)
      expected_fib = 55
    case(11)
      expected_fib = 89
    case(12)
      expected_fib = 144
    case default
      expected_fib = -1
    end select
  end function expected_fib

end program fibonacci_tests
```

### C++ Unit Tests

To run the C++ unit tests, you can use a C++ compiler like `g++`. Save the following code in a file named `fibonacci_tests.cpp`:

```cpp
#include <iostream>
#include <cstdlib> // For exit()

int fib(int n) {
    int f[1000];
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= n + 1; ++i) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n+1];
}

int expected_fib(int n) {
    switch (n) {
        case 1: return 1;
        case 2: return 1;
        case 3: return 2;
        case 4: return 3;
        case 5: return 5;
        case 6: return 8;
        case 7: return 13;
        case 8: return 21;
        case 9: return 34;
        case 10: return 55;
        case 11: return 89;
        case 12: return 144;
        default: return -1;
    }
}

int main() {
    int result;

    // Test cases
    for (int i = 1; i <= 12; ++i) {
        result = fib(i);
        if (result != expected_fib(i)) {
            std::cerr << "fib(" << i << ") == " << expected_fib(i) << ": assertion failed" << std::endl;
            std::exit(1);
        }
    }

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}
```

### Running the Tests

#### Fortran

To compile and run the Fortran tests, use the following commands:

```sh
gfortran -o fibonacci_tests fibonacci_tests.f90
./fibonacci_tests
```

#### C++

To compile and run the C++ tests, use the following commands:

```sh
g++ -o fibonacci_tests fibonacci_tests.cpp
./fibonacci_tests
```

These tests will verify the correctness of the `fib` function for inputs from 1 to 12 and will exit the program with an error code if any of the assertions fail. If all tests pass, it will print "All tests passed successfully."
