Certainly! Here's the equivalent C++ code for the provided Fortran program:

```cpp
#include <iostream>
#include <string>

std::string decimal_to_binary(int decimal) {
    std::string out;
    if (decimal == 0) {
        return "db0db";
    }

    int temp = decimal;
    while (temp > 0) {
        out += (temp % 2 == 0) ? '0' : '1';
        temp /= 2;
    }

    return "db" + out + "db";
}

void test_decimal_to_binary() {
    std::string result;

    result = decimal_to_binary(0);
    if (result != "db0db") {
        std::cerr << "Assertion failed: decimal_to_binary(0) == 'db0db'" << std::endl;
        std::exit(1);
    }

    result = decimal_to_binary(32);
    if (result != "db100000db") {
        std::cerr << "Assertion failed: decimal_to_binary(32) == 'db100000db'" << std::endl;
        std::exit(1);
    }

    result = decimal_to_binary(103);
    if (result != "db1100111db") {
        std::cerr << "Assertion failed: decimal_to_binary(103) == 'db1100111db'" << std::endl;
        std::exit(1);
    }

    result = decimal_to_binary(15);
    if (result != "db1111db") {
        std::cerr << "Assertion failed: decimal_to_binary(15) == 'db1111db'" << std::endl;
        std::exit(1);
    }
}

int main() {
    test_decimal_to_binary();
    std::cout << "All assertions passed." << std::endl;
    return 0;
}
```

This C++ code defines a function `decimal_to_binary` that converts a decimal number to a binary string representation, and a function `test_decimal_to_binary` that performs unit tests on the `decimal_to_binary` function. The `main` function calls `test_decimal_to_binary` to run the tests and then prints a message indicating that all assertions passed.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `decimal_to_binary` function.

### Fortran Unit Test Code

To compile and run this Fortran code, you might need a Fortran compiler like `gfortran`. Save the following code to a file named `test_decimal_to_binary.f90`:

```fortran
program test_decimal_to_binary
    implicit none
    character(len=100) :: result

    result = decimal_to_binary(0)
    if (trim(result) /= "db0db") then
        write(*,*) "Assertion failed: decimal_to_binary(0) == 'db0db'"
        call exit(1)
    end if

    result = decimal_to_binary(32)
    if (trim(result) /= "db100000db") then
        write(*,*) "Assertion failed: decimal_to_binary(32) == 'db100000db'"
        call exit(1)
    end if

    result = decimal_to_binary(103)
    if (trim(result) /= "db1100111db") then
        write(*,*) "Assertion failed: decimal_to_binary(103) == 'db1100111db'"
        call exit(1)
    end if

    result = decimal_to_binary(15)
    if (trim(result) /= "db1111db") then
        write(*,*) "Assertion failed: decimal_to_binary(15) == 'db1111db'"
        call exit(1)
    end if

    write(*,*) "All assertions passed."

contains

    character(len=100) function decimal_to_binary(decimal)
        implicit none
        integer, intent(in) :: decimal
        integer :: temp
        character(len=100) :: out
        character(len=1) :: digit

        out = ""
        if (decimal == 0) then
            decimal_to_binary = "db0db"
            return
        end if

        temp = decimal
        do while (temp > 0)
            write(digit, '(I1)') mod(temp, 2)
            out = trim(digit) // out
            temp = temp / 2
        end do

        decimal_to_binary = "db" // trim(out) // "db"
    end function decimal_to_binary

end program test_decimal_to_binary
```

### C++ Unit Test Code

To compile and run this C++ code, you might need a C++ compiler like `g++`. Save the following code to a file named `test_decimal_to_binary.cpp`:

```cpp
#include <iostream>
#include <string>
#include <cstdlib> // For std::exit

std::string decimal_to_binary(int decimal) {
    std::string out;
    if (decimal == 0) {
        return "db0db";
    }

    int temp = decimal;
    while (temp > 0) {
        out += (temp % 2 == 0) ? '0' : '1';
        temp /= 2;
    }

    return "db" + out + "db";
}

void test_decimal_to_binary() {
    std::string result;

    result = decimal_to_binary(0);
    if (result != "db0db") {
        std::cerr << "Assertion failed: decimal_to_binary(0) == 'db0db'" << std::endl;
        std::exit(1);
    }

    result = decimal_to_binary(32);
    if (result != "db100000db") {
        std::cerr << "Assertion failed: decimal_to_binary(32) == 'db100000db'" << std::endl;
        std::exit(1);
    }

    result = decimal_to_binary(103);
    if (result != "db1100111db") {
        std::cerr << "Assertion failed: decimal_to_binary(103) == 'db1100111db'" << std::endl;
        std::exit(1);
    }

    result = decimal_to_binary(15);
    if (result != "db1111db") {
        std::cerr << "Assertion failed: decimal_to_binary(15) == 'db1111db'" << std::endl;
        std::exit(1);
    }
}

int main() {
    test_decimal_to_binary();
    std::cout << "All assertions passed." << std::endl;
    return 0;
}
```

### Compilation and Execution

- For Fortran:
  ```sh
  gfortran -o test_decimal_to_binary test_decimal_to_binary.f90
  ./test_decimal_to_binary
  ```

- For C++:
  ```sh
  g++ -o test_decimal_to_binary test_decimal_to_binary.cpp
  ./test_decimal_to_binary
  ```

These unit tests will verify the correctness of the `decimal_to_binary` function in both the Fortran and C++ implementations. If all assertions pass, the programs will print "All assertions passed."
