Certainly! Below is the equivalent C++ code for the provided Fortran code. This C++ code includes the necessary headers and uses the standard library for string manipulation and I/O operations.

```cpp
#include <iostream>
#include <string>

// Function to count the number of times a substring occurs in a string
int how_many_times(const std::string& str, const std::string& substring) {
    int out = 0;
    size_t str_len = str.length();
    size_t sub_len = substring.length();

    if (str_len == 0) {
        return 0;
    }

    for (size_t i = 0; i < str_len - sub_len + 1; ++i) {
        if (str.substr(i, sub_len) == substring) {
            out++;
        }
    }

    return out;
}

int main() {
    // Test cases
    if (how_many_times("", "x") != 0) {
        std::cerr << "Assertion failed: how_many_times('', 'x') == 0" << std::endl;
        return 1;
    }

    if (how_many_times("xyxyxyx", "x") != 4) {
        std::cerr << "Assertion failed: how_many_times('xyxyxyx', 'x') == 4" << std::endl;
        return 1;
    }

    if (how_many_times("cacacacac", "cac") != 4) {
        std::cerr << "Assertion failed: how_many_times('cacacacac', 'cac') == 4" << std::endl;
        return 1;
    }

    if (how_many_times("john doe", "john") != 1) {
        std::cerr << "Assertion failed: how_many_times('john doe', 'john') == 1" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
```

This C++ code defines a function `how_many_times` that takes two strings as input and returns the number of times the second string occurs in the first string. The `main` function contains several test cases to verify the correctness of the `how_many_times` function. If any of the test cases fail, the program will print an error message and return a non-zero exit code. Otherwise, it will print "All tests passed." indicating success.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `how_many_times` function in both languages.

### Fortran Unit Tests

To compile and run the Fortran unit tests, you can use a Fortran compiler like `gfortran`. Here is the complete Fortran code including the module and the test program:

```fortran
module string_utils
    implicit none
    contains
        integer function how_many_times(str, substring)
            character(len=*), intent(in) :: str, substring
            integer :: i, out, str_len, sub_len

            out = 0
            str_len = len(str)
            sub_len = len(substring)

            if (str_len == 0) then
                how_many_times = 0
                return
            end if

            do i = 1, str_len - sub_len + 1
                if (str(i:i+sub_len-1) == substring) then
                    out = out + 1
                end if
            end do

            how_many_times = out
        end function how_many_times
end module string_utils

program main
    use string_utils
    implicit none
    integer :: result

    ! Test cases
    result = how_many_times("", "x")
    if (result /= 0) then
        write(*,*) "Assertion failed: how_many_times('', 'x') == 0"
        call exit(1)
    end if

    result = how_many_times("xyxyxyx", "x")
    if (result /= 4) then
        write(*,*) "Assertion failed: how_many_times('xyxyxyx', 'x') == 4"
        call exit(1)
    end if

    result = how_many_times("cacacacac", "cac")
    if (result /= 4) then
        write(*,*) "Assertion failed: how_many_times('cacacacac', 'cac') == 4"
        call exit(1)
    end if

    result = how_many_times("john doe", "john")
    if (result /= 1) then
        write(*,*) "Assertion failed: how_many_times('john doe', 'john') == 1"
        call exit(1)
    end if

    write(*,*) "All tests passed."
end program main
```

To compile and run the Fortran code, you can use the following commands in a terminal:

```sh
gfortran -o string_utils_test string_utils_test.f90
./string_utils_test
```

### C++ Unit Tests

Here is the complete C++ code including the `how_many_times` function and the test cases:

```cpp
#include <iostream>
#include <string>

// Function to count the number of times a substring occurs in a string
int how_many_times(const std::string& str, const std::string& substring) {
    int out = 0;
    size_t str_len = str.length();
    size_t sub_len = substring.length();

    if (str_len == 0) {
        return 0;
    }

    for (size_t i = 0; i < str_len - sub_len + 1; ++i) {
        if (str.substr(i, sub_len) == substring) {
            out++;
        }
    }

    return out;
}

int main() {
    // Test cases
    if (how_many_times("", "x") != 0) {
        std::cerr << "Assertion failed: how_many_times('', 'x') == 0" << std::endl;
        return 1;
    }

    if (how_many_times("xyxyxyx", "x") != 4) {
        std::cerr << "Assertion failed: how_many_times('xyxyxyx', 'x') == 4" << std::endl;
        return 1;
    }

    if (how_many_times("cacacacac", "cac") != 4) {
        std::cerr << "Assertion failed: how_many_times('cacacacac', 'cac') == 4" << std::endl;
        return 1;
    }

    if (how_many_times("john doe", "john") != 1) {
        std::cerr << "Assertion failed: how_many_times('john doe', 'john') == 1" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
```

To compile and run the C++ code, you can use the following commands in a terminal:

```sh
g++ -o string_utils_test string_utils_test.cpp
./string_utils_test
```

These unit tests will verify the correctness of the `how_many_times` function in both Fortran and C++. If any of the tests fail, the program will print an error message and exit with a non-zero status. Otherwise, it will print "All tests passed." indicating success.
