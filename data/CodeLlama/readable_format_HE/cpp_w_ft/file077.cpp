Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

int is_bored(const std::string& S) {
    int sum = 0;
    bool isstart = true;
    bool isi = false;
    int lenS = S.length();

    for (int i = 0; i < lenS; ++i) {
        if (S[i] == ' ' && isi) {
            isi = false;
            sum++;
        }
        if (S[i] == 'I' && isstart) {
            isi = true;
        } else {
            isi = false;
        }
        if (S[i] != ' ') {
            isstart = false;
        }
        if (S[i] == '.' || S[i] == '?' || S[i] == '!') {
            isstart = true;
        }
    }
    return sum;
}

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    assert(is_bored("Hello world") == 0);
    assert(is_bored("Is the sky blue?") == 0);
    assert(is_bored("I love It !") == 1);
    assert(is_bored("bIt") == 0);
    assert(is_bored("I feel good today. I will be productive. will kill It") == 2);
    assert(is_bored("You and I are going for a walk") == 0);

    return 0;
}
```

### Explanation:
1. **Function `is_bored`**: This function takes a `std::string` as input and returns an integer. It calculates the number of times the word "I" is followed by a space in the given string.
2. **Variable `sum`**: This variable is used to count the number of times the word "I" is followed by a space.
3. **Variables `isstart`, `isi`, `lenS`**: These variables are used to keep track of the state of the string and the position of the character being processed.
4. **Loop**: The loop iterates through each character of the input string. It checks for the conditions to increment the `sum` variable.
5. **`assert` function**: This function checks if the condition is `false` and prints an error message if so. If the condition is `false`, the program exits with a status code of `1`.
6. **Main function**: The `main` function contains the test cases that call the `assert` function with the results of the `is_bored` function.

This C++ code should behave the same way as the provided Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program is_bored_program
    implicit none
    character(len=100) :: S
    integer :: result

    ! Test cases
    call assert(is_bored("Hello world") == 0)
    call assert(is_bored("Is the sky blue?") == 0)
    call assert(is_bored("I love It !") == 1)
    call assert(is_bored("bIt") == 0)
    call assert(is_bored("I feel good today. I will be productive. will kill It") == 2)
    call assert(is_bored("You and I are going for a walk") == 0)

contains

    function is_bored(S) result(sum)
        implicit none
        character(len=*), intent(in) :: S
        integer :: sum
        logical :: isstart, isi
        integer :: i, lenS

        isstart = .true.
        isi = .false.
        sum = 0
        lenS = len_trim(S)

        do i = 1, lenS
            if (S(i:i) == ' ' .and. isi) then
                isi = .false.
                sum = sum + 1
            end if
            if (S(i:i) == 'I' .and. isstart) then
                isi = .true.
            else
                isi = .false.
            end if
            if (S(i:i) /= ' ') then
                isstart = .false.
            end if
            if (S(i:i) == '.' .or. S(i:i) == '?' .or. S(i:i) == '!') then
                isstart = .true.
            end if
        end do
    end function is_bored

    subroutine assert(condition)
        logical, intent(in) :: condition
        if (.not. condition) then
            write(*,*) "Assertion failed"
            call exit(1)
        end if
    end subroutine assert

end program is_bored_program
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

int is_bored(const std::string& S) {
    int sum = 0;
    bool isstart = true;
    bool isi = false;
    int lenS = S.length();

    for (int i = 0; i < lenS; ++i) {
        if (S[i] == ' ' && isi) {
            isi = false;
            sum++;
        }
        if (S[i] == 'I' && isstart) {
            isi = true;
        } else {
            isi = false;
        }
        if (S[i] != ' ') {
            isstart = false;
        }
        if (S[i] == '.' || S[i] == '?' || S[i] == '!') {
            isstart = true;
        }
    }
    return sum;
}

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    assert(is_bored("Hello world") == 0);
    assert(is_bored("Is the sky blue?") == 0);
    assert(is_bored("I love It !") == 1);
    assert(is_bored("bIt") == 0);
    assert(is_bored("I feel good today. I will be productive. will kill It") == 2);
    assert(is_bored("You and I are going for a walk") == 0);

    return 0;
}
```

### Explanation:
1. **Fortran Unit Test Code**: This code includes the `is_bored` function and a `assert` subroutine to check the correctness of the function. It contains test cases that call the `assert` subroutine with the results of the `is_bored` function.
2. **C++ Unit Test Code**: This code includes the `is_bored` function and a `assert` function to check the correctness of the function. It contains test cases that call the `assert` function with the results of the `is_bored` function.

To compile and run the Fortran code, you can use a Fortran compiler like `gfortran`:
```sh
gfortran -o is_bored_test is_bored_program.f90
./is_bored_test
```

To compile and run the C++ code, you can use a C++ compiler like `g++`:
```sh
g++ -o is_bored_test is_bored_program.cpp
./is_bored_test
```

These unit tests will verify that the translation from Fortran to C++ is correct by ensuring that both implementations produce the same results for the given test cases.
