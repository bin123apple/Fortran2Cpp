Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <cstdlib> // For exit()

// Function declaration
int sum_to_n(int n);

int main() {
    // Assertions
    if (sum_to_n(1) != 1) {
        std::cerr << "sum_to_n(1) == 1: assertion failed" << std::endl;
        std::exit(1);
    }

    if (sum_to_n(6) != 21) {
        std::cerr << "sum_to_n(6) == 21: assertion failed" << std::endl;
        std::exit(1);
    }

    if (sum_to_n(11) != 66) {
        std::cerr << "sum_to_n(11) == 66: assertion failed" << std::endl;
        std::exit(1);
    }

    if (sum_to_n(30) != 465) {
        std::cerr << "sum_to_n(30) == 465: assertion failed" << std::endl;
        std::exit(1);
    }

    if (sum_to_n(100) != 5050) {
        std::cerr << "sum_to_n(100) == 5050: assertion failed" << std::endl;
        std::exit(1);
    }

    return 0;
}

// Function definition
int sum_to_n(int n) {
    return n * (n + 1) / 2;
}
```

This C++ code includes the necessary headers and uses `std::cerr` for error output and `std::exit(1)` to exit the program with an error code if any of the assertions fail, similar to the Fortran code. The `sum_to_n` function is defined with the same logic as in the Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `sum_to_n` function.

### Fortran Unit Tests

To add unit tests directly in the Fortran program, you can modify the program to include test cases directly. Here's how you can do it:

```fortran
program main
  implicit none

  ! Test cases
  call test_sum_to_n()

contains

  ! Function definition
  integer function sum_to_n(n)
    integer, intent(in) :: n
    sum_to_n = n * (n + 1) / 2
  end function sum_to_n

  ! Test function
  subroutine test_sum_to_n()
    implicit none
    integer :: result

    ! Test case 1
    result = sum_to_n(1)
    if (result /= 1) then
      write(*,*) "Test case 1 failed: sum_to_n(1) should be 1"
      stop 1
    end if

    ! Test case 2
    result = sum_to_n(6)
    if (result /= 21) then
      write(*,*) "Test case 2 failed: sum_to_n(6) should be 21"
      stop 1
    end if

    ! Test case 3
    result = sum_to_n(11)
    if (result /= 66) then
      write(*,*) "Test case 3 failed: sum_to_n(11) should be 66"
      stop 1
    end if

    ! Test case 4
    result = sum_to_n(30)
    if (result /= 465) then
      write(*,*) "Test case 4 failed: sum_to_n(30) should be 465"
      stop 1
    end if

    ! Test case 5
    result = sum_to_n(100)
    if (result /= 5050) then
      write(*,*) "Test case 5 failed: sum_to_n(100) should be 5050"
      stop 1
    end if

    write(*,*) "All tests passed successfully."
  end subroutine test_sum_to_n

end program main
```

### C++ Unit Tests

For C++, you can use a simple testing approach similar to the Fortran example above. However, for more comprehensive testing, you might consider using a testing framework like Google Test. Here's a basic example without a framework:

```cpp
#include <iostream>
#include <cstdlib> // For exit()

// Function declaration
int sum_to_n(int n);

// Test function declaration
void test_sum_to_n();

int main() {
    // Run tests
    test_sum_to_n();

    return 0;
}

// Function definition
int sum_to_n(int n) {
    return n * (n + 1) / 2;
}

// Test function definition
void test_sum_to_n() {
    if (sum_to_n(1) != 1) {
        std::cerr << "Test case 1 failed: sum_to_n(1) should be 1" << std::endl;
        std::exit(1);
    }

    if (sum_to_n(6) != 21) {
        std::cerr << "Test case 2 failed: sum_to_n(6) should be 21" << std::endl;
        std::exit(1);
    }

    if (sum_to_n(11) != 66) {
        std::cerr << "Test case 3 failed: sum_to_n(11) should be 66" << std::endl;
        std::exit(1);
    }

    if (sum_to_n(30) != 465) {
        std::cerr << "Test case 4 failed: sum_to_n(30) should be 465" << std::endl;
        std::exit(1);
    }

    if (sum_to_n(100) != 5050) {
        std::cerr << "Test case 5 failed: sum_to_n(100) should be 5050" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed successfully." << std::endl;
}
```

These unit tests will verify the correctness of the `sum_to_n` function in both the Fortran and C++ implementations.
