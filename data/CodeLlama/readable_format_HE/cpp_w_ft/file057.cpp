Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

// Function declaration
int fruit_distribution(const std::string& s, int n);

int main() {
    std::string s;
    int n;

    // Test cases
    s = "5 apples and 6 oranges";
    n = 19;
    if (fruit_distribution(s, n) != 8) {
        std::cerr << "Test case 1 failed" << std::endl;
        std::exit(1);
    }

    s = "5 apples and 6 oranges";
    n = 21;
    if (fruit_distribution(s, n) != 10) {
        std::cerr << "Test case 2 failed" << std::endl;
        std::exit(1);
    }

    s = "0 apples and 1 oranges";
    n = 3;
    if (fruit_distribution(s, n) != 2) {
        std::cerr << "Test case 3 failed" << std::endl;
        std::exit(1);
    }

    s = "1 apples and 0 oranges";
    n = 3;
    if (fruit_distribution(s, n) != 2) {
        std::cerr << "Test case 4 failed" << std::endl;
        std::exit(1);
    }

    s = "2 apples and 3 oranges";
    n = 100;
    if (fruit_distribution(s, n) != 95) {
        std::cerr << "Test case 5 failed" << std::endl;
        std::exit(1);
    }

    s = "2 apples and 3 oranges";
    n = 5;
    if (fruit_distribution(s, n) != 0) {
        std::cerr << "Test case 6 failed" << std::endl;
        std::exit(1);
    }

    s = "1 apples and 100 oranges";
    n = 120;
    if (fruit_distribution(s, n) != 19) {
        std::cerr << "Test case 7 failed" << std::endl;
        std::exit(1);
    }

    std::cout << "All test cases passed" << std::endl;

    return 0;
}

int fruit_distribution(const std::string& s, int n) {
    std::string num1, num2;
    int is12 = 0;
    int num1_val = 0, num2_val = 0;

    for (size_t i = 0; i < s.length(); ++i) {
        if (isdigit(s[i])) {
            if (is12 == 0) {
                num1 += s[i];
            } else if (is12 == 1) {
                num2 += s[i];
            }
        } else if (is12 == 0 && !num1.empty()) {
            is12 = 1;
        }
    }

    if (!num1.empty()) {
        num1_val = std::stoi(num1);
    }
    if (!num2.empty()) {
        num2_val = std::stoi(num2);
    }

    return n - num1_val - num2_val;
}
```

This C++ code includes the `fruit_distribution` function, which is equivalent to the Fortran function `fruit_distribution`. The main function contains several test cases to verify the correctness of the `fruit_distribution` function. If any test case fails, it prints an error message and exits with a non-zero status. If all test cases pass, it prints "All test cases passed".
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `fruit_distribution` function in both languages.

### Fortran Unit Test Code

```fortran
program fruit_distribution_program
    implicit none
    character(len=100) :: s
    integer :: n

    ! Function declaration
    integer :: fruit_distribution

    ! Test cases
    s = "5 apples and 6 oranges"
    n = 19
    if (fruit_distribution(trim(s), n) /= 8) then
        write(*,*) "Test case 1 failed"
        call exit(1)
    end if

    s = "5 apples and 6 oranges"
    n = 21
    if (fruit_distribution(trim(s), n) /= 10) then
        write(*,*) "Test case 2 failed"
        call exit(1)
    end if

    s = "0 apples and 1 oranges"
    n = 3
    if (fruit_distribution(trim(s), n) /= 2) then
        write(*,*) "Test case 3 failed"
        call exit(1)
    end if

    s = "1 apples and 0 oranges"
    n = 3
    if (fruit_distribution(trim(s), n) /= 2) then
        write(*,*) "Test case 4 failed"
        call exit(1)
    end if

    s = "2 apples and 3 oranges"
    n = 100
    if (fruit_distribution(trim(s), n) /= 95) then
        write(*,*) "Test case 5 failed"
        call exit(1)
    end if

    s = "2 apples and 3 oranges"
    n = 5
    if (fruit_distribution(trim(s), n) /= 0) then
        write(*,*) "Test case 6 failed"
        call exit(1)
    end if

    s = "1 apples and 100 oranges"
    n = 120
    if (fruit_distribution(trim(s), n) /= 19) then
        write(*,*) "Test case 7 failed"
        call exit(1)
    end if

    write(*,*) "All test cases passed"
end program fruit_distribution_program

function fruit_distribution(s, n) result(res)
    implicit none
    character(len=*), intent(in) :: s
    integer, intent(in) :: n
    integer :: res
    character(len=100) :: num1, num2
    integer :: i, is12, num1_val, num2_val

    num1 = ""
    num2 = ""
    is12 = 0

    do i = 1, len(s)
        if (iachar(s(i:i)) >= 48 .and. iachar(s(i:i)) <= 57) then
            if (is12 == 0) then
                num1 = trim(num1) // s(i:i)
            else if (is12 == 1) then
                num2 = trim(num2) // s(i:i)
            end if
        else if (is12 == 0 .and. len(trim(num1)) > 0) then
            is12 = 1
        end if
    end do

    read(num1, *) num1_val
    read(num2, *) num2_val

    res = n - num1_val - num2_val
end function fruit_distribution
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

// Function declaration
int fruit_distribution(const std::string& s, int n);

int main() {
    std::string s;
    int n;

    // Test cases
    s = "5 apples and 6 oranges";
    n = 19;
    if (fruit_distribution(s, n) != 8) {
        std::cerr << "Test case 1 failed" << std::endl;
        std::exit(1);
    }

    s = "5 apples and 6 oranges";
    n = 21;
    if (f
