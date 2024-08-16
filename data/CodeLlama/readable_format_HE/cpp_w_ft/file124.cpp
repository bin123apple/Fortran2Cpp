Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <string>
#include <cctype> // for std::tolower and std::toupper

std::string solve(const std::string& s) {
    std::string out;
    int nletter = 0;
    bool is_reversed = true;

    for (char c : s) {
        if (isalpha(c)) {
            if (isupper(c)) {
                out += std::tolower(c);
            } else {
                out += std::toupper(c);
            }
        } else {
            nletter++;
            out += c;
        }
    }

    if (nletter == s.size()) {
        std::reverse(out.begin(), out.end());
    }

    return out;
}

std::string reverse_string(const std::string& s) {
    std::string rev;
    for (char c : s) {
        rev += c;
    }
    std::reverse(rev.begin(), rev.end());
    return rev;
}

int main() {
    std::string s, result;

    // Test cases
    s = "AsDf";
    result = solve(s);
    if (result != "aSdF") {
        std::cerr << "Assertion failed: solve('AsDf') == 'aSdF'" << std::endl;
        return 1;
    }

    s = "1234";
    result = solve(s);
    if (result != "4321") {
        std::cerr << "Assertion failed: solve('1234') == '4321'" << std::endl;
        return 1;
    }

    s = "ab";
    result = solve(s);
    if (result != "AB") {
        std::cerr << "Assertion failed: solve('ab') == 'AB'" << std::endl;
        return 1;
    }

    s = "#a@C";
    result = solve(s);
    if (result != "#A@c") {
        std::cerr << "Assertion failed: solve('#a@C') == '#A@c'" << std::endl;
        return 1;
    }

    s = "#AsdfW^45";
    result = solve(s);
    if (result != "#aSDFw^45") {
        std::cerr << "Assertion failed: solve('#AsdfW^45') == '#aSDFw^45'" << std::endl;
        return 1;
    }

    s = "#6@2";
    result = solve(s);
    if (result != "2@6#") {
        std::cerr << "Assertion failed: solve('#6@2') == '2@6#'" << std::endl;
        return 1;
    }

    s = "#$a^D";
    result = solve(s);
    if (result != "#$A^d") {
        std::cerr << "Assertion failed: solve('#$a^D') == '#$A^d'" << std::endl;
        return 1;
    }

    s = "#ccc";
    result = solve(s);
    if (result != "#CCC") {
        std::cerr << "Assertion failed: solve('#ccc') == '#CCC'" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}
```

This C++ code includes the `solve` function, which mimics the functionality of the Fortran `solve` function, and the `reverse_string` function, which is used to reverse the string. The `main` function contains the test cases that verify the correctness of the `solve` function.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `solve` function in both languages.

### Fortran Unit Test Code

```fortran
program test_solve
    implicit none
    character(len=100) :: s, result

    ! Test cases
    s = "AsDf"
    result = solve(trim(s))
    if (trim(result) /= "aSdF") then
        write(*,*) "Assertion failed: solve('AsDf') == 'aSdF'"
        call exit(1)
    end if

    s = "1234"
    result = solve(trim(s))
    if (trim(result) /= "4321") then
        write(*,*) "Assertion failed: solve('1234') == '4321'"
        call exit(1)
    end if

    s = "ab"
    result = solve(trim(s))
    if (trim(result) /= "AB") then
        write(*,*) "Assertion failed: solve('ab') == 'AB'"
        call exit(1)
    end if

    s = "#a@C"
    result = solve(trim(s))
    if (trim(result) /= "#A@c") then
        write(*,*) "Assertion failed: solve('#a@C') == '#A@c'"
        call exit(1)
    end if

    s = "#AsdfW^45"
    result = solve(trim(s))
    if (trim(result) /= "#aSDFw^45") then
        write(*,*) "Assertion failed: solve('#AsdfW^45') == '#aSDFw^45'"
        call exit(1)
    end if

    s = "#6@2"
    result = solve(trim(s))
    if (trim(result) /= "2@6#") then
        write(*,*) "Assertion failed: solve('#6@2') == '2@6#'"
        call exit(1)
    end if

    s = "#$a^D"
    result = solve(trim(s))
    if (trim(result) /= "#$A^d") then
        write(*,*) "Assertion failed: solve('#$a^D') == '#$A^d'"
        call exit(1)
    end if

    s = "#ccc"
    result = solve(trim(s))
    if (trim(result) /= "#CCC") then
        write(*,*) "Assertion failed: solve('#ccc') == '#CCC'"
        call exit(1)
    end if

    write(*,*) "All tests passed."

contains

    function solve(s) result(out)
        implicit none
        character(len=*), intent(in) :: s
        character(len=100) :: out
        integer :: i, nletter, len_s
        character(len=1) :: w

        nletter = 0
        out = ""
        len_s = len_trim(s)

        do i = 1, len_s
            w = s(i:i)
            if (iachar(w) >= 65 .and. iachar(w) <= 90) then
                w = achar(iachar(w) + 32)
            else if (iachar(w) >= 97 .and. iachar(w) <= 122) then
                w = achar(iachar(w) - 32)
            else
                nletter = nletter + 1
            end if
            out = trim(out) // w
        end do

        if (nletter == len_s) then
            out = reverse_string(trim(out))
        end if
    end function solve

    function reverse_string(s) result(rev)
        implicit none
        character(len=*), intent(in) :: s
        character(len=100) :: rev
        integer :: i, len_s

        len_s = len_trim(s)
        rev = ""
        do i = len_s, 1, -1
            rev = trim(rev) // s(i:i)
        end do
    end function reverse_string

end program test_solve
```

### C++ Unit Test Code

```cpp
#include <iostream
