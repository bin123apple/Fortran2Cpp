Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

std::string file_name_check(const std::string& file_name) {
    int numdigit = 0;
    int numdot = 0;
    std::string last;
    char w;

    if (file_name.length() < 5) {
        return "No";
    }

    w = file_name[0];
    if (w < 'A' || (w > 'Z' && w < 'a') || w > 'z') {
        return "No";
    }

    last = file_name.substr(file_name.length() - 4, 4);
    if (last != ".txt" && last != ".exe" && last != ".dll") {
        return "No";
    }

    for (size_t i = 0; i < file_name.length(); ++i) {
        if (file_name[i] >= '0' && file_name[i] <= '9') {
            ++numdigit;
        }
        if (file_name[i] == '.') {
            ++numdot;
        }
    }

    if (numdigit > 3 || numdot != 1) {
        return "No";
    } else {
        return "Yes";
    }
}

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    assert(file_name_check("example.txt") == "Yes");
    assert(file_name_check("1example.dll") == "No");
    assert(file_name_check("s1sdf3.asd") == "No");
    assert(file_name_check("K.dll") == "Yes");
    assert(file_name_check("MY16FILE3.exe") == "Yes");
    assert(file_name_check("His12FILE94.exe") == "No");
    assert(file_name_check("_Y.txt") == "No");
    assert(file_name_check("?aREYA.exe") == "No");
    assert(file_name_check("/this_is_valid.dll") == "No");
    assert(file_name_check("this_is_valid.wow") == "No");
    assert(file_name_check("this_is_valid.txt") == "Yes");
    assert(file_name_check("this_is_valid.txtexe") == "No");
    assert(file_name_check("#this2_i4s_5valid.ten") == "No");
    assert(file_name_check("@this1_is6_valid.exe") == "No");
    assert(file_name_check("this_is_12valid.6exe4.txt") == "No");
    assert(file_name_check("all.exe.txt") == "No");
    assert(file_name_check("I563_No.exe") == "Yes");
    assert(file_name_check("Is3youfault.txt") == "Yes");
    assert(file_name_check("no_one#knows.dll") == "Yes");
    assert(file_name_check("1I563_Yes3.exe") == "No");
    assert(file_name_check("I563_Yes3.txtt") == "No");
    assert(file_name_check("final..txt") == "No");
    assert(file_name_check("final132") == "No");
    assert(file_name_check("_f4indsartal132.") == "No");
    assert(file_name_check(".txt") == "No");
    assert(file_name_check("s.") == "No");

    return 0;
}
```

This C++ code includes the `file_name_check` function and the `assert` function to verify the correctness of the Fortran code's logic. The `main` function contains a series of test cases to verify the correctness of the `file_name_check` function.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program file_name_check_program
    implicit none

    ! Test cases
    call assert(file_name_check('example.txt') == 'Yes')
    call assert(file_name_check('1example.dll') == 'No')
    call assert(file_name_check('s1sdf3.asd') == 'No')
    call assert(file_name_check('K.dll') == 'Yes')
    call assert(file_name_check('MY16FILE3.exe') == 'Yes')
    call assert(file_name_check('His12FILE94.exe') == 'No')
    call assert(file_name_check('_Y.txt') == 'No')
    call assert(file_name_check('?aREYA.exe') == 'No')
    call assert(file_name_check('/this_is_valid.dll') == 'No')
    call assert(file_name_check('this_is_valid.wow') == 'No')
    call assert(file_name_check('this_is_valid.txt') == 'Yes')
    call assert(file_name_check('this_is_valid.txtexe') == 'No')
    call assert(file_name_check('#this2_i4s_5valid.ten') == 'No')
    call assert(file_name_check('@this1_is6_valid.exe') == 'No')
    call assert(file_name_check('this_is_12valid.6exe4.txt') == 'No')
    call assert(file_name_check('all.exe.txt') == 'No')
    call assert(file_name_check('I563_No.exe') == 'Yes')
    call assert(file_name_check('Is3youfault.txt') == 'Yes')
    call assert(file_name_check('no_one#knows.dll') == 'Yes')
    call assert(file_name_check('1I563_Yes3.exe') == 'No')
    call assert(file_name_check('I563_Yes3.txtt') == 'No')
    call assert(file_name_check('final..txt') == 'No')
    call assert(file_name_check('final132') == 'No')
    call assert(file_name_check('_f4indsartal132.') == 'No')
    call assert(file_name_check('.txt') == 'No')
    call assert(file_name_check('s.') == 'No')

contains

    character(len=3) function file_name_check(file_name)
        character(len=*), intent(in) :: file_name
        integer :: numdigit, numdot, i
        character(len=4) :: last
        character(len=1) :: w

        numdigit = 0
        numdot = 0

        if (len_trim(file_name) < 5) then
            file_name_check = 'No'
            return
        end if

        w = file_name(1:1)
        if (ichar(w) < 65 .or. (ichar(w) > 90 .and. ichar(w) < 97) .or. ichar(w) > 122) then
            file_name_check = 'No'
            return
        end if

        last = file_name(len_trim(file_name)-3:len_trim(file_name))
        if (last /= '.txt' .and. last /= '.exe' .and. last /= '.dll') then
            file_name_check = 'No'
            return
        end if

        do i = 1, len_trim(file_name)
            if (ichar(file_name(i:i)) >= 48 .and. ichar(file_name(i:i)) <= 57) numdigit = numdigit +
