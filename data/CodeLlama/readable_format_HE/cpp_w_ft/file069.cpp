Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

bool is_happy(const std::string& s) {
    if (s.length() < 3) {
        return false;
    }

    for (size_t i = 3; i <= s.length(); ++i) {
        if (s[i - 1] == s[i - 2] || s[i - 1] == s[i - 3]) {
            return false;
        }
    }

    return true;
}

int main() {
    // Test cases
    if (!is_happy("a")) {
        std::cout << "Test 1 passed" << std::endl;
    } else {
        std::cout << "Test 1 failed" << std::endl;
        std::exit(1);
    }

    if (!is_happy("aa")) {
        std::cout << "Test 2 passed" << std::endl;
    } else {
        std::cout << "Test 2 failed" << std::endl;
        std::exit(1);
    }

    if (is_happy("abcd")) {
        std::cout << "Test 3 passed" << std::endl;
    } else {
        std::cout << "Test 3 failed" << std::endl;
        std::exit(1);
    }

    if (!is_happy("aabb")) {
        std::cout << "Test 4 passed" << std::endl;
    } else {
        std::cout << "Test 4 failed" << std::endl;
        std::exit(1);
    }

    if (is_happy("adb")) {
        std::cout << "Test 5 passed" << std::endl;
    } else {
        std::cout << "Test 5 failed" << std::endl;
        std::exit(1);
    }

    if (!is_happy("xyy")) {
        std::cout << "Test 6 passed" << std::endl;
    } else {
        std::cout << "Test 6 failed" << std::endl;
        std::exit(1);
    }

    if (is_happy("iopaxpoi")) {
        std::cout << "Test 7 passed" << std::endl;
    } else {
        std::cout << "Test 7 failed" << std::endl;
        std::exit(1);
    }

    if (!is_happy("iopaxioi")) {
        std::cout << "Test 8 passed" << std::endl;
    } else {
        std::cout << "Test 8 failed" << std::endl;
        std::exit(1);
    }

    return 0;
}
```

This C++ code includes the `is_happy` function to check if a given string is happy, and a `main` function that runs several test cases to verify the correctness of the `is_happy` function. The tests are designed to match the Fortran tests, ensuring the same logic and outcomes are tested.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `is_happy` function in both languages.

### Fortran Unit Test Code

```fortran
program test_is_happy
    implicit none

    ! Test cases
    call test_case("a", .false.)
    call test_case("aa", .false.)
    call test_case("abcd", .true.)
    call test_case("aabb", .false.)
    call test_case("adb", .true.)
    call test_case("xyy", .false.)
    call test_case("iopaxpoi", .true.)
    call test_case("iopaxioi", .false.)

contains

    subroutine test_case(s, expected)
        character(len=*), intent(in) :: s
        logical, intent(in) :: expected
        logical :: result

        result = is_happy(s)
        if (result .eqv. expected) then
            write(*,*) "Test passed for: ", s
        else
            write(*,*) "Test failed for: ", s
            call exit(1)
        end if
    end subroutine test_case

    logical function is_happy(s)
        character(len=*), intent(in) :: s
        integer :: i

        if (len(s) < 3) then
            is_happy = .false.
            return
        end if

        do i = 3, len(s)
            if (s(i:i) == s(i-1:i-1) .or. s(i:i) == s(i-2:i-2)) then
                is_happy = .false.
                return
            end if
        end do

        is_happy = .true.
    end function is_happy

end program test_is_happy
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

bool is_happy(const std::string& s) {
    if (s.length() < 3) {
        return false;
    }

    for (size_t i = 3; i <= s.length(); ++i) {
        if (s[i - 1] == s[i - 2] || s[i - 1] == s[i - 3]) {
            return false;
        }
    }

    return true;
}

void test_case(const std::string& s, bool expected) {
    bool result = is_happy(s);
    if (result == expected) {
        std::cout << "Test passed for: " << s << std::endl;
    } else {
        std::cout << "Test failed for: " << s << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    test_case("a", false);
    test_case("aa", false);
    test_case("abcd", true);
    test_case("aabb", false);
    test_case("adb", true);
    test_case("xyy", false);
    test_case("iopaxpoi", true);
    test_case("iopaxioi", false);

    return 0;
}
```

### Explanation

- **Fortran Unit Test Code**: This code defines a `test_case` subroutine that takes a string `s` and an expected result `expected`. It then checks if the `is_happy` function returns the expected result for the given string. If the result matches the expected result, it prints "Test passed"; otherwise, it prints "Test failed" and exits with an error code.

- **C++ Unit Test Code**: This code defines a `test_case` function that takes a string `s` and an expected result `expected`. It then checks if the `is_happy` function returns the expected result for the given string. If the result matches the expected result, it prints "Test passed"; otherwise, it prints "Test failed" and exits with an error code.

Both unit test codes are designed to ensure that the `is_happy` function behaves correctly across a range of inputs, matching the original Fortran logic and outcomes.
