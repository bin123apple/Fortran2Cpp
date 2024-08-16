Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the necessary headers and uses the standard library functions and idioms.

```cpp
#include <iostream>
#include <string>
#include <cstdlib> // For exit()

// Function to count vowels in a string
int vowels_count(const std::string& s) {
    int count = 0;
    const std::string vowels = "aeiouAEIOU";

    for (char c : s) {
        if (vowels.find(c) != std::string::npos) {
            count++;
        }
    }

    // Special handling for 'y' at the end of the string
    if (!s.empty() && (s.back() == 'y' || s.back() == 'Y')) {
        count++;
    }

    return count;
}

int main() {
    std::string s;
    int count;

    // Test cases
    s = "abcde";
    count = vowels_count(s);
    if (count != 2) {
        std::cerr << "Assertion failed for 'abcde'" << std::endl;
        std::exit(1);
    }

    s = "Alone";
    count = vowels_count(s);
    if (count != 3) {
        std::cerr << "Assertion failed for 'Alone'" << std::endl;
        std::exit(1);
    }

    s = "key";
    count = vowels_count(s);
    if (count != 2) {
        std::cerr << "Assertion failed for 'key'" << std::endl;
        std::exit(1);
    }

    s = "bye";
    count = vowels_count(s);
    if (count != 1) {
        std::cerr << "Assertion failed for 'bye'" << std::endl;
        std::exit(1);
    }

    s = "keY";
    count = vowels_count(s);
    if (count != 2) {
        std::cerr << "Assertion failed for 'keY'" << std::endl;
        std::exit(1);
    }

    s = "bYe";
    count = vowels_count(s);
    if (count != 1) {
        std::cerr << "Assertion failed for 'bYe'" << std::endl;
        std::exit(1);
    }

    s = "ACEDY";
    count = vowels_count(s);
    if (count != 3) {
        std::cerr << "Assertion failed for 'ACEDY'" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}
```

This C++ code includes the necessary headers for input/output operations and program exit, and it uses the `std::string` class for handling strings, which is a common and powerful feature of C++. The `vowels_count` function iterates through each character of the input string and checks if it is a vowel, counting the vowels as it goes. The special handling for the 'y' at the end of the string is also included, as in the original Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `vowels_count` function in both languages.

### Fortran Unit Test Code

To compile and run this Fortran code, you might need a Fortran compiler like `gfortran`. Save the following code in a file named `test_fortran.f90`:

```fortran
program test_vowels_count
    implicit none
    integer :: count

    ! Test cases
    count = vowels_count("abcde")
    if (count /= 2) then
        write(*,*) "Test failed for 'abcde'"
        stop 1
    end if

    count = vowels_count("Alone")
    if (count /= 3) then
        write(*,*) "Test failed for 'Alone'"
        stop 1
    end if

    count = vowels_count("key")
    if (count /= 2) then
        write(*,*) "Test failed for 'key'"
        stop 1
    end if

    count = vowels_count("bye")
    if (count /= 1) then
        write(*,*) "Test failed for 'bye'"
        stop 1
    end if

    count = vowels_count("keY")
    if (count /= 2) then
        write(*,*) "Test failed for 'keY'"
        stop 1
    end if

    count = vowels_count("bYe")
    if (count /= 1) then
        write(*,*) "Test failed for 'bYe'"
        stop 1
    end if

    count = vowels_count("ACEDY")
    if (count /= 3) then
        write(*,*) "Test failed for 'ACEDY'"
        stop 1
    end if

    write(*,*) "All tests passed successfully."

contains

    function vowels_count(s) result(count)
        implicit none
        character(len=*), intent(in) :: s
        integer :: count
        character(len=10) :: vowels
        integer :: i

        vowels = "aeiouAEIOU"
        count = 0

        do i = 1, len(s)
            if (index(vowels, s(i:i)) > 0) then
                count = count + 1
            end if
        end do

        if (s(len(s):len(s)) == 'y' .or. s(len(s):len(s)) == 'Y') then
            count = count + 1
        end if
    end function vowels_count

end program test_vowels_count
```

### C++ Unit Test Code

To compile and run this C++ code, you might need a C++ compiler like `g++`. Save the following code in a file named `test_cpp.cpp`:

```cpp
#include <iostream>
#include <string>
#include <cstdlib> // For exit()

// Function to count vowels in a string
int vowels_count(const std::string& s) {
    int count = 0;
    const std::string vowels = "aeiouAEIOU";

    for (char c : s) {
        if (vowels.find(c) != std::string::npos) {
            count++;
        }
    }

    // Special handling for 'y' at the end of the string
    if (!s.empty() && (s.back() == 'y' || s.back() == 'Y')) {
        count++;
    }

    return count;
}

void test_vowels_count(const std::string& test_case, int expected) {
    int result = vowels_count(test_case);
    if (result != expected) {
        std::cerr << "Test failed for '" << test_case << "'. Expected " << expected << ", got " << result << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    test_vowels_count("abcde", 2);
    test_vowels_count("Alone", 3);
    test_vowels_count("key", 2);
    test_vowels_count("bye", 1);
    test_vowels_count("keY", 2);
    test_vowels_count("bYe", 1);
    test_vowels_count("ACEDY", 3);

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran code, use the following commands in your terminal:

```sh
gfortran -o test_fortran test_fortran.f90
./test_fortran
