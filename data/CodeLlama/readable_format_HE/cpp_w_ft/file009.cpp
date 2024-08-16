Translating the provided Fortran code to C++ involves a few steps, including adapting the Fortran module and program structure to a C++ class and main function. Here's how you can translate the Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class StringUtils {
public:
    static std::string longest(const std::vector<std::string>& strings) {
        if (strings.empty()) return "";
        std::string longestStr = strings[0];
        for (size_t i = 1; i < strings.size(); ++i) {
            longestStr = (longestStr.size() > strings[i].size()) ? longestStr : strings[i];
        }
        return longestStr;
    }
};

int main() {
    // Test case 1: Empty array
    std::vector<std::string> strings1 = {};
    std::string result1 = StringUtils::longest(strings1);
    if (!result1.empty()) {
        std::cerr << "Test case 1 failed: assertion failed" << std::endl;
        return 1;
    }

    // Test case 2: Array with single character strings
    std::vector<std::string> strings2 = {"x", "y", "z"};
    std::string result2 = StringUtils::longest(strings2);
    if (result2 != "x") {
        std::cerr << "Test case 2 failed: assertion failed" << std::endl;
        return 1;
    }

    // Test case 3: Array with varying length strings
    std::vector<std::string> strings3 = {"x       ", "yyy     ", "zzzz    ", "www     ", "kkkk    ", "abc     "};
    std::string result3 = StringUtils::longest(strings3);
    if (result3 != "zzzz    ") {
        std::cerr << "Test case 3 failed: assertion failed" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;
    return 0;
}
```

### Explanation:

1. **Class Definition**: The Fortran module `string_utils` is translated to a C++ class `StringUtils`. The `longest` function is made static and public so it can be called without instantiating the class.

2. **Function Implementation**: The Fortran function `longest` is translated into a C++ function. It takes a vector of strings as input and returns the longest string.

3. **Main Function**: The `main` function in C++ serves as the entry point for the program. It includes test cases similar to the Fortran program.

4. **Test Cases**: The test cases are implemented using vectors of strings and checking the results against expected outcomes. If a test case fails, an error message is printed, and the program exits with a non-zero status.

This C++ code should behave similarly to the original Fortran code, providing the same functionality and passing the same test cases.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `longest` function in both implementations.

### Fortran Unit Test Code

```fortran
module string_utils
    implicit none
    contains

    function longest(strings) result(out)
        implicit none
        character(len=*), dimension(:), intent(in) :: strings
        character(len=:), allocatable :: out
        integer :: i

        out = ""
        do i = 1, size(strings)
            if (len_trim(strings(i)) > len_trim(out)) then
                out = strings(i)
            end if
        end do
    end function longest

end module string_utils

program main
    use string_utils
    implicit none
    character(len=:), allocatable :: result
    character(len=10), dimension(:), allocatable :: strings

    ! Test case 1: Empty array
    if (allocated(strings)) deallocate(strings)
    allocate(strings(0))
    result = longest(strings)
    if (result /= "") then
        write(*,*) "Test case 1 failed: assertion failed"
        call exit(1)
    end if

    ! Test case 2: Array with single character strings
    if (allocated(strings)) deallocate(strings)
    allocate(strings(3))
    strings = ["x", "y", "z"]
    result = longest(strings)
    if (result /= "x") then
        write(*,*) "Test case 2 failed: assertion failed"
        call exit(1)
    end if

    ! Test case 3: Array with varying length strings
    if (allocated(strings)) deallocate(strings)
    allocate(strings(6))
    strings = ["x       ", "yyy     ", "zzzz    ", "www     ", "kkkk    ", "abc     "]
    result = longest(strings)
    if (result /= "zzzz    ") then
        write(*,*) "Test case 3 failed: assertion failed"
        call exit(1)
    end if

    write(*,*) "All test cases passed"
end program main
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class StringUtils {
public:
    static std::string longest(const std::vector<std::string>& strings) {
        if (strings.empty()) return "";
        std::string longestStr = strings[0];
        for (size_t i = 1; i < strings.size(); ++i) {
            longestStr = (longestStr.size() > strings[i].size()) ? longestStr : strings[i];
        }
        return longestStr;
    }
};

int main() {
    // Test case 1: Empty array
    std::vector<std::string> strings1 = {};
    std::string result1 = StringUtils::longest(strings1);
    if (!result1.empty()) {
        std::cerr << "Test case 1 failed: assertion failed" << std::endl;
        return 1;
    }

    // Test case 2: Array with single character strings
    std::vector<std::string> strings2 = {"x", "y", "z"};
    std::string result2 = StringUtils::longest(strings2);
    if (result2 != "x") {
        std::cerr << "Test case 2 failed: assertion failed" << std::endl;
        return 1;
    }

    // Test case 3: Array with varying length strings
    std::vector<std::string> strings3 = {"x       ", "yyy     ", "zzzz    ", "www     ", "kkkk    ", "abc     "};
    std::string result3 = StringUtils::longest(strings3);
    if (result3 != "zzzz    ") {
        std::cerr << "Test case 3 failed: assertion failed" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;
    return 0;
}
```

### Explanation:

1. **Fortran Unit Test**:
   - The Fortran program includes a module `string_utils` with the `longest` function and a main program that tests this function with different inputs.
   - The test cases include checking for an empty array, an array with single character strings, and an array with strings of varying lengths.

2. **C++ Unit Test**:
   - The C++ code defines a `StringUtils` class with a static `longest` function and a `main` function that tests this function with the same set of test cases as the Fortran version.
   - The test cases are designed to ensure that the `longest` function behaves correctly in both C++ and Fortran.

To compile and run these tests:

- For Fortran, use a Fortran compiler like `gfortran`:
  ```sh
  gfortran -o test_fortran test_fortran.f90
  ./test_fortran
  ```
- For C++, use a C++ compiler like `g++`:
  ```sh
  g++ -o test_cpp test_cpp.cpp
  ./test_cpp
  ```

These tests should confirm that the `longest
