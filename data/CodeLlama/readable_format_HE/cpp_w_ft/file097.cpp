Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <vector>

namespace utils {
    int add_elements(const std::vector<int>& arr, int k) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            if (arr[i] >= -99 && arr[i] <= 99) {
                sum += arr[i];
            }
        }
        return sum;
    }
}

int main() {
    // Test cases
    if (utils::add_elements({1, -2, -3, 41, 57, 76, 87, 88, 99}, 3) != -4) {
        std::cerr << "Assertion failed: result /= -4" << std::endl;
        return 1;
    }

    if (utils::add_elements({111, 121, 3, 4000, 5, 6}, 2) != 0) {
        std::cerr << "Assertion failed: result /= 0" << std::endl;
        return 1;
    }

    if (utils::add_elements({11, 21, 3, 90, 5, 6, 7, 8, 9}, 4) != 125) {
        std::cerr << "Assertion failed: result /= 125" << std::endl;
        return 1;
    }

    if (utils::add_elements({111, 21, 3, 4000, 5, 6, 7, 8, 9}, 4) != 24) {
        std::cerr << "Assertion failed: result /= 24" << std::endl;
        return 1;
    }

    if (utils::add_elements({1}, 1) != 1) {
        std::cerr << "Assertion failed: result /= 1" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
```

### Explanation:
1. **Namespace `utils`**: This is used to encapsulate the `add_elements` function, similar to how the Fortran module encapsulates the function.
2. **Function `add_elements`**: This function takes a vector of integers and an integer `k` as input parameters. It iterates through the first `k` elements of the vector and adds them to the sum if they are between -99 and 99 (inclusive).
3. **Main function**: This contains the test cases that call the `add_elements` function with different inputs and checks if the result matches the expected output. If any test case fails, it prints an error message and returns 1.

This C++ code should behave similarly to the provided Fortran code and pass all the test cases.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
module utils
    implicit none
contains
    function add_elements(arr, k) result(sum)
        implicit none
        integer, intent(in) :: arr(:)
        integer, intent(in) :: k
        integer :: sum
        integer :: i

        sum = 0
        do i = 1, k
            if (arr(i) >= -99 .and. arr(i) <= 99) then
                sum = sum + arr(i)
            end if
        end do
    end function add_elements
end module utils

program main
    use utils
    implicit none
    integer :: result

    ! Test cases
    result = add_elements([1, -2, -3, 41, 57, 76, 87, 88, 99], 3)
    if (result /= -4) then
        write(*,*) "Assertion failed: result /= -4"
        call exit(1)
    end if

    result = add_elements([111, 121, 3, 4000, 5, 6], 2)
    if (result /= 0) then
        write(*,*) "Assertion failed: result /= 0"
        call exit(1)
    end if

    result = add_elements([11, 21, 3, 90, 5, 6, 7, 8, 9], 4)
    if (result /= 125) then
        write(*,*) "Assertion failed: result /= 125"
        call exit(1)
    end if

    result = add_elements([111, 21, 3, 4000, 5, 6, 7, 8, 9], 4)
    if (result /= 24) then
        write(*,*) "Assertion failed: result /= 24"
        call exit(1)
    end if

    result = add_elements([1], 1)
    if (result /= 1) then
        write(*,*) "Assertion failed: result /= 1"
        call exit(1)
    end if

    write(*,*) "All tests passed."
end program main
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>

namespace utils {
    int add_elements(const std::vector<int>& arr, int k) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            if (arr[i] >= -99 && arr[i] <= 99) {
                sum += arr[i];
            }
        }
        return sum;
    }
}

int main() {
    // Test cases
    if (utils::add_elements({1, -2, -3, 41, 57, 76, 87, 88, 99}, 3) != -4) {
        std::cerr << "Assertion failed: result /= -4" << std::endl;
        return 1;
    }

    if (utils::add_elements({111, 121, 3, 4000, 5, 6}, 2) != 0) {
        std::cerr << "Assertion failed: result /= 0" << std::endl;
        return 1;
    }

    if (utils::add_elements({11, 21, 3, 90, 5, 6, 7, 8, 9}, 4) != 125) {
        std::cerr << "Assertion failed: result /= 125" << std::endl;
        return 1;
    }

    if (utils::add_elements({111, 21, 3, 4000, 5, 6, 7, 8, 9}, 4) != 24) {
        std::cerr << "Assertion failed: result /= 24" << std::endl;
        return 1;
    }

    if (utils::add_elements({1}, 1) != 1) {
        std::cerr << "Assertion failed: result /= 1" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**: This code defines a module `utils` containing the `add_elements` function and a main program that tests this function with various inputs. It prints "All tests passed." if all assertions are successful.

2. **C++ Unit Test Code**: This code defines a namespace `utils` containing the `add_elements` function and a main function that tests this function with the same set of inputs as the Fortran code. It prints "All tests passed." if all assertions are successful.

To run these tests, you can compile and execute the Fortran code using a Fortran compiler (e.g., `gfortran`) and the C++ code using a C++ compiler (e
