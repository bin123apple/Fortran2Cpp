Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the necessary headers and uses the standard library for string manipulation.

```cpp
#include <iostream>
#include <string>
#include <algorithm>

std::string string_xor(const std::string& a, const std::string& b) {
    std::string output;
    size_t len_a = a.length(), len_b = b.length();
    size_t min_len = std::min(len_a, len_b);

    for (size_t i = 0; i < min_len; ++i) {
        if (a[i] == b[i]) {
            output += '0';
        } else {
            output += '1';
        }
    }

    if (len_a > len_b) {
        output += a.substr(min_len);
    } else if (len_b > len_a) {
        output += b.substr(min_len);
    }

    return output;
}

int main() {
    std::string result;

    // Test cases
    result = string_xor("111000", "101010");
    if (result != "010010") {
        std::cerr << "Assertion failed: string_xor('111000', '101010') /= '010010'" << std::endl;
        return 1;
    }

    result = string_xor("1", "1");
    if (result != "0") {
        std::cerr << "Assertion failed: string_xor('1', '1') /= '0'" << std::endl;
        return 1;
    }

    result = string_xor("0101", "0000");
    if (result != "0101") {
        std::cerr << "Assertion failed: string_xor('0101', '0000') /= '0101'" << std::endl;
        return 1;
    }

    return 0;
}
```

This C++ code defines a `string_xor` function that performs the same operation as the Fortran function. It compares corresponding characters of the input strings and appends a '0' if they are equal and a '1' if they are different, then concatenates the remaining characters of the longer string. The `main` function contains the test cases similar to the Fortran program.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `string_xor` function in both languages.

### Fortran Unit Test Code

To compile and run this Fortran code, you might need a Fortran compiler like `gfortran`. Save the code to a file, for example, `test_string_xor.f90`, and then compile and run it using the following commands:

```sh
gfortran -o test_string_xor test_string_xor.f90
./test_string_xor
```

```fortran
program test_string_xor
    implicit none
    character(len=:), allocatable :: result

    ! Test cases
    result = string_xor("111000", "101010")
    if (result /= "010010") then
        write(*,*) "Test failed: string_xor('111000', '101010') /= '010010'"
        call exit(1)
    end if

    result = string_xor("1", "1")
    if (result /= "0") then
        write(*,*) "Test failed: string_xor('1', '1') /= '0'"
        call exit(1)
    end if

    result = string_xor("0101", "0000")
    if (result /= "0101") then
        write(*,*) "Test failed: string_xor('0101', '0000') /= '0101'"
        call exit(1)
    end if

    write(*,*) "All tests passed."

contains

    function string_xor(a, b) result(output)
        character(len=*), intent(in) :: a, b
        character(len=:), allocatable :: output
        integer :: i, len_a, len_b, min_len

        len_a = len(a)
        len_b = len(b)
        min_len = min(len_a, len_b)
        output = ""

        do i = 1, min_len
            if (a(i:i) == b(i:i)) then
                output = output // '0'
            else
                output = output // '1'
            end if
        end do

        if (len_a > len_b) then
            output = output // a(min_len+1:len_a)
        else if (len_b > len_a) then
            output = output // b(min_len+1:len_b)
        end if
    end function string_xor

end program test_string_xor
```

### C++ Unit Test Code

To compile and run this C++ code, you might need a C++ compiler like `g++`. Save the code to a file, for example, `test_string_xor.cpp`, and then compile and run it using the following commands:

```sh
g++ -o test_string_xor test_string_xor.cpp
./test_string_xor
```

```cpp
#include <iostream>
#include <string>
#include <algorithm>

std::string string_xor(const std::string& a, const std::string& b) {
    std::string output;
    size_t len_a = a.length(), len_b = b.length();
    size_t min_len = std::min(len_a, len_b);

    for (size_t i = 0; i < min_len; ++i) {
        if (a[i] == b[i]) {
            output += '0';
        } else {
            output += '1';
        }
    }

    if (len_a > len_b) {
        output += a.substr(min_len);
    } else if (len_b > len_a) {
        output += b.substr(min_len);
    }

    return output;
}

int main() {
    std::string result;

    // Test cases
    result = string_xor("111000", "101010");
    if (result != "010010") {
        std::cerr << "Test failed: string_xor('111000', '101010') /= '010010'" << std::endl;
        return 1;
    }

    result = string_xor("1", "1");
    if (result != "0") {
        std::cerr << "Test failed: string_xor('1', '1') /= '0'" << std::endl;
        return 1;
    }

    result = string_xor("0101", "0000");
    if (result != "0101") {
        std::cerr << "Test failed: string_xor('0101', '0000') /= '0101'" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
```

These unit test codes will verify the correctness of the `string_xor` function in both Fortran and C++ by running the specified test cases. If all tests pass, it will print "All tests passed."
