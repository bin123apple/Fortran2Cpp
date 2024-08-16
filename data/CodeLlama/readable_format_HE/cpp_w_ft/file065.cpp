Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <cmath>

bool is_simple_power(int x, int n) {
    int p = 1;
    int count = 0;
    while (p <= x && count < 100) {
        if (p == x) {
            return true;
        }
        p *= n;
        ++count;
    }
    return false;
}

int main() {
    // Test cases
    if (!is_simple_power(1, 4)) {
        std::cerr << "Assertion failed: is_simple_power(1, 4) == true" << std::endl;
        return 1;
    }
    if (!is_simple_power(2, 2)) {
        std::cerr << "Assertion failed: is_simple_power(2, 2) == true" << std::endl;
        return 1;
    }
    if (!is_simple_power(8, 2)) {
        std::cerr << "Assertion failed: is_simple_power(8, 2) == true" << std::endl;
        return 1;
    }
    if (is_simple_power(3, 2)) {
        std::cerr << "Assertion failed: is_simple_power(3, 2) == false" << std::endl;
        return 1;
    }
    if (is_simple_power(3, 1)) {
        std::cerr << "Assertion failed: is_simple_power(3, 1) == false" << std::endl;
        return 1;
    }
    if (is_simple_power(5, 3)) {
        std::cerr << "Assertion failed: is_simple_power(5, 3) == false" << std::endl;
        return 1;
    }
    if (!is_simple_power(16, 2)) {
        std::cerr << "Assertion failed: is_simple_power(16, 2) == true" << std::endl;
        return 1;
    }
    if (is_simple_power(143214, 16)) {
        std::cerr << "Assertion failed: is_simple_power(143214, 16) == false" << std::endl;
        return 1;
    }
    if (!is_simple_power(4, 2)) {
        std::cerr << "Assertion failed: is_simple_power(4, 2) == true" << std::endl;
        return 1;
    }
    if (!is_simple_power(9, 3)) {
        std::cerr << "Assertion failed: is_simple_power(9, 3) == true" << std::endl;
        return 1;
    }
    if (!is_simple_power(16, 4)) {
        std::cerr << "Assertion failed: is_simple_power(16, 4) == true" << std::endl;
        return 1;
    }
    if (is_simple_power(24, 2)) {
        std::cerr << "Assertion failed: is_simple_power(24, 2) == false" << std::endl;
        return 1;
    }
    if (is_simple_power(128, 4)) {
        std::cerr << "Assertion failed: is_simple_power(128, 4) == false" << std::endl;
        return 1;
    }
    if (is_simple_power(12, 6)) {
        std::cerr << "Assertion failed: is_simple_power(12, 6) == false" << std::endl;
        return 1;
    }
    if (!is_simple_power(1, 1)) {
        std::cerr << "Assertion failed: is_simple_power(1, 1) == true" << std::endl;
        return 1;
    }
    if (!is_simple_power(1, 12)) {
        std::cerr << "Assertion failed: is_simple_power(1, 12) == true" << std::endl;
        return 1;
    }

    return 0;
}
```

This C++ code includes the `is_simple_power` function, which checks if a number `x` is a simple power of another number `n`. The `main` function contains a series of assertions to verify the correctness of the `is_simple_power` function. If any assertion fails, it prints an error message and returns 1, indicating a failure. Otherwise, it returns 0, indicating success.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the Fortran and C++ versions of the `is_simple_power` function. These tests will help verify the correctness of the translation.

### Fortran Unit Test Code

```fortran
program test_simple_power
  implicit none

  ! Test cases
  call assert_true(is_simple_power(1, 4))
  call assert_true(is_simple_power(2, 2))
  call assert_true(is_simple_power(8, 2))
  call assert_false(is_simple_power(3, 2))
  call assert_false(is_simple_power(3, 1))
  call assert_false(is_simple_power(5, 3))
  call assert_true(is_simple_power(16, 2))
  call assert_false(is_simple_power(143214, 16))
  call assert_true(is_simple_power(4, 2))
  call assert_true(is_simple_power(9, 3))
  call assert_true(is_simple_power(16, 4))
  call assert_false(is_simple_power(24, 2))
  call assert_false(is_simple_power(128, 4))
  call assert_false(is_simple_power(12, 6))
  call assert_true(is_simple_power(1, 1))
  call assert_true(is_simple_power(1, 12))

contains

  logical function is_simple_power(x, n)
    implicit none
    integer, intent(in) :: x, n
    integer :: p, count

    p = 1
    count = 0
    do while (p <= x .and. count < 100)
      if (p == x) then
        is_simple_power = .true.
        return
      end if
      p = p * n
      count = count + 1
    end do
    is_simple_power = .false.
  end function is_simple_power

  subroutine assert_true(condition)
    logical, intent(in) :: condition
    if (.not. condition) then
      write(*,*) "Assertion failed: expected true"
      call exit(1)
    end if
  end subroutine assert_true

  subroutine assert_false(condition)
    logical, intent(in) :: condition
    if (condition) then
      write(*,*) "Assertion failed: expected false"
      call exit(1)
    end if
  end subroutine assert_false

end program test_simple_power
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <cassert>

bool is_simple_power(int x, int n) {
    int p = 1;
    int count = 0;
    while (p <= x && count < 100) {
        if (p == x) {
            return true;
        }
        p *= n;
        ++count;
    }
    return false;
}

void assert_true(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed: expected true" << std::endl;
        std::exit(1);
    }
}

void assert_false(bool condition) {
    if (condition) {
        std::cerr << "Assertion failed: expected false" << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
