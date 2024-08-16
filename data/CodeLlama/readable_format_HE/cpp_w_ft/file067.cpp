Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

const std::string key = "2357BD";

int hex_key(const std::string& num) {
    int out = 0;
    for (size_t i = 0; i < num.length(); ++i) {
        if (key.find(num[i]) != std::string::npos) {
            out += 1;
        }
    }
    return out;
}

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    assert(hex_key("AB") == 1);
    assert(hex_key("1077E") == 2);
    assert(hex_key("ABED1A33") == 4);
    assert(hex_key("2020") == 2);
    assert(hex_key("123456789ABCDEF0") == 6);
    assert(hex_key("112233445566778899AABBCCDDEEFF00") == 12);
    assert(hex_key("") == 0);

    return 0;
}
```

### Explanation:
1. **Key Definition**: The `key` string is defined similarly to the Fortran code.
2. **`hex_key` Function**: This function takes a string `num` as input and returns the number of characters in `num` that are present in the `key` string.
3. **`assert` Function**: This function checks if the condition is `true`. If not, it prints an error message and exits the program with a status code of `1`.
4. **`main` Function**: The `main` function contains assertions similar to the Fortran program. If any assertion fails, the program will exit with an error message.

This C++ code should behave similarly to the original Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

Save the following Fortran code in a file named `hex_key_test.f90`:

```fortran
program hex_key_test
    implicit none
    character(len=*), parameter :: key = "2357BD"
    integer :: result

    ! Main program body
    call assert(hex_key("AB") == 1)
    call assert(hex_key("1077E") == 2)
    call assert(hex_key("ABED1A33") == 4)
    call assert(hex_key("2020") == 2)
    call assert(hex_key("123456789ABCDEF0") == 6)
    call assert(hex_key("112233445566778899AABBCCDDEEFF00") == 12)
    call assert(hex_key("") == 0)

contains

    function hex_key(num) result(out)
        character(len=*), intent(in) :: num
        integer :: out
        integer :: i
        character(len=1) :: char

        out = 0
        do i = 1, len_trim(num)
            char = num(i:i)
            if (index(key, char) /= 0) then
                out = out + 1
            end if
        end do
    end function hex_key

    subroutine assert(condition)
        logical, intent(in) :: condition
        if (.not. condition) then
            write(*,*) "Assertion failed"
            call exit(1)
        end if
    end subroutine assert

end program hex_key_test
```

### C++ Unit Test Code

Save the following C++ code in a file named `hex_key_test.cpp`:

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

const std::string key = "2357BD";

int hex_key(const std::string& num) {
    int out = 0;
    for (size_t i = 0; i < num.length(); ++i) {
        if (key.find(num[i]) != std::string::npos) {
            out += 1;
        }
    }
    return out;
}

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    assert(hex_key("AB") == 1);
    assert(hex_key("1077E") == 2);
    assert(hex_key("ABED1A33") == 4);
    assert(hex_key("2020") == 2);
    assert(hex_key("123456789ABCDEF0") == 6);
    assert(hex_key("112233445566778899AABBCCDDEEFF00") == 12);
    assert(hex_key("") == 0);

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran code, use the following commands:

```sh
gfortran -o hex_key_test hex_key_test.f90
./hex_key_test
```

#### C++

To compile and run the C++ code, use the following commands:

```sh
g++ -o hex_key_test hex_key_test.cpp
./hex_key_test
```

Both programs should output "All tests passed successfully." if all assertions are correct. If any assertion fails, the programs will exit with an error message.
