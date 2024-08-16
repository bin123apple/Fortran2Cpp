Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the same test cases and functionality as the original Fortran code.

```cpp
#include <iostream>
#include <vector>
#include <cstdlib> // For exit()

int add(const std::vector<int>& lst) {
    int sum = 0;
    for (size_t i = 0; i < lst.size() / 2; ++i) {
        if (lst[2 * i + 1] % 2 == 0) {
            sum += lst[2 * i + 1];
        }
    }
    return sum;
}

int main() {
    // Test cases
    if (add({4, 88}) != 88) {
        std::cerr << "Assertion failed: add({4, 88}) == 88" << std::endl;
        std::exit(1);
    }

    if (add({4, 5, 6, 7, 2, 122}) != 122) {
        std::cerr << "Assertion failed: add({4, 5, 6, 7, 2, 122}) == 122" << std::endl;
        std::exit(1);
    }

    if (add({4, 0, 6, 7}) != 0) {
        std::cerr << "Assertion failed: add({4, 0, 6, 7}) == 0" << std::endl;
        std::exit(1);
    }

    if (add({4, 4, 6, 8}) != 12) {
        std::cerr << "Assertion failed: add({4, 4, 6, 8}) == 12" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}
```

### Explanation:
1. **Function `add`**: This function takes a vector of integers as input and returns the sum of even-valued elements in the vector, considering the original Fortran code's logic.
2. **Main function**: This contains the test cases that verify the correctness of the `add` function. If any test case fails, it prints an error message and exits with a non-zero status.

### Notes:
- The original Fortran code uses 1-based indexing for arrays, while C++ uses 0-based indexing. Therefore, the translation adjusts the indexing accordingly.
- The `std::vector<int>` is used to represent the array of integers, and its size is dynamically managed, similar to how arrays are handled in Fortran.
- The `std::cerr` is used for error output, and `std::exit(1)` is used to exit the program with a failure status, similar to the `call exit(1)` in Fortran.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `add` function in both languages.

### Fortran Unit Test Code

```fortran
program test_add_function
    implicit none
    integer :: result

    ! Test cases
    result = add([4, 88])
    if (result /= 88) then
        write(*,*) "Test failed: add([4, 88]) == 88"
        call exit(1)
    end if

    result = add([4, 5, 6, 7, 2, 122])
    if (result /= 122) then
        write(*,*) "Test failed: add([4, 5, 6, 7, 2, 122]) == 122"
        call exit(1)
    end if

    result = add([4, 0, 6, 7])
    if (result /= 0) then
        write(*,*) "Test failed: add([4, 0, 6, 7]) == 0"
        call exit(1)
    end if

    result = add([4, 4, 6, 8])
    if (result /= 12) then
        write(*,*) "Test failed: add([4, 4, 6, 8]) == 12"
        call exit(1)
    end if

    write(*,*) "All tests passed successfully."

contains

    function add(lst) result(sum)
        integer, dimension(:), intent(in) :: lst
        integer :: sum
        integer :: i

        sum = 0
        do i = 0, (size(lst) - 1) / 2
            if (mod(lst(2 * i + 2), 2) == 0) then
                sum = sum + lst(2 * i + 2)
            end if
        end do
    end function add

end program test_add_function
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <cstdlib> // For exit()

int add(const std::vector<int>& lst) {
    int sum = 0;
    for (size_t i = 0; i < lst.size() / 2; ++i) {
        if (lst[2 * i + 1] % 2 == 0) {
            sum += lst[2 * i + 1];
        }
    }
    return sum;
}

int main() {
    // Test cases
    if (add({4, 88}) != 88) {
        std::cerr << "Test failed: add({4, 88}) == 88" << std::endl;
        std::exit(1);
    }

    if (add({4, 5, 6, 7, 2, 122}) != 122) {
        std::cerr << "Test failed: add({4, 5, 6, 7, 2, 122}) == 122" << std::endl;
        std::exit(1);
    }

    if (add({4, 0, 6, 7}) != 0) {
        std::cerr << "Test failed: add({4, 0, 6, 7}) == 0" << std::endl;
        std::exit(1);
    }

    if (add({4, 4, 6, 8}) != 12) {
        std::cerr << "Test failed: add({4, 4, 6, 8}) == 12" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}
```

### Explanation:
- **Fortran Unit Test Code**: This program defines a `test_add_function` program that includes the `add` function and several test cases to verify its correctness. If any test fails, it prints an error message and exits with a non-zero status.
- **C++ Unit Test Code**: This program defines a `main` function that includes the `add` function and several test cases to verify its correctness. If any test fails, it prints an error message and exits with a non-zero status.

### Compilation and Execution:
- **Fortran**: You can compile the Fortran code using a Fortran compiler like `gfortran`:
  ```sh
  gfortran -o test_add_function test_add_function.f90
  ./test_add_function
  ```
- **C++**: You can compile the C++ code using a C++ compiler like `g++`:
  ```sh
  g++ -o test_add_function test_add_function.cpp
  ./test_add_function
  ```

These unit tests will help ensure that the `add` function behaves as expected in both the Fortran and C++ implementations.
