Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the necessary functions to perform the base conversion and integer to string conversion, similar to the Fortran version.

```cpp
#include <iostream>
#include <string>
#include <cstdlib> // For exit()

// Function to change base
std::string change_base(int x, int base) {
    std::string out;
    int temp_x = x;
    while (temp_x > 0) {
        int remainder = temp_x % base;
        out = std::to_string(remainder) + out;
        temp_x = temp_x / base;
    }
    return out;
}

// Integer to string conversion function
std::string itoa(int num) {
    return std::to_string(num);
}

int main() {
    // Assertions
    if (change_base(8, 3) != "22") {
        std::cerr << "Assertion failed: change_base(8, 3) == '22'" << std::endl;
        std::exit(1);
    }
    if (change_base(9, 3) != "100") {
        std::cerr << "Assertion failed: change_base(9, 3) == '100'" << std::endl;
        std::exit(1);
    }
    if (change_base(234, 2) != "11101010") {
        std::cerr << "Assertion failed: change_base(234, 2) == '11101010'" << std::endl;
        std::exit(1);
    }
    if (change_base(16, 2) != "10000") {
        std::cerr << "Assertion failed: change_base(16, 2) == '10000'" << std::endl;
        std::exit(1);
    }
    if (change_base(8, 2) != "1000") {
        std::cerr << "Assertion failed: change_base(8, 2) == '1000'" << std::endl;
        std::exit(1);
    }
    if (change_base(7, 2) != "111") {
        std::cerr << "Assertion failed: change_base(7, 2) == '111'" << std::endl;
        std::exit(1);
    }

    for (int x = 2; x <= 7; ++x) {
        if (change_base(x, x + 1) != itoa(x)) {
            std::cerr << "Assertion failed: change_base(" << x << ", " << x + 1 << ") == " << x << std::endl;
            std::exit(1);
        }
    }

    return 0;
}
```

This C++ code includes the necessary functions to perform the base conversion and integer to string conversion, similar to the Fortran version. The `change_base` function converts an integer `x` from its current base to a new base `base`, and `itoa` converts an integer to a string. The main function contains assertions to verify the correctness of the `change_base` function.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These unit tests will verify the correctness of the `change_base` function in both languages.

### Fortran Unit Test Code

```fortran
program change_base_test
    implicit none
    character(len=100) :: result
    integer :: x

    ! Test cases
    if (trim(change_base(8, 3)) /= "22") then
        write(*,*) "Test failed: change_base(8, 3) == '22'"
    else
        write(*,*) "Test passed: change_base(8, 3) == '22'"
    end if

    if (trim(change_base(9, 3)) /= "100") then
        write(*,*) "Test failed: change_base(9, 3) == '100'"
    else
        write(*,*) "Test passed: change_base(9, 3) == '100'"
    end if

    if (trim(change_base(234, 2)) /= "11101010") then
        write(*,*) "Test failed: change_base(234, 2) == '11101010'"
    else
        write(*,*) "Test passed: change_base(234, 2) == '11101010'"
    end if

    if (trim(change_base(16, 2)) /= "10000") then
        write(*,*) "Test failed: change_base(16, 2) == '10000'"
    else
        write(*,*) "Test passed: change_base(16, 2) == '10000'"
    end if

    if (trim(change_base(8, 2)) /= "1000") then
        write(*,*) "Test failed: change_base(8, 2) == '1000'"
    else
        write(*,*) "Test passed: change_base(8, 2) == '1000'"
    end if

    if (trim(change_base(7, 2)) /= "111") then
        write(*,*) "Test failed: change_base(7, 2) == '111'"
    else
        write(*,*) "Test passed: change_base(7, 2) == '111'"
    end if

contains
    ! Function to change base
    character(len=100) function change_base(x, base)
        implicit none
        integer, intent(in) :: x, base
        integer :: temp_x, remainder
        character(len=100) :: out, temp_str
        out = ""
        temp_x = x
        do while (temp_x > 0)
            remainder = mod(temp_x, base)
            write(temp_str, '(I0)') remainder
            out = trim(adjustl(temp_str)) // out
            temp_x = temp_x / base
        end do
        change_base = out
    end function change_base

end program change_base_test
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <string>
#include <cstdlib> // For exit()

// Function to change base
std::string change_base(int x, int base) {
    std::string out;
    int temp_x = x;
    while (temp_x > 0) {
        int remainder = temp_x % base;
        out = std::to_string(remainder) + out;
        temp_x = temp_x / base;
    }
    return out;
}

// Integer to string conversion function
std::string itoa(int num) {
    return std::to_string(num);
}

void test_change_base(int x, int base, const std::string& expected) {
    std::string result = change_base(x, base);
    if (result == expected) {
        std::cout << "Test passed: change_base(" << x << ", " << base << ") == " << expected << std::endl;
    } else {
        std::cerr << "Test failed: change_base(" << x << ", " << base << ") == " << expected << " (Got " << result << ")" << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    test_change_base(8, 3, "22");
    test_change_base(9, 3, "100");
    test_change_base(234, 2, "11101010");
    test_change_base(16, 2, "10000");
    test_change_base(8, 2, "1000");
    test_change_base(7, 2, "111");

    return 0;
}
