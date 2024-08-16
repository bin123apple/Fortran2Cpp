Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <cstdlib> // For exit()

// Function prototype
int choose_num(int x, int y);

int main() {
    int result;

    result = choose_num(12, 15);
    if (result != 14) {
        std::cerr << "Assertion failed: choose_num(12, 15) == 14" << std::endl;
        std::exit(1);
    }

    result = choose_num(13, 12);
    if (result != -1) {
        std::cerr << "Assertion failed: choose_num(13, 12) == -1" << std::endl;
        std::exit(1);
    }

    result = choose_num(33, 12354);
    if (result != 12354) {
        std::cerr << "Assertion failed: choose_num(33, 12354) == 12354" << std::endl;
        std::exit(1);
    }

    result = choose_num(5234, 5233);
    if (result != -1) {
        std::cerr << "Assertion failed: choose_num(5234, 5233) == -1" << std::endl;
        std::exit(1);
    }

    result = choose_num(6, 29);
    if (result != 28) {
        std::cerr << "Assertion failed: choose_num(6, 29) == 28" << std::endl;
        std::exit(1);
    }

    result = choose_num(27, 10);
    if (result != -1) {
        std::cerr << "Assertion failed: choose_num(27, 10) == -1" << std::endl;
        std::exit(1);
    }

    result = choose_num(7, 7);
    if (result != -1) {
        std::cerr << "Assertion failed: choose_num(7, 7) == -1" << std::endl;
        std::exit(1);
    }

    result = choose_num(546, 546);
    if (result != 546) {
        std::cerr << "Assertion failed: choose_num(546, 546) == 546" << std::endl;
        std::exit(1);
    }

    return 0;
}

int choose_num(int x, int y) {
    if (y < x) {
        return -1;
    } else if (y == x && x % 2 == 1) {
        return -1;
    } else if (x % 2 == 1) {
        return y - 1;
    } else {
        return y;
    }
}
```

This C++ code includes the main function and the `choose_num` function, which mimics the functionality of the Fortran code. The `main` function contains assertions to verify the correctness of the `choose_num` function with various inputs. If any assertion fails, it prints an error message and exits with a status code of 1.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `choose_num` function with various inputs.

### Fortran Unit Test Code

```fortran
program test_choose_num
    implicit none

    integer :: result

    ! Test 1
    result = choose_num(12, 15)
    if (result /= 14) then
        write(*,*) "Test 1 failed: choose_num(12, 15) == 14"
    else
        write(*,*) "Test 1 passed"
    end if

    ! Test 2
    result = choose_num(13, 12)
    if (result /= -1) then
        write(*,*) "Test 2 failed: choose_num(13, 12) == -1"
    else
        write(*,*) "Test 2 passed"
    end if

    ! Test 3
    result = choose_num(33, 12354)
    if (result /= 12354) then
        write(*,*) "Test 3 failed: choose_num(33, 12354) == 12354"
    else
        write(*,*) "Test 3 passed"
    end if

    ! Test 4
    result = choose_num(5234, 5233)
    if (result /= -1) then
        write(*,*) "Test 4 failed: choose_num(5234, 5233) == -1"
    else
        write(*,*) "Test 4 passed"
    end if

    ! Test 5
    result = choose_num(6, 29)
    if (result /= 28) then
        write(*,*) "Test 5 failed: choose_num(6, 29) == 28"
    else
        write(*,*) "Test 5 passed"
    end if

    ! Test 6
    result = choose_num(27, 10)
    if (result /= -1) then
        write(*,*) "Test 6 failed: choose_num(27, 10) == -1"
    else
        write(*,*) "Test 6 passed"
    end if

    ! Test 7
    result = choose_num(7, 7)
    if (result /= -1) then
        write(*,*) "Test 7 failed: choose_num(7, 7) == -1"
    else
        write(*,*) "Test 7 passed"
    end if

    ! Test 8
    result = choose_num(546, 546)
    if (result /= 546) then
        write(*,*) "Test 8 failed: choose_num(546, 546) == 546"
    else
        write(*,*) "Test 8 passed"
    end if

contains

    integer function choose_num(x, y)
        implicit none
        integer, intent(in) :: x, y

        if (y < x) then
            choose_num = -1
        else if (y == x .and. mod(y, 2) == 1) then
            choose_num = -1
        else if (mod(y, 2) == 1) then
            choose_num = y - 1
        else
            choose_num = y
        end if
    end function choose_num

end program test_choose_num
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <cstdlib> // For exit()

// Function prototype
int choose_num(int x, int y);

int main() {
    int result;

    // Test 1
    result = choose_num(12, 15);
    if (result != 14) {
        std::cerr << "Test 1 failed: choose_num(12, 15) == 14" << std::endl;
    } else {
        std::cout << "Test 1 passed" << std::endl;
    }

    // Test 2
    result = choose_num(13, 12);
    if (result != -1) {
        std::cerr << "Test 2 failed: choose_num(13, 12) == -1" << std::endl;
    } else {
        std::cout << "Test 2 passed" << std::endl;
    }

    // Test 3
    result = choose_num(33, 12354);
    if (result != 12354) {
        std::cerr << "Test 3 failed: choose_num(33, 12354) == 12354" << std::endl;
    } else {
        std::cout << "
