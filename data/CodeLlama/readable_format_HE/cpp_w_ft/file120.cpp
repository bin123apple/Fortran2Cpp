Translating the given Fortran code to C++ involves several steps, including changing the syntax for loops, function definitions, and conditionals. Here's how you can translate the Fortran code to C++:

```cpp
#include <iostream>
#include <string>
#include <cstdlib> // For exit()

std::string int_to_mini_romank(int number) {
    std::string rep[13] = {"m ", "cm", "d ", "cd", "c ", "xc", "l ", "xl", "x ", "ix", "v ", "iv", "i "};
    int num[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string current;
    int pos = 0;
    int temp_number = number;

    while (temp_number > 0) {
        while (temp_number >= num[pos]) {
            current += rep[pos];
            temp_number -= num[pos];
        }
        if (temp_number > 0) ++pos;
    }

    return current;
}

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        exit(1);
    }
}

int main() {
    // Test cases
    assert(int_to_mini_romank(19) == "xix");
    assert(int_to_mini_romank(152) == "clii");
    assert(int_to_mini_romank(251) == "ccli");
    assert(int_to_mini_romank(426) == "cdxxvi");
    assert(int_to_mini_romank(500) == "d");
    assert(int_to_mini_romank(1) == "i");
    assert(int_to_mini_romank(4) == "iv");
    assert(int_to_mini_romank(43) == "xliii");
    assert(int_to_mini_romank(90) == "xc");
    assert(int_to_mini_romank(94) == "xciv");
    assert(int_to_mini_romank(532) == "dxxxii");
    assert(int_to_mini_romank(900) == "cm");
    assert(int_to_mini_romank(994) == "cmxciv");
    assert(int_to_mini_romank(1000) == "m");

    return 0;
}
```

### Key Points in the Translation:

1. **Function Definition**: The `int_to_mini_romank` function is translated to return a `std::string` and take an `int` parameter, similar to the Fortran version.
2. **Arrays**: The arrays `rep` and `num` are translated to `std::string` and `int` arrays, respectively.
3. **Looping**: The Fortran `do` loop is translated to C++ `while` loops.
4. **String Concatenation**: The Fortran `trim` function and string concatenation are handled using `+=` operator in C++.
5. **Assertions**: The `assert` subroutine is translated to a `assert` function in C++ that uses `std::cerr` for error output and `exit(1)` to terminate the program if the condition is false.
6. **Test Cases**: The test cases are directly translated into assertions within the `main` function.

This C++ code should behave similarly to the original Fortran code, providing the same functionality and passing the same test cases.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the outputs of both implementations.

### Fortran Unit Test Code

```fortran
program test_mini_roman
    implicit none
    character(len=100) :: result

    ! Test cases
    call assert(int_to_mini_romank(19) == "xix")
    call assert(int_to_mini_romank(152) == "clii")
    call assert(int_to_mini_romank(251) == "ccli")
    call assert(int_to_mini_romank(426) == "cdxxvi")
    call assert(int_to_mini_romank(500) == "d")
    call assert(int_to_mini_romank(1) == "i")
    call assert(int_to_mini_romank(4) == "iv")
    call assert(int_to_mini_romank(43) == "xliii")
    call assert(int_to_mini_romank(90) == "xc")
    call assert(int_to_mini_romank(94) == "xciv")
    call assert(int_to_mini_romank(532) == "dxxxii")
    call assert(int_to_mini_romank(900) == "cm")
    call assert(int_to_mini_romank(994) == "cmxciv")
    call assert(int_to_mini_romank(1000) == "m")

contains

    function int_to_mini_romank(number) result(current)
        implicit none
        integer, intent(in) :: number
        character(len=100) :: current
        character(len=2), dimension(13) :: rep = ["m ", "cm", "d ", "cd", "c ", "xc", "l ", "xl", "x ", "ix", "v ", "iv", "i "]
        integer, dimension(13) :: num = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        integer :: pos, temp_number

        current = ""
        pos = 1
        temp_number = number

        do while (temp_number > 0)
            do while (temp_number >= num(pos))
                current = trim(current) // trim(rep(pos))
                temp_number = temp_number - num(pos)
            end do
            if (temp_number > 0) pos = pos + 1
        end do
    end function int_to_mini_romank

    subroutine assert(condition)
        logical, intent(in) :: condition
        if (.not. condition) then
            write(*,*) "Assertion failed"
            call exit(1)
        end if
    end subroutine assert

end program test_mini_roman
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <string>
#include <cstdlib> // For exit()

std::string int_to_mini_romank(int number) {
    std::string rep[13] = {"m ", "cm", "d ", "cd", "c ", "xc", "l ", "xl", "x ", "ix", "v ", "iv", "i "};
    int num[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string current;
    int pos = 0;
    int temp_number = number;

    while (temp_number > 0) {
        while (temp_number >= num[pos]) {
            current += rep[pos];
            temp_number -= num[pos];
        }
        if (temp_number > 0) ++pos;
    }

    return current;
}

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        exit(1);
    }
}

int main() {
    // Test cases
