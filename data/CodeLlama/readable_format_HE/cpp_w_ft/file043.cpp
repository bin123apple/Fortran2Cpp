Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the necessary headers and uses standard I/O streams for output.

```cpp
#include <iostream>
#include <string>
#include <cassert>

std::string remove_vowels(const std::string& text) {
    std::string vowels = "AEIOUaeiou";
    std::string result;

    for (char c : text) {
        if (vowels.find(c) == std::string::npos) {
            result += c;
        }
    }

    return result;
}

void assert_test(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    assert_test(remove_vowels("") == "");
    assert_test(remove_vowels("abcdef//nghijklm") == "bcdf//nghjklm");
    assert_test(remove_vowels("fedcba") == "fdcb");
    assert_test(remove_vowels("eeeee") == "");
    assert_test(remove_vowels("acBAA") == "cB");
    assert_test(remove_vowels("EcBOO") == "cB");
    assert_test(remove_vowels("ybcd") == "ybcd");

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}
```

### Explanation:
1. **Function `remove_vowels`**: This function takes a `std::string` as input and returns a new string with all vowels removed. It uses a `std::string` for the vowels and iterates through the input string, copying non-vowel characters to the result string.

2. **`assert_test`**: This function is a simple assertion utility that checks the condition and prints an error message if the condition is false, then exits the program with a non-zero status. It's a direct translation of the Fortran `assert` subroutine.

3. **`main` function**: This is the entry point of the C++ program. It contains the test cases that call `assert_test` with the expected outcomes. If all tests pass, it prints a success message.

This code should compile with a standard C++ compiler and run the tests as expected.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `remove_vowels` function in both languages.

### Fortran Unit Test Code

```fortran
program remove_vowels_program
    implicit none
    character(len=100) :: text, result
    character(len=100) :: empty_string
    character(len=100) :: vowels
    integer :: i

    ! Test cases
    empty_string = ""
    call assert(remove_vowels(empty_string) == "")
    call assert(remove_vowels("abcdef//nghijklm") == "bcdf//nghjklm")
    call assert(remove_vowels("fedcba") == "fdcb")
    call assert(remove_vowels("eeeee") == "")
    call assert(remove_vowels("acBAA") == "cB")
    call assert(remove_vowels("EcBOO") == "cB")
    call assert(remove_vowels("ybcd") == "ybcd")

contains

    function remove_vowels(text) result(out)
        character(len=*), intent(in) :: text
        character(len=100) :: out
        character(len=100) :: vowels
        integer :: i, j, len_text, len_vowels
        logical :: is_vowel

        out = ""
        vowels = "AEIOUaeiou"
        len_text = len_trim(text)
        len_vowels = len_trim(vowels)

        do i = 1, len_text
            is_vowel = .false.
            do j = 1, len_vowels
                if (text(i:i) == vowels(j:j)) then
                    is_vowel = .true.
                    exit
                end if
            end do
            if (.not. is_vowel) then
                out = trim(out) // text(i:i)
            end if
        end do
    end function remove_vowels

    subroutine assert(condition)
        logical, intent(in) :: condition
        if (.not. condition) then
            write(*,*) "Assertion failed"
            call exit(1)
        end if
    end subroutine assert

end program remove_vowels_program
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <string>
#include <cassert>

std::string remove_vowels(const std::string& text) {
    std::string vowels = "AEIOUaeiou";
    std::string result;

    for (char c : text) {
        if (vowels.find(c) == std::string::npos) {
            result += c;
        }
    }

    return result;
}

void assert_test(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    assert_test(remove_vowels("") == "");
    assert_test(remove_vowels("abcdef//nghijklm") == "bcdf//nghjklm");
    assert_test(remove_vowels("fedcba") == "fdcb");
    assert_test(remove_vowels("eeeee") == "");
    assert_test(remove_vowels("acBAA") == "cB");
    assert_test(remove_vowels("EcBOO") == "cB");
    assert_test(remove_vowels("ybcd") == "ybcd");

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**: This program includes the `remove_vowels` function and a simple `assert` subroutine to check the correctness of the function. It tests various strings with and without vowels to ensure the function works as expected.

2. **C++ Unit Test Code**: This program mirrors the Fortran unit test code, using C++ syntax and constructs. It includes the `remove_vowels` function and an `assert_test` function to validate the correctness of the function.

To compile and run these tests, you would use a Fortran compiler for the Fortran code and a C++ compiler for the C++ code. For example, for Fortran, you might use `gfortran`, and for C++, `g++` or `clang++`.
