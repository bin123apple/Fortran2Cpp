Certainly! Here's the equivalent C++ code for the provided Fortran program:

```cpp
#include <iostream>
#include <array>
#include <cstdlib>

std::array<int, 2> eat(int number, int need, int remaining) {
    if (need > remaining) {
        return {number + remaining, 0};
    } else {
        return {number + need, remaining - need};
    }
}

bool issame(const std::array<int, 2>& a, const std::array<int, 2>& b) {
    for (int i = 0; i < 2; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::array<int, 2> result;
    std::array<int, 2> expected;

    // Test cases
    result = eat(5, 6, 10);
    expected = {11, 4};
    if (!issame(result, expected)) {
        std::cerr << "Assertion failed: eat(5, 6, 10) == {11, 4}" << std::endl;
        std::exit(1);
    }

    result = eat(4, 8, 9);
    expected = {12, 1};
    if (!issame(result, expected)) {
        std::cerr << "Assertion failed: eat(4, 8, 9) == {12, 1}" << std::endl;
        std::exit(1);
    }

    result = eat(1, 10, 10);
    expected = {11, 0};
    if (!issame(result, expected)) {
        std::cerr << "Assertion failed: eat(1, 10, 10) == {11, 0}" << std::endl;
        std::exit(1);
    }

    result = eat(2, 11, 5);
    expected = {7, 0};
    if (!issame(result, expected)) {
        std::cerr << "Assertion failed: eat(2, 11, 5) == {7, 0}" << std::endl;
        std::exit(1);
    }

    result = eat(4, 5, 7);
    expected = {9, 2};
    if (!issame(result, expected)) {
        std::cerr << "Assertion failed: eat(4, 5, 7) == {9, 2}" << std::endl;
        std::exit(1);
    }

    result = eat(4, 5, 1);
    expected = {5, 0};
    if (!issame(result, expected)) {
        std::cerr << "Assertion failed: eat(4, 5, 1) == {5, 0}" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}
```

This C++ code mirrors the functionality of the original Fortran program, including the `eat` function and the `issame` function to compare the results of the `eat` function with expected values. If any test fails, it prints an error message and exits with a non-zero status. If all tests pass, it prints "All tests passed."
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `eat` function and the `issame` function.

### Fortran Unit Test Code

```fortran
program test_main
  implicit none

  call test_eat()
  call test_issame()

contains

  subroutine test_eat()
    integer, dimension(2) :: result
    integer, dimension(2) :: expected

    ! Test case 1
    result = eat(5, 6, 10)
    expected = (/11, 4/)
    call assert_equal(result, expected, "eat(5, 6, 10)")

    ! Test case 2
    result = eat(4, 8, 9)
    expected = (/12, 1/)
    call assert_equal(result, expected, "eat(4, 8, 9)")

    ! Test case 3
    result = eat(1, 10, 10)
    expected = (/11, 0/)
    call assert_equal(result, expected, "eat(1, 10, 10)")

    ! Test case 4
    result = eat(2, 11, 5)
    expected = (/7, 0/)
    call assert_equal(result, expected, "eat(2, 11, 5)")

    ! Test case 5
    result = eat(4, 5, 7)
    expected = (/9, 2/)
    call assert_equal(result, expected, "eat(4, 5, 7)")

    ! Test case 6
    result = eat(4, 5, 1)
    expected = (/5, 0/)
    call assert_equal(result, expected, "eat(4, 5, 1)")

  end subroutine test_eat

  subroutine test_issame()
    integer, dimension(2) :: a, b
    logical :: result

    ! Test case 1
    a = (/1, 2/)
    b = (/1, 2/)
    result = issame(a, b)
    call assert_true(result, "issame(a, b) with a = (/1, 2/), b = (/1, 2/)")

    ! Test case 2
    a = (/3, 4/)
    b = (/5, 6/)
    result = issame(a, b)
    call assert_false(result, "issame(a, b) with a = (/3, 4/), b = (/5, 6/)")

  end subroutine test_issame

  function eat(number, need, remaining) result(res)
    integer, intent(in) :: number, need, remaining
    integer, dimension(2) :: res

    if (need > remaining) then
      res = (/number + remaining, 0/)
    else
      res = (/number + need, remaining - need/)
    end if
  end function eat

  logical function issame(a, b)
    integer, dimension(2), intent(in) :: a, b
    integer :: i

    issame = .true.
    do i = 1, 2
      if (a(i) /= b(i)) then
        issame = .false.
        return
      end if
    end do
  end function issame

  subroutine assert_equal(result, expected, message)
    integer, dimension(2), intent(in) :: result, expected
    character(len=*), intent(in) :: message

    if (result /= expected) then
      write(*,*) "Assertion failed:", trim(message)
      stop 1
    end if
  end subroutine assert_equal

  subroutine assert_true(condition, message)
    logical, intent(in) :: condition
    character(len=*), intent(in) :: message

    if (.not. condition) then
      write(*,*) "Assertion failed:", trim(message)
      stop 1
    end if
  end subroutine assert_true

  subroutine assert_false(condition, message)
    logical, intent(in) :: condition
    character(len=*), intent(in) :: message

    if (condition) then
      write(*,*) "Assertion failed:", trim(message)
      stop 1
    end if
  end subroutine assert_false

end program test_main
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <array>
#include <cstdlib>

std::array<int, 2> eat(int number, int need, int remaining) {
    if (need > remaining) {
        return {number + remaining, 0};
    } else {
        return {number + need, remaining - need};
