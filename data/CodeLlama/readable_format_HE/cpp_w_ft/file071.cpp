Certainly! Below is the equivalent C++ code for the provided Fortran program:

```cpp
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

bool is_prime_length(const std::string& s) {
    int l = s.length();
    if (l < 2) {
        return false;
    }

    for (int i = 2; i <= static_cast<int>(std::sqrt(l)); ++i) {
        if (l % i == 0) {
            return false;
        }
    }

    return true;
}

void run_tests() {
    struct Test {
        std::string str;
        bool expected;
    };

    Test tests[] = {
        {"Hello", true},
        {"abcdcba", true},
        {"kittens", true},
        {"orange", false},
        {"wow", true},
        {"world", true},
        {"MadaM", true},
        {"Wow", true},
        {"", false},
        {"HI", true},
        {"go", true},
        {"gogo", false},
        {"aaaaaaaaaaaaaaa", false},
        {"Madam", true},
        {"M", false},
        {"0", false}
    };

    bool all_tests_passed = true;
    for (const auto& test : tests) {
        bool result = is_prime_length(test.str);
        if (result != test.expected) {
            std::cerr << "is_prime_length('" << test.str << "') == "
                      << std::boolalpha << test.expected << ": assertion failed" << std::endl;
            all_tests_passed = false;
        }
    }

    if (all_tests_passed) {
        std::cout << "All tests passed successfully." << std::endl;
    }
}

int main() {
    run_tests();
    return 0;
}
```

### Explanation:
1. **Function `is_prime_length`**:
   - This function checks if the length of the given string `s` is a prime number.
   - It uses a loop to check if the length of the string is divisible by any number between 2 and the square root of the length.

2. **Function `run_tests`**:
   - This function contains an array of test cases where each test case is a pair of a string and a boolean value indicating whether the string's length is a prime number.
   - It iterates through the array, calls `is_prime_length` with each string, and checks if the result matches the expected outcome.
   - If all tests pass, it prints "All tests passed successfully."

3. **Main Function**:
   - Calls the `run_tests` function to execute the tests.

This C++ code should behave similarly to the provided Fortran code. The tests have been adapted to use a struct array for test cases and to use `std::boolalpha` for printing boolean values as true/false instead of 1/0.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program prime_length_check
  implicit none

  call run_tests()

contains

  logical function is_prime_length(s)
    character(len=*), intent(in) :: s
    integer :: l, i

    l = len_trim(s)
    if (l < 2) then
      is_prime_length = .false.
      return
    end if

    do i = 2, int(sqrt(real(l)))
      if (mod(l, i) == 0) then
        is_prime_length = .false.
        return
      end if
    end do

    is_prime_length = .true.
  end function is_prime_length

  subroutine run_tests()
    character(len=:), allocatable :: str
    logical :: result

    str = "Hello"
    result = is_prime_length(str)
    if (.not. result) then
      write(*,*) "is_prime_length('Hello') == true: assertion failed"
      call exit(1)
    end if

    str = "abcdcba"
    result = is_prime_length(str)
    if (.not. result) then
      write(*,*) "is_prime_length('abcdcba') == true: assertion failed"
      call exit(1)
    end if

    str = "kittens"
    result = is_prime_length(str)
    if (.not. result) then
      write(*,*) "is_prime_length('kittens') == true: assertion failed"
      call exit(1)
    end if

    str = "orange"
    result = is_prime_length(str)
    if (result) then
      write(*,*) "is_prime_length('orange') == false: assertion failed"
      call exit(1)
    end if

    str = "wow"
    result = is_prime_length(str)
    if (.not. result) then
      write(*,*) "is_prime_length('wow') == true: assertion failed"
      call exit(1)
    end if

    str = "world"
    result = is_prime_length(str)
    if (.not. result) then
      write(*,*) "is_prime_length('world') == true: assertion failed"
      call exit(1)
    end if

    str = "MadaM"
    result = is_prime_length(str)
    if (.not. result) then
      write(*,*) "is_prime_length('MadaM') == true: assertion failed"
      call exit(1)
    end if

    str = "Wow"
    result = is_prime_length(str)
    if (.not. result) then
      write(*,*) "is_prime_length('Wow') == true: assertion failed"
      call exit(1)
    end if

    str = ""
    result = is_prime_length(str)
    if (result) then
      write(*,*) "is_prime_length('') == false: assertion failed"
      call exit(1)
    end if

    str = "HI"
    result = is_prime_length(str)
    if (.not. result) then
      write(*,*) "is_prime_length('HI') == true: assertion failed"
      call exit(1)
    end if

    str = "go"
    result = is_prime_length(str)
    if (.not. result) then
      write(*,*) "is_prime_length('go') == true: assertion failed"
      call exit(1)
    end if

    str = "gogo"
    result = is_prime_length(str)
    if (result) then
      write(*,*) "is_prime_length('gogo') == false: assertion failed"
      call exit(1)
    end if

    str = "aaaaaaaaaaaaaaa"
    result = is_prime_length(str)
    if (result) then
      write(*,*) "is_prime_length('aaaaaaaaaaaaaaa') == false: assertion failed"
      call exit(1)
    end if

    str = "Madam"
    result = is_prime_length(str)
    if (.not. result) then
      write(*,*) "is_prime_length('Madam') == true: assertion failed"
      call exit(1)
    end if

    str = "M"
    result = is_prime_length(str)
    if (result) then
      write(*,*) "is_prime_length('M') == false: assertion failed"
      call exit(1)
    end if

    str = "0"
    result = is_prime_length(str)
    if (result) then
      write(*,*) "is_prime_length('0') == false: assertion failed"
      call exit(1)
    end if

    write(*,*) "All tests passed successfully."
  end subroutine run_tests

end program prime_length_check
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <cmath>
#include <string
