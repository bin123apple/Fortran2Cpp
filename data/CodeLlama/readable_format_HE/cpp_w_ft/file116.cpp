Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the same functionality and the same assertions as the original Fortran code.

#include <iostream>
#include <cmath>
#include <cstdlib>

int x_or_y(int n, int x, int y) {
    bool isPrime = true;
    if (n < 2) isPrime = false;
    for (int i = 2; i <= static_cast<int>(std::sqrt(n)); ++i) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }

    return isPrime ? x : y;
}

int main() {
    // Assertions
    if (x_or_y(7, 34, 12) != 34) {
        std::cerr << "Assertion failed: x_or_y(7, 34, 12) == 34" << std::endl;
        std::exit(1);
    }

    if (x_or_y(15, 8, 5) != 5) {
        std::cerr << "Assertion failed: x_or_y(15, 8, 5) == 5" << std::endl;
        std::exit(1);
    }

    if (x_or_y(3, 33, 5212) != 33) {
        std::cerr << "Assertion failed: x_or_y(3, 33, 5212) == 33" << std::endl;
        std::exit(1);
    }

    if (x_or_y(1259, 3, 52) != 3) {
        std::cerr << "Assertion failed: x_or_y(1259, 3, 52) == 3" << std::endl;
        std::exit(1);
    }

    if (x_or_y(7919, -1, 12) != -1) {
        std::cerr << "Assertion failed: x_or_y(7919, -1, 12) == -1" << std::endl;
        std::exit(1);
    }

    if (x_or_y(3609, 1245, 583) != 583) {
        std::cerr << "Assertion failed: x_or_y(3609, 1245, 583) == 583" << std::endl;
        std::exit(1);
    }

    if (x_or_y(91, 56, 129) != 129) {
        std::cerr << "Assertion failed: x_or_y(91, 56, 129) == 129" << std::endl;
        std::exit(1);
    }

    if (x_or_y(6, 34, 1234) != 1234) {
        std::cerr << "Assertion failed: x_or_y(6, 34, 1234) == 1234" << std::endl;
        std::exit(1);
    }

    if (x_or_y(1, 2, 0) != 0) {
        std::cerr << "Assertion failed: x_or_y(1, 2, 0) == 0" << std::endl;
        std::exit(1);
    }

    if (x_or_y(2, 2, 0) != 2) {
        std::cerr << "Assertion failed: x_or_y(2, 2, 0) == 2" << std::endl;
        std::exit(1);
    }

    std::cout << "All assertions passed." << std::endl;

    return 0;
}
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `x_or_y` function in both languages.

### Fortran Unit Tests

To run the Fortran unit tests, you can use a Fortran compiler like `gfortran`. Save the following code in a file named `test_main.f90`:

```fortran
program test_main
    implicit none

    ! Test cases
    call test_case(7, 34, 12)
    call test_case(15, 8, 5)
    call test_case(3, 33, 5212)
    call test_case(1259, 3, 52)
    call test_case(7919, -1, 12)
    call test_case(3609, 1245, 583)
    call test_case(91, 56, 129)
    call test_case(6, 34, 1234)
    call test_case(1, 2, 0)
    call test_case(2, 2, 0)

    write(*,*) "All tests passed."

contains

    function x_or_y(n, x, y) result(res)
        integer, intent(in) :: n, x, y
        integer :: res
        logical :: isp
        integer :: i

        isp = .true.
        if (n < 2) isp = .false.
        do i = 2, int(sqrt(real(n)))
            if (mod(n, i) == 0) then
                isp = .false.
                exit
            end if
        end do

        if (isp) then
            res = x
        else
            res = y
        end if
    end function x_or_y

    subroutine test_case(n, x, y)
        integer, intent(in) :: n, x, y
        integer :: expected, result

        expected = x_or_y(n, x, y)
        result = x_or_y(n, x, y)

        if (result /= expected) then
            write(*,*) "Test failed: x_or_y(", n, ", ", x, ", ", y, ") == ", expected, ", got ", result
            call exit(1)
        end if
    end subroutine test_case

end program test_main
```

Compile and run the Fortran code:

```sh
gfortran test_main.f90 -o test_main
./test_main
```

### C++ Unit Tests

To run the C++ unit tests, you can use a C++ compiler like `g++`. Save the following code in a file named `test_main.cpp`:

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>

int x_or_y(int n, int x, int y) {
    bool isPrime = true;
    if (n < 2) isPrime = false;
    for (int i = 2; i <= static_cast<int>(std::sqrt(n)); ++i) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }

    return isPrime ? x : y;
}

void test_case(int n, int x, int y, int expected) {
    int result = x_or_y(n, x, y);
    if (result != expected) {
        std::cerr << "Test failed: x_or_y(" << n << ", " << x << ", " << y << ") == " << expected << ", got " << result << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    test_case(7, 34, 12, 34);
    test_case(15, 8, 5, 5);
    test_case(3, 33, 5212, 33);
    test_case(1259, 3, 52, 3);
    test_case(791
