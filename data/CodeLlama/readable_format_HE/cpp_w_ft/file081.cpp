Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

// Function prototype
int count_upper(const std::string& s);

int main() {
    int result;

    // Test cases
    result = count_upper("aBCdEf");
    if (result != 1) {
        std::cerr << "Assertion failed: count_upper('aBCdEf') == 1" << std::endl;
        std::exit(1);
    }

    result = count_upper("abcdefg");
    if (result != 0) {
        std::cerr << "Assertion failed: count_upper('abcdefg') == 0" << std::endl;
        std::exit(1);
    }

    result = count_upper("dBBE");
    if (result != 0) {
        std::cerr << "Assertion failed: count_upper('dBBE') == 0" << std::endl;
        std::exit(1);
    }

    result = count_upper("B");
    if (result != 0) {
        std::cerr << "Assertion failed: count_upper('B') == 0" << std::endl;
        std::exit(1);
    }

    result = count_upper("U");
    if (result != 1) {
        std::cerr << "Assertion failed: count_upper('U') == 1" << std::endl;
        std::exit(1);
    }

    result = count_upper("");
    if (result != 0) {
        std::cerr << "Assertion failed: count_upper('') == 0" << std::endl;
        std::exit(1);
    }

    result = count_upper("EEEE");
    if (result != 2) {
        std::cerr << "Assertion failed: count_upper('EEEE') == 2" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}

int count_upper(const std::string& s) {
    const std::string uvowel = "AEIOU";
    int count = 0;
    size_t len_s = s.length();

    for (size_t i = 0; i < len_s; i += 2) {
        if (uvowel.find(s[i]) != std::string::npos) {
            count++;
        }
    }

    return count;
}
```

This C++ code includes the `count_upper` function, which is equivalent to the Fortran function, and a `main` function that tests this function with various inputs, similar to the Fortran program. The `std::string` class is used to handle strings, and the `std::cerr` and `std::exit` functions are used for error handling and exiting the program, respectively, similar to the Fortran `write` and `exit` statements.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `count_upper` function in both languages.

### Fortran Unit Test Code

To compile and run the Fortran code, you can use a Fortran compiler like `gfortran`. Here is the unit test code:

```fortran
program test_count_upper
    implicit none
    integer :: result

    ! Test cases
    result = count_upper("aBCdEf")
    if (result /= 1) then
        write(*,*) "Test failed: count_upper('aBCdEf') == 1"
    else
        write(*,*) "Test passed: count_upper('aBCdEf') == 1"
    end if

    result = count_upper("abcdefg")
    if (result /= 0) then
        write(*,*) "Test failed: count_upper('abcdefg') == 0"
    else
        write(*,*) "Test passed: count_upper('abcdefg') == 0"
    end if

    result = count_upper("dBBE")
    if (result /= 0) then
        write(*,*) "Test failed: count_upper('dBBE') == 0"
    else
        write(*,*) "Test passed: count_upper('dBBE') == 0"
    end if

    result = count_upper("B")
    if (result /= 0) then
        write(*,*) "Test failed: count_upper('B') == 0"
    else
        write(*,*) "Test passed: count_upper('B') == 0"
    end if

    result = count_upper("U")
    if (result /= 1) then
        write(*,*) "Test failed: count_upper('U') == 1"
    else
        write(*,*) "Test passed: count_upper('U') == 1"
    end if

    result = count_upper("")
    if (result /= 0) then
        write(*,*) "Test failed: count_upper('') == 0"
    else
        write(*,*) "Test passed: count_upper('') == 0"
    end if

    result = count_upper("EEEE")
    if (result /= 2) then
        write(*,*) "Test failed: count_upper('EEEE') == 2"
    else
        write(*,*) "Test passed: count_upper('EEEE') == 2"
    end if

contains

    function count_upper(s) result(count)
        implicit none
        character(len=*), intent(in) :: s
        integer :: count
        character(len=5) :: uvowel
        integer :: i, len_s

        uvowel = "AEIOU"
        count = 0
        len_s = len_trim(s)

        do i = 1, len_s, 2
            if (index(uvowel, s(i:i)) > 0) then
                count = count + 1
            end if
        end do
    end function count_upper

end program test_count_upper
```

### C++ Unit Test Code

To compile and run the C++ code, you can use a C++ compiler like `g++`. Here is the unit test code:

```cpp
#include <iostream>
#include <string>
#include <cassert>

// Function prototype
int count_upper(const std::string& s);

int main() {
    // Test cases
    assert(count_upper("aBCdEf") == 1);
    std::cout << "Test passed: count_upper('aBCdEf') == 1" << std::endl;

    assert(count_upper("abcdefg") == 0);
    std::cout << "Test passed: count_upper('abcdefg') == 0" << std::endl;

    assert(count_upper("dBBE") == 0);
    std::cout << "Test passed: count_upper('dBBE') == 0" << std::endl;

    assert(count_upper("B") == 0);
    std::cout << "Test passed: count_upper('B') == 0" << std::endl;

    assert(count_upper("U") == 1);
    std::cout << "Test passed: count_upper('U') == 1" << std::endl;

    assert(count_upper("") == 0);
    std::cout << "Test passed: count_upper('') == 0" << std::endl;

    assert(count_upper("EEEE") == 2);
    std::cout << "Test passed: count_upper('EEEE') == 2" << std::endl;

    std::cout << "All tests passed." << std::endl;

    return 0;
}

int count_upper(const std::string& s) {
    const std::string uvowel = "AEIOU";
    int count = 0;
    size_t len_s = s.length();

    for (size_t i = 0; i < len_s; i += 2) {
        if (uvowel.find(s[i]) != std::string::npos)
